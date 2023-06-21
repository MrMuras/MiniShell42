/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:13:23 by snocita           #+#    #+#             */
/*   Updated: 2023/06/21 16:18:05 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_builtin(t_cmd	*cmd, char	**envp)
{
	if ((ft_strncmp(cmd->cmd, "echo", ft_strlen("echo") + 1) == 0))
		return (ft_echo(cmd));
	if (ft_strncmp(cmd->cmd, "cd", ft_strlen("cd") + 1) == 0)
		return (ft_cd(cmd));
	if (ft_strncmp(cmd->cmd, "pwd", ft_strlen("pwd") + 1) == 0)
		return (ft_pwd(cmd));
	if (ft_strncmp(cmd->cmd, "export", ft_strlen("export") + 1) == 0)
		return (ft_export(cmd, envp));
	// if (ft_strncmp(cmd->cmd, "unset", ft_strlen()) == 0))
	// 	return (ft_unset(cmd));
	if (ft_strncmp(cmd->cmd, "env", ft_strlen("env") + 1) == 0)
		return (ft_env(envp));
	if (ft_strncmp(cmd->cmd, "exit", ft_strlen("exit") + 1) == 0)
		return (ft_exit(cmd));
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
			cmd->path = valid->tmp2;
			free(valid->tmp2);
			return (1);
		}
		free(valid->tmp2);
		valid->path++;
	}
	return (0);
}
