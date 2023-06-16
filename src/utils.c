/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:09:14 by amurawsk          #+#    #+#             */
/*   Updated: 2023/06/16 18:33:48 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	my_free(char **str)
{
	while (str++)
		free(*str);
	free (str);
}

void	init_struct(t_cmd	*cmd)
{
	cmd->cmd = NULL;
	cmd->cmd_index = NULL;
	cmd->flag = NULL;
	cmd->args = NULL;
	cmd->expansion = NULL;
	cmd->is_builtin = 0;
}
