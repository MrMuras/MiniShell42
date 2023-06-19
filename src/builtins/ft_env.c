/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:58:29 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 12:50:39 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_env(t_cmd	*cmd)
{
	int	i;

	i = 0;
	while (cmd->myenvp[i])
		printf("%s\n", cmd->myenvp[i++]);
	return (1);
}
