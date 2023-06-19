/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:06:25 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 14:02:09 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execution(char	*input, t_cmd	*cmd)
{
	pid_t	fd;
	(void)input;
	fd = fork();
	if (fd == 0)
	{
		parsing(cmd);
		printf("executing...\n");
		printf("The program is: %s\n", cmd->cmd);
		printf("The program path is: %s\n", cmd->path);
		int	status = execve(cmd->path, (char *[]){cmd->cmd, NULL}, (char *[]){NULL});
		perror("execve");
		printf("%d\n", status);
	}
	//kill(fd, SIGKILL);
}
