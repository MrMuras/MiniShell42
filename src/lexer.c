/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:46:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/14 18:18:58 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	lexer(char *input, char **envp, t_cmd	*cmd)
{
	char	**ret;
	int		i;
	int		index;

	index = 0;
	cmd->myenvp = ft_double_strdup(envp);
	if (strlen(input) == 0)
		return (0);
	if (strncmp(input, "exit", 4) == 0)
		exit(0);
	ret = ft_split(input, ' ');
	i = 0;
	identify(ret, cmd);
	return (1);
}

int	expand(char *str, t_cmd *cmd)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			return (0);
		while (cmd->myenvp[j])
		{
			if ((ft_strncmp(cmd->myenvp[j], str + 1, ft_strlen(str + 1))) == 0)
			{
				while (cmd->myenvp[j][k] != '=')
					k++;
				cmd->expansion = &cmd->myenvp[j][k + 1];
				break ;
			}
			cmd->expansion = " \n";
			j++;
		}
		i++;
	}
	return (1);
}

void	identify(char **input, t_cmd *cmd)
{
	int	i;
	int	j;
	int	is_rec;

	j = 0;
	i = 0;
	is_rec = 0;
	while (input[i])
	{
		if (i == 0)
		{
			cmd->cmd = input[i];
			parsing(cmd, e_builtins);
			//printf("\t%s is the main command\n", cmd->cmd);
		}
		else if (i == 1 && input[i][0] == '-')
		{
			cmd->flag = input[i];
			//printf("\t%s is a flag\n", cmd->flag);
		}
		else if (input[i][0] == '$')
		{
			//printf("DOLLAR SIGN FOUND\n");
			if (expand(input[i], cmd) == 1)
				printf("The expansion found is equal to: %s\n", cmd->expansion);
		}
		else if (input[i][0] == '|')
		{
			//printf("\tPIPE HAS BEEN HIT!\n");
			if (input[i + 1][j])
			{
				//WHAT ABOUT OUTPUT?
				//printf("\tCATALISYS OF NEW PROGRAM\n");
				is_rec = 1;
				break ;
			}
		}
		else
		{
			cmd->args = malloc(sizeof(char *) * 2);
			cmd->args = strdup(input[i]);
			//printf("\t%s is an argument\n", cmd->args);
		}
		i++;
	}
	if (is_rec == 1)
		identify(input + i + 1, cmd);
}

//CMD VALIDATION IS WAS IMPLEMENTED HERE, BUT WILL ULTIMATELY BE INSIDE THE PARSING, NOT LEXING!!!!!!!!
// int	identify(char **input)
// {
// 	int		i;
// 	t_cmd	*cmd;

// 	i = 0;
// 	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
// 	if (!cmd)
// 		return (0);
// 	while (input[i])
// 	{
// 		if (i == 0)
// 			cmd->cmd = input[i];
// 		else if (i == 1 && input[i][0] == '-')
// 			cmd->flag = input[i];
// 		else
// 		{
// 			cmd->args = &input[i];
// 			cmd->argnum++;
// 		}
// 		i++;
// 	}
// 	parsing(cmd);
// 	return (0);
// }

// FOR DEBUGGING!
// int	identify(char **input)
// {
// 	int		i;
// 	t_cmd	*cmd;

// 	i = 0;
// 	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
// 	if (!cmd)
// 		return (0);
// 	while (input[i])
// 	{
// 		if (i == 0)
// 		{
// 		// 	cmd->envp = strdup(envp);
// 			if (cmd_validation(input[i]) == 1)
// 			{
// 				cmd->cmd = input[i];
// 				printf("%s is the main command\n", cmd->cmd);
// 			}
// 		}
// 		else if (i == 1 && input[i][0] == '-')
// 		{
// 			cmd->flag = input[i];
// 			printf("%s is a flag\n", cmd->flag);
// 		}
// 		else
// 		{
// 			cmd->args = &input[i];
// 			printf("%s is an argument\n", cmd->args[0]);
// 		}
// 		i++;
// 	}
// 	// parsing(cmd);
// 	return (0);
// }

// int	identify(char **input, t_cmd *cmd)
// {
// 	int		i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (i == 0)
// 		{
// 			cmd->cmd = input[i];
// 			printf("%s is the main command\n", cmd->cmd);
// 		}
// 		else if (i == 1 && input[i][0] == '-')
// 		{
// 			if (input[i][0] == '-')
// 			{
// 				cmd->flag = input[i];
// 				printf("%s is a flag\n", cmd->flag);
// 			}
// 		}
// 		else if (input[i][0] == '$')
// 			expand(cmd);
// 		else
// 		{
// 			cmd->args = &input[i];
// 			printf("%s is an argument\n", cmd->args[0]);
// 		}
// 		i++;
// 	}
// 	parsing(cmd);
// 	return (0);
// }
