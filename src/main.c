/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/15 23:02:22 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_cmd	*init_structs(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd *));
	if (!cmd)
		return (0);
	return (cmd);
}

int	main(int ac, char **av, char **envp)
{
	char	*input;
	t_cmd	*cmd;

	(void)ac;
	(void)av;
	(void)envp;

	cmd = init_structs();
	using_history();
	while (1)
	{
		input = readline("Minishelly$ ");
		if (strlen(input) > 0)
			add_history(input);
		if (lexer(input, envp, cmd) == 1)
			execution(input, cmd);
		free(input);
	}
	free(cmd);
	return (0);
}
