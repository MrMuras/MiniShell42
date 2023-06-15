/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/15 17:35:28 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_cmd	*init_structs(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->expansion = NULL;
	cmd->is_builtin = 0;
	if (!cmd)
		return (0);
	return (cmd);
}

int	main(int ac, char **av, char **envp)
{
//BRANCHNAME->builtins
	char	*input;
	t_cmd	*cmd;

	(void)ac;
	(void)av;
	(void)envp;

	using_history();
	cmd = init_structs();
	while (1)
	{
		input = readline("Minishelly$ ");
		add_history(input);
		if (lexer(input, envp, cmd) == 1)
			execution(input, cmd);
	}
	return (0);
}
