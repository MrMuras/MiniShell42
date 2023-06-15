/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:12:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/15 17:50:41 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//chdir cmd
int	ft_cd(t_cmd	*cmd)
{
	if (chdir(cmd->args) > 0)
	{
		printf("Path not findable");
		return (0);
	}
	return (1);
}
