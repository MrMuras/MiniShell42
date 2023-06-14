/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:52:47 by snocita           #+#    #+#             */
/*   Updated: 2023/01/13 12:44:01 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

/*
	Substract a string
*/

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strcpy;

	i = 0;
	if (len > ft_strlen(s))
	{
		strcpy = malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!strcpy)
			return (NULL);
	}
	else
	{
		strcpy = malloc(sizeof(char) * len + 1);
		if (!strcpy)
			return (NULL);
	}
	while (start < ft_strlen(s) && i < len)
	{
		strcpy[i] = s[start];
		i++;
		start++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}
