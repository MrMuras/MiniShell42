/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:42:42 by snocita           #+#    #+#             */
/*   Updated: 2023/06/12 17:15:42 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// char	*g_cmd_list[] = {"ls", "cmd", "pwd", "mkdir", "rm", "cp", "mv"};

//KEYS
//Single Quote (39)
# define SQUOTE 42
//Double Quote (34)
# define DQUOTE 43

//GNL
# include "gnl/get_next_line.h"
//LIBFT
# include "libft/libft.h"
// # include "libreadline.h"
# include <readline/readline.h>
# include <readline/history.h>
// readline, rl_clear_history, rl_on_new_line, 
//	rl_replace_line, rl_redisplay, add_history
# include <stdio.h>
// printf 
# include <stdlib.h>
// malloc, free
# include <unistd.h>
// write, access, open, read, close,
//	dup, dup2, pipe, isatty, ttyname,
//	ttyslot, ioctl
# include <sys/types.h>
// fork, wait, waitpid, wait3, wait4
# include <signal.h>
// kill, exit
# include <sys/stat.h>
// getcwd, chdir, stat, lstat, fstat, unlink,
// errono macro
# include <errno.h>
//	execve
# include <dirent.h>
// opendir, readdir, closedir
# include <string.h>
// strerror, perror
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
//tcsetattr, tcgetattr, tgetent, 
//	tgetflag, tgetnum, tgetstr, tgoto, tputs: termios.h

typedef struct s_cmd
{
	char	*cmd;
	char	*flag;
	char	**args;
}	t_cmd;

int	lexer(char *input);
int	identify(char **input);
// int	parsing(t_cmd *cmd);

#endif