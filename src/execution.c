/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:06:25 by snocita           #+#    #+#             */
/*   Updated: 2023/06/19 13:22:47 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	execution(char	*input, t_cmd	*cmd)
{
	execve("/usr/bin/make", (char *[]){"make", "re", NULL}, (char *[]){NULL});
}
