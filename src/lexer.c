/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:46:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/20 20:49:42 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	makefile(void)
{
	execve("/usr/bin/make", (char *[]){"make", "re", NULL}, (char *[]){NULL});
}

t_cmd	*lexer(char *input, t_cmd	*cmd, char **envp)
{
	int		i;

	if (strlen(input) == 0)
		return (0);
	if (strncmp(input, "make", 4) == 0)
		makefile();
	cmd->spl_input = ft_split(input, ' ');
	i = 0;
	identify(cmd->spl_input, cmd, envp);
	return (cmd);
}

void	identify(char **input, t_cmd *cmd, char **envp)
{
	int	i;
	int	is_rec;

	i = 0;
	is_rec = 0;
	while (input[i])
	{
		if (i == 0)
		{
			cmd->cmd = input[i];
			// printf("\t%s is the main command\n", cmd->cmd);
		}
		else if (i == 1 && input[i][0] == '-')
		{
			cmd->flag = input[i];
			// printf("\t%s is a flag\n", cmd->flag);
		}
		else if (input[i][0] == '$')
			expand(input[i], cmd, envp);
		else if (input[i][0] == '|')
		{
			printf("\tPIPE HAS BEEN HIT!\n");
			if (input[i + 1][0])
			{
				//WHAT ABOUT OUTPUT?
				//printf("\tCATALISYS OF NEW PROGRAM\n");
				is_rec = 1;
				break ;
			}
		}
		else
		{
			cmd->args = input[i];
			printf("\t%s is an argument\n", cmd->args);
		}
		i++;
	}
	if (is_builtin(cmd, envp) == 1)
	{
		cmd->is_builtin = 1;
		printf("\tand is a builtin!\n");
	}
	if (is_rec == 1)
		identify(input + i + 1, cmd, envp);
}

int	expand(char *str, t_cmd *cmd, char **envp)
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
		while (envp[j])
		{
			if ((ft_strncmp(envp[j], str + 1, ft_strlen(str + 1))) == 0)
			{
				if (envp[j][ft_strlen(str + 1)] == '=')
				{
					while (envp[j][k] != '=')
						k++;
					cmd->expansion = &envp[j][k + 1];
					break ;
				}
			}
			cmd->expansion = " \n";
			j++;
		}
		i++;
	}
	printf("%s", cmd->expansion);
	return (1);
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
