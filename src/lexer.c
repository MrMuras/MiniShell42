/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:46:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/12 18:04:46 by snocita          ###   ########.fr       */
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

int	lexer(char *input)
{
	char	**ret;

	if (strlen(input) == 0)
		return (0);
	if (strncmp(input, "exit", 4) == 0)
		exit(0);
	ret = ft_split(input, ' ');
	identify(ret);
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

int	cmd_validation(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] == ' ')
		i++;
	char *env = getenv("PATH");
	char **splitted_env = ft_split(env, ':');
	while (splitted_env[j])
	{
		char *temp1 = ft_strjoin(splitted_env[j], "/");
		char *temp2 = ft_strjoin(temp1, input+i);
		free(temp1);
		if (access(temp2, X_OK) == 0)
		{
			free(temp2);
			return (1);
		}
		free(temp2);
		j++;
	}
	return (0);
}

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

int	identify(char **input)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
	if (!cmd)
		return (0);
	while (input[i])
	{
		if (i == 0)
		{
			cmd->cmd = input[i];
			printf("%s is the main command\n", cmd->cmd);
		}
		else if (i == 1 && input[i][0] == '-')
		{
			cmd->flag = input[i];
			printf("%s is a flag\n", cmd->flag);
		}
		else
		{
			cmd->args = &input[i];
			printf("%s is an argument\n", cmd->args[0]);
		}
		i++;
	}
	// parsing(cmd);
	return (0);
}
