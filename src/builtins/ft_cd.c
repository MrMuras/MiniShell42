/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:12:18 by snocita           #+#    #+#             */
/*   Updated: 2023/06/21 16:41:56 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

//chdir cmd
int	ft_cd(t_cmd	*cmd)
{
	int	i;

	i = 0;
	if (chdir(cmd->args[i]) > 0)
	{
		printf("Path not findable");
		return (0);
	}
	return (1);
}
