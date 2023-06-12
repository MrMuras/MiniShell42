/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:46:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/11 22:34:04 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int ac, char **av, char **envp)
{
	if (ac == 2)
		lexer(av[1]);
	else
		identify(av + 1);
	return (0);
}

int	lexer(char *input)
{
	char	**ret;

	if (strlen(input) == 0)
		return (0);
	ret = ft_split(input, ' ');
	identify(ret);
	return (1);
}

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
			cmd->envp = strdup(envp);
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
			cmd->argnum++;
			printf("\t%d\n", cmd->argnum);
			printf("%s is an argument\n", cmd->args[0]);
		}
		i++;
	}
	// parsing(cmd);
	return (0);
}
