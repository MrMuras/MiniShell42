/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:46:14 by snocita           #+#    #+#             */
/*   Updated: 2023/06/21 19:47:35 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	makefile(void)
{
	execve("/usr/bin/make", (char *[]){"make", "re", NULL}, (char *[]){NULL});
}

t_cmd	*lexer(char *input, t_cmd	*cmd, char **envp)
{
	int		i;

	if (strlen(input) == 0)
		return (0);
	if (strncmp(input, "make", 4) == 0)
		makefile();
	cmd->spl_input = ft_split(input, ' ');
	i = 0;
	identify(cmd->spl_input, cmd, envp);
	return (cmd);
}

void	identify(char **input, t_cmd *cmd, char **envp)
{
	int	i;
	int	j;
	int	is_rec;

	i = 0;
	j = 0;
	is_rec = 0;
	while (input[i])
	{
		if (is_builtin(cmd, envp) == 1)
		{
			cmd->is_builtin = 1;
			printf("\tand is a builtin!\n");
		}
		if (i == 0)
			cmd->cmd = input[i];
		else if (i == 1 && input[i][0] == '-')
			cmd->flag = input[i];
		else if (input[i][0] == '$')
			expand(input[i], cmd, envp);
		else if (input[i][0] == '|')
		{
			if (input[i + 1])
			{
				is_rec = 1;
				break ;
			}
		}
		else
		{
			if (j < 100)
			{
				if (input[i])
				{
					cmd->args[j] = input[i];
					j++;
					i++;
				}
			}
			else
				break ;
		}
		i++;
	}
	if (is_rec == 1)
		identify(input + i + 1, cmd, envp);
}

int	expand(char *str, t_cmd *cmd, char **envp)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] >= 'a' && str[i] <= 'z')
			return (0);
		while (envp[j])
		{
			if ((ft_strncmp(envp[j], str + 1, ft_strlen(str + 1))) == 0)
			{
				if (envp[j][ft_strlen(str + 1)] == '=')
				{
					while (envp[j][k] != '=')
						k++;
					cmd->expansion = &envp[j][k + 1];
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	cmd->expansion = " \n";
	printf("%s", cmd->expansion);
	return (1);
}
