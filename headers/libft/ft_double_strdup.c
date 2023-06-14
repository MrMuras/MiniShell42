/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:08:48 by snocita           #+#    #+#             */
/*   Updated: 2023/06/13 17:48:52 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//USED FOR MINISHELL: this function copies **envp into a new **string called myenvp
char	**ft_double_strdup(char **envp)
{
	char	**myenvp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i])
		i++;
	myenvp = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		myenvp[i] = malloc(sizeof(char) * (strlen(envp[i]) + 1));
		strcpy(myenvp[i], envp[i]);
		i++;
	}
	myenvp[i] = NULL;
	return (myenvp);
}

// int	main(int ac, char **av, char **envp)
// {
// 	(void)ac;
// 	(void)av;
// 	int i = 0;
// 	char **ret = ft_double_strdup(envp);
// 	while (ret[i])
// 	{
// 		printf("%s\n", ret[i]);
// 		i++;
// 	}
// 	return (0);
// }
