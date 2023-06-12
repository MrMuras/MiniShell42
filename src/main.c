/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:51:31 by snocita           #+#    #+#             */
/*   Updated: 2023/06/12 17:50:53 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//create an program main that shows a prompt and waits for a command and just spits it out.

// int	read_cmd(void)
// {
// 	write(0, "hello", 4);
// }

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		looping = 1;
	// char	*cmd;
	while (looping)
	{
		char *input = readline("$ ");
		// printf("%s", input);
		lexer(input);
	}
	return (0);
}
