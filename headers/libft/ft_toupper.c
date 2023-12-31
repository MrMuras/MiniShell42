/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:56:16 by snocita           #+#    #+#             */
/*   Updated: 2023/01/13 21:48:23 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>

int	ft_islowercase(int c);
int	ft_toupper(int c);

int	ft_islowercase(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_toupper(int c)
{
	if (ft_islowercase(c))
	{
		c -= 32;
		return (c);
	}
	return (c);
}

// int	main(void)
// {
// 	printf("%c", ft_toupper('E'));
// }
