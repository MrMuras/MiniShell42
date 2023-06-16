/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:51:48 by snocita           #+#    #+#             */
/*   Updated: 2023/06/16 16:52:15 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_echo(t_cmd	*cmd)
{
	//cmd->is_builtin = 1;
	if (!cmd->args)
		printf(" ");
	else
		printf("%s", cmd->args);
	if (!(cmd->flag))
		printf("\n");
	cmd->cmd = NULL;
	cmd->flag = NULL;
	cmd->args = NULL;
	return (1);
}
