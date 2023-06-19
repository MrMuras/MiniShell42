/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:09:14 by amurawsk          #+#    #+#             */
/*   Updated: 2023/06/19 20:43:35 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_double_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init_struct(t_cmd	*cmd)
{
	cmd->cmd = NULL;
	cmd->cmd_index = NULL;
	cmd->flag = NULL;
	cmd->args = NULL;
	cmd->expansion = NULL;
	cmd->is_builtin = 0;
	cmd->exit = 0;
}
