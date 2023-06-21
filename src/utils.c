/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:09:14 by amurawsk          #+#    #+#             */
/*   Updated: 2023/06/21 18:23:01 by snocita          ###   ########.fr       */
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

void	free_all(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[i] != NULL && i < 100)
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
	free(cmd->spl_input);
	free(cmd);
}

void	init_struct(t_cmd	*cmd)
{
	cmd->cmd = NULL;
	cmd->flag = NULL;
	cmd->args = NULL;
	cmd->expansion = NULL;
	cmd->is_builtin = 0;
	cmd->exit = 0;
}
