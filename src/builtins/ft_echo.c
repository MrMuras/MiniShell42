/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:51:48 by snocita           #+#    #+#             */
/*   Updated: 2023/06/15 17:32:53 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_echo(t_cmd	*cmd)
{
	cmd->is_builtin = 1;
	if (!cmd->args)
		printf(" ");
	else
	{
		printf("its fucked up\n");
		printf("%s", cmd->args);
	}
	if (!(cmd->flag))
		printf("\n");
	cmd = init_structs();
	printf("%s\n", cmd->cmd);
	return (1);
}
