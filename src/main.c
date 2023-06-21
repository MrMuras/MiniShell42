/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/21 18:25:10 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_cmd	*malloc_struct(void)
{
	t_cmd	*cmd;
	int		i;
	int		j;

	i = 0;
	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		exit(1);
	cmd->args = malloc(100 * sizeof(char *));
	if (!cmd->args)
	{
		free(cmd);
		exit(1);
	}
	while (i < 100)
	{
		cmd->args[i] = malloc(100 * sizeof(char));
		if (!cmd->args[i])
		{
			j = 0;
			while (j < i)
			{
				free(cmd->args[j]);
				j++;
			}
			free(cmd->args);
			free(cmd);
			exit(1);
		}
		i++;
	}
	cmd->args[100] = NULL;
	cmd->exit = 0;

	free(cmd->args);
	return (cmd);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd;
	t_cmd	*temp;

	(void)ac;
	(void)av;
	cmd = malloc_struct();
	using_history();
	while (cmd->exit != 1)
	{
		init_struct(cmd);
		cmd->input = readline("Minishelly$ ");
		if (strlen(cmd->input) > 0)
			add_history(cmd->input);
		temp = lexer(cmd->input, cmd, envp);
		if (cmd->is_builtin == 0)
			execution(cmd);
		free(cmd->input);
	}
	free_all(cmd);
	return (0);
}
