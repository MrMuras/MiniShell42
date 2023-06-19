/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 21:15:12 by amurawsk         ###   ########.fr       */
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
	free_double_arr(cmd->myenvp);
	free(cmd);
}

int	main(int ac, char **av, char **envp)
{
	t_cmd	*cmd;
	t_cmd	*temp;

	(void)ac;
	(void)av;
	cmd = malloc_struct();
	cmd->myenvp = ft_double_strdup(envp);
	using_history();
	while (cmd->exit != 1)
	{
		init_struct(cmd);
		cmd->input = readline("Minishelly$ ");
		if (strlen(cmd->input) > 0)
			add_history(cmd->input);
		temp = lexer(cmd->input, cmd);
		if (cmd->is_builtin == 0)
			execution(cmd);
		free(cmd->input);
	}
	free_all(cmd);
	return (0);
}
