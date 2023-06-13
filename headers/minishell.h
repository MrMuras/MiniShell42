/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:42:42 by snocita           #+#    #+#             */
/*   Updated: 2023/06/13 19:09:05 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// char	*g_cmd_list[] = {"ls", "cmd", "pwd", "mkdir", "rm", "cp", "mv"};

//MINISHELL NAME
# define MINISHELL_NAME "\033[32mMinishelly\033[0m"

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
	int		*cmd_index;
	char	*flag;
	char	*args;
	char	*expansion;
	char	**myenvp;
}	t_cmd;

typedef struct s_valid
{
	int		spaces;
	int		path;
	char	*env;
	char	**splitted_env;
	char	*tmp1;
	char	*tmp2;
}	t_valid;

int	lexer(char *input, char **envp);
int	identify(char **input, t_cmd *cmd);
int	parsing(t_cmd *cmd);
int	cmd_validation(t_cmd *cmd);

#endif