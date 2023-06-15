/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:18:05 by snocita           #+#    #+#             */
/*   Updated: 2023/06/15 17:40:19 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	ft_export(t_cmd	*cmd)
{
	char	**export_vars;

	if (!(cmd->args))
		return (0);
	export_vars = ft_split(cmd->args, '=');
	printf("%s\n", export_vars[1]);
	return (1);
}
