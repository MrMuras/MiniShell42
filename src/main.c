/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/14 17:35:46 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//create an program main that shows a prompt and waits for a command and just spits it out.

// int	read_cmd(void)
// {
// 	write(0, "hello", 4);
// }

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	(void)envp;
	char	*input;

	using_history();
	while (1)
	{
		input = readline("\033[32mMinishelly $\033[0m ");
		add_history(input);
		lexer(input, envp);
	}
	return (0);
}
