/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 18:18:45 by snocita          ###   ########.fr       */
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

void	free_all(t_cmd	*cmd)
{
	free_double_arr(cmd->myenvp);
	free(cmd);
}

int	main(int ac, char **av, char **envp)
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
		cmd = lexer(input, envp, cmd);
		if (cmd->is_builtin == 0)
			execution(cmd);
		free(input);
	}
	free_all(cmd);
	return (0);
}
