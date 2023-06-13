/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:13:23 by snocita           #+#    #+#             */
/*   Updated: 2023/06/13 18:54:59 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	parsing(t_cmd *cmd, int index)
{
	if (cmd_validation(cmd, index) == 1)
		printf("%s is accessible!\n", cmd->cmd[index]);
	else
		printf("%s: command not found: %s\n", MINISHELL_NAME, cmd->cmd[1]);
	return (0);
}

int	cmd_validation(t_cmd *cmd, int index)
{
	t_valid	*valid;

	valid = (t_valid *)malloc(sizeof(t_valid));
	if (!valid)
		return (0);
	valid->spaces = 0;
	valid->path = 0;
	while (cmd->cmd[index][valid->spaces] == ' ')
		valid->spaces++;
	valid->env = getenv("PATH");
	valid->splitted_env = ft_split(valid->env, ':');
	while (valid->splitted_env[valid->path])
	{
		valid->tmp1 = ft_strjoin(valid->splitted_env[valid->path], "/");
		valid->tmp2 = ft_strjoin(valid->tmp1, \
			(cmd->cmd[index]) + valid->spaces);
		free(valid->tmp1);
		if (access(valid->tmp2, X_OK) == 0)
		{
			free(valid->tmp2);
			return (1);
		}
		free(valid->tmp2);
		valid->path++;
	}
	return (0);
}
