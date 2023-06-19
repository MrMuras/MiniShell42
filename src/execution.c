/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:06:25 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 19:18:45 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execution(t_cmd	*cmd)
{
	(void)cmd;
	// pid_t	fd;
	// fd = fork();
	// if (fd == 0)
	// {
	// 	parsing(cmd);
	// 	printf("The program is: %s\n", cmd->cmd);
	// 	printf("The program path is: %s\n", cmd->path);
	// 	int	status = execve(cmd->path, (char *[]){cmd->cmd, NULL}, (char *[]){*cmd->myenvp, NULL});
	// 	if (status == -1)
	// 		printf("NOPE");
	// 	perror("execve");
	// 	printf("%d\n", status);
	// }
	// waitpid(fd, NULL, 0);
}
