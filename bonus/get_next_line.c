/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:47:38 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/09 18:41:11 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*bufferjoin(char *buffer, char *str)
{
	char	*tmp;

	if (!buffer)
		buffer = (char *)ft_calloc_gnl(1, 1);
	tmp = buffer;
	buffer = ft_strjoin_gnl(buffer, str);
	free(tmp);
	tmp = NULL;
	return (buffer);
}

char	*read_line(int fd, char *buffer)
{
	ssize_t	len;
	char	*out;

	out = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	len = 1;
	while (len > 0)
	{
		len = read(fd, out, BUFFER_SIZE);
		if ((ft_strlen_gnl(buffer) == 0 && len == 0) || len < 0)
		{
			free(out);
			free(buffer);
			return (NULL);
		}
		out[len] = 0;
		buffer = bufferjoin(buffer, out);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(out);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = ft_substr_gnl(buffer, 0, len);
	return (line);
}

char	*rebuffer(char *buffer)
{
	char	*tmp;
	size_t	len;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[len] == '\n')
		len++;
	tmp = ft_substr_gnl(buffer, len, ft_strlen_gnl(buffer) - len);
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	out = get_line(buffer);
	buffer = rebuffer(buffer);
	return (out);
}
