/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:51:48 by snocita           #+#    #+#             */
/*   Updated: 2023/06/21 18:14:57 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_echo(t_cmd	*cmd)
{
	int	i;

	i = 0;
	if (cmd->args[i] == NULL)
		printf("\n");
	else
	{
		while (cmd->args[i] != NULL)
		{
			printf("%s\n", cmd->args[i]);
			i++;
		}
	}
	if (!(cmd->flag))
		printf("\n");
	return (0);
}
