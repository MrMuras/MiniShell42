/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:13:23 by snocita           #+#    #+#             */
/*   Updated: 2023/06/16 16:56:14 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_builtin(t_cmd	*cmd)
{
	int	cmd_length;

	cmd_length = ft_strlen(cmd->cmd);
	if (ft_strncmp(cmd->cmd, "echo", cmd_length) == 0)
		return (ft_echo(cmd));
	if (ft_strncmp(cmd->cmd, "cd", cmd_length) == 0)
		return (ft_cd(cmd));
	if (ft_strncmp(cmd->cmd, "pwd", cmd_length) == 0)
		return (ft_pwd(cmd));
	if (ft_strncmp(cmd->cmd, "export", cmd_length) == 0)
		return (ft_export(cmd));
	// if (ft_strncmp(cmd->cmd, "unset", cmd_length) == 0)
	// 	return (ft_unset(cmd));
	if (ft_strncmp(cmd->cmd, "env", cmd_length) == 0)
		return (ft_env(cmd));
	// if (ft_strncmp(cmd->cmd, "exit", cmd_length) == 0)
	// 	return (ft_exit(cmd));
	else
		return (0);
}

int	parsing(t_cmd *cmd)
{
	if (cmd_validation(cmd) == 1)
	{
		printf("\t%s is accessible!\n", cmd->cmd);
		// if (cmd->is_builtin != 1)
		// 	printf("\tIt's a normal cmd!\n");
	}
	else
		printf("%s: command not found: %s\n", MINISHELL_NAME, cmd->cmd);
	return (0);
}

int	cmd_validation(t_cmd *cmd)
{
	t_valid	*valid;

	valid = (t_valid *)malloc(sizeof(t_valid));
	if (!valid)
		return (0);
	valid->spaces = 0;
	valid->path = 0;
	while (cmd->cmd[valid->spaces] == ' ')
		valid->spaces++;
	valid->env = getenv("PATH");
	valid->splitted_env = ft_split(valid->env, ':');
	while (valid->splitted_env[valid->path])
	{
		valid->tmp1 = ft_strjoin(valid->splitted_env[valid->path], "/");
		valid->tmp2 = ft_strjoin(valid->tmp1, \
			(cmd->cmd) + valid->spaces);
		free(valid->tmp1);
		if (access(valid->tmp2, X_OK) == 0)
		{
			free(valid->tmp2);
			return (1);
		}
		free(valid->tmp2);
		valid->path++;
	}
	free
	return (0);
}
