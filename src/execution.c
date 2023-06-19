/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:06:25 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 18:22:08 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execution(t_cmd	*cmd)
{
	pid_t	fd;
	fd = fork();
	if (fd == 0)
	{
		parsing(cmd);
		printf("The program is: %s\n", cmd->cmd);
		printf("The program path is: %s\n", cmd->path);
		int	status = execve(cmd->path, (char *[]){cmd->cmd, NULL}, (char *[]){*cmd->myenvp, NULL});
		if (status == -1)
			printf("NOPE");
		perror("execve");
		printf("%d\n", status);
	}
	waitpid(fd, NULL, 0);
}
