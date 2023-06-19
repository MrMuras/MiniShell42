/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:18:05 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 18:12:13 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	update_envp(t_cmd	*cmd, char *export_var)
{
	char	**temp_myenvp;
	int		i;
	int		k;
	char	**to_free;

	i = 0;
	while (cmd->myenvp[i])
	{
		// printf("\n%s\n", cmd->myenvp[i]);
		if (ft_strncmp(cmd->myenvp[i], export_var, ft_strlen(export_var)) == 0)
		{
			printf("\nQUITTING!\n");
			return ;
		}
		i++;
	}
	i++;
	to_free = cmd->myenvp;
	temp_myenvp = malloc(sizeof(char *) * (i + 1));
	k = 0;
	while (cmd->myenvp[k])
	{
		temp_myenvp[k] = cmd->myenvp[k];
		k++;
	}
	temp_myenvp[i - 1] = export_var;
	temp_myenvp[i] = NULL;
	cmd->myenvp = temp_myenvp;
	printf("%s\n", cmd->myenvp[i - 1]);
	//free_double_arr(to_free);
}

int	ft_export(t_cmd	*cmd)
{
	if (!(cmd->args))
		return (0);
	update_envp(cmd, cmd->args);
	return (1);
}
