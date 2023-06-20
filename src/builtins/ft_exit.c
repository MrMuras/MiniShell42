/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:40:25 by amurawsk          #+#    #+#             */
/*   Updated: 2023/06/20 20:23:52 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_exit(t_cmd *cmd)
{
	if (strncmp(cmd->cmd, "exit", 4) == 0)
		cmd->exit = 1;
	return (1);
}
