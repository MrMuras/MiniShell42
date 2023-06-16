/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/16 18:49:03 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_cmd	*malloc_struct(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (0);
	return (cmd);
}

int	main(int ac,char **av, char **envp)
{
	char	*input;
	t_cmd	*cmd;

	(void)ac;
	(void)av;
	cmd = malloc_struct();
	cmd->myenvp = ft_double_strdup(envp);
	using_history();
	while (1)
	{
		init_struct(cmd);
		input = readline("Minishelly$ ");
		if (strlen(input) > 0)
			add_history(input);
		if (lexer(input, envp, cmd) == 1)
			execution(input, cmd);
		free(input);
	}
	free(cmd->args);
	free(cmd);
	return (0);
}
