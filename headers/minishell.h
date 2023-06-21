/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:42:42 by snocita           #+#    #+#             */
/*   Updated: 2023/06/21 19:48:10 by snocita          ###   ########.fr       */
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
	char	*expansion;
	int		is_builtin;
	char	*path;
	int		exit;
	char	*input;
	char	**spl_input;
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

t_cmd	*lexer(char *input, t_cmd	*cmd, char **envp);
void	identify(char **input, t_cmd *cmd, char **envp);
int		parsing(t_cmd *cmd);
int		expand(char *str, t_cmd *cmd, char **envp);
int		cmd_validation(t_cmd *cmd);
t_cmd	*malloc_struct(void);
void	execution(t_cmd	*cmd);
int		ft_echo(t_cmd	*cmd);
int		is_builtin(t_cmd	*cmd, char	**envp);
int		ft_cd(t_cmd	*cmd);
int		ft_pwd(t_cmd	*cmd);
int		ft_env(char **envp);
int		ft_export(t_cmd	*cmd, char	**envp);
void	free_double_arr(char **str);
void	init_struct(t_cmd	*cmd);
void	free_all(t_cmd	*cmd);
int		ft_exit(t_cmd *cmd);

#endif