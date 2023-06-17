/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:58:29 by snocita           #+#    #+#             */
/*   Updated: 2023/06/17 15:01:25 by snocita          ###   ########.fr       */
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
