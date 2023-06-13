/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:46:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/13 18:56:45 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

// int	prelexer(int ac, char **av)
// {
// 	if (ac == 2)
// 		lexer(av[1]);
// 	else
// 		identify(av + 1);
// 	return (0);
// }

int	lexer(char *input, char **envp)
{
	char	**ret;
	t_cmd	*cmd;
	int		i;
	int		index;

	index = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
	if (!cmd)
		return (0);
	cmd->myenvp = ft_double_strdup(envp);
	if (strlen(input) == 0)
		return (0);
	if (strncmp(input, "exit", 4) == 0)
		exit(0);
	ret = ft_split(input, ' ');
	i = 0;
	while (ret[i])
		identify(ret, cmd, index);
	return (1);
}

int	expand(char *str, t_cmd *cmd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (0);
		else if (str[i] >= 'a' && str[i] <= 'z')
			return (0);
		str = &str[i];
		while (cmd->myenvp[j])
		{
			if ((ft_strncmp(cmd->myenvp[j], str, 100)) == 0)
			{
				printf("FOUND EXPANSION");
				cmd->expansion = cmd->myenvp;
				break ;
			}
			j++;
		}
	}
	return (1);
}

int	identify(char **input, t_cmd *cmd, int index)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (i == 0)
		{
			cmd->cmd[index] = input[i];
			printf("%s is the main command\n", cmd->cmd[index]);
		}
		else if (i == 1 && input[i][0] == '-')
		{
			cmd->flag = input[i];
			printf("%s is a flag\n", cmd->flag);
		}
		else if (input[i][0] == '$')
			expand(input[i], cmd);
		else if (input[i][0] == '|')
		{
			printf("PIPE HAS BEEN HIT!\n");
			if (input[i + 2])
				identify(&input[i + 2], cmd, index++);
		}
		else
		{
			cmd->args = malloc(sizeof(char *) * 2);
			cmd->args[0] = strdup(input[i]);
			cmd->args[1] = NULL;
			printf("%s is an argument\n", cmd->args[0]);
		}
		i++;
	}
	parsing(cmd, index);
	return (0);
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
