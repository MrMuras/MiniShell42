/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:51:48 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 18:19:33 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_echo(t_cmd	*cmd)
{
	if (cmd->args == NULL)
		write(1, "", 1);
	else
		write(1, cmd->args, ft_strlen(cmd->args));
	if (!(cmd->flag))
		write(1, "\n", 1);
	return (0);
}
