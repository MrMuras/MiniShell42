/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/20 20:21:58 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_cmd	*malloc_struct(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (0);
	cmd->exit = 0;
	return (cmd);
}

void	free_all(t_cmd	*cmd)
{
	free(cmd);
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
