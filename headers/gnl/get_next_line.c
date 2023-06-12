/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:38:06 by snocita           #+#    #+#             */
/*   Updated: 2023/05/12 13:24:31 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char **buffer)
{
	char	*line;
	char	*temp;
	char	*address_nwl;

	address_nwl = ft_strchr(*buffer, '\n');
	if (address_nwl)
	{
		line = ft_substr(*buffer, 0, address_nwl - *buffer + 1);
		temp = ft_strdup(address_nwl + 1);
		free(*buffer);
		*buffer = temp;
		if (!**buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
		return (line);
	}
	else
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	return (line);
}

static int	read_buffer(int fd, char **buffer)
{
	char	*temp;
	char	*temp_buf;
	int		bytes_read;

	temp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buf)
		return (-1);
	bytes_read = read(fd, temp_buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		temp_buf[bytes_read] = '\0';
		if (!*buffer)
			*buffer = ft_strdup(temp_buf);
		else
		{
			temp = ft_strjoin(*buffer, temp_buf);
			free(*buffer);
			*buffer = temp;
		}
		if (ft_strchr(*buffer, '\n'))
			break ;
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
	}
	free(temp_buf);
	return (bytes_read);
}

char	*get_next_line(int fd, char *buffer)
{
	// static char	*buffer;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read_buffer(fd, &buffer);
	if (bytes_read < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (!bytes_read && !buffer)
		return (NULL);
	line = ft_get_line(&buffer);
	return (line);
}
