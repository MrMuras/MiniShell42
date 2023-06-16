/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:58:29 by snocita           #+#    #+#             */
/*   Updated: 2023/06/16 18:33:30 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_env(t_cmd	*cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd->myenvp[i])
		printf("%s\n", cmd->myenvp[i++]);
	return (1);
}
