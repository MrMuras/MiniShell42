/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:18:05 by snocita           #+#    #+#             */
/*   Updated: 2023/06/17 15:01:26 by amurawsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	update_envp(t_cmd	*cmd, char *export_var)
{
	char	**temp_myenvp;
	int		i;

	i = 0;
	while (cmd->myenvp[i])
		i++;
	i++;
	temp_myenvp = malloc(sizeof(char *) * (i));
	temp_myenvp[i] = export_var;
	cmd->myenvp = temp_myenvp;
	printf("%s\n", cmd->myenvp[i]);
	free(temp_myenvp);
}

int	ft_export(t_cmd	*cmd)
{
	if (!(cmd->args))
		return (0);
	update_envp(cmd, cmd->args);
	return (1);
}
