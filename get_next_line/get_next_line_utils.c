/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:50:55 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 18:17:25 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_gnl_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_gnl_calloc(size_t count, size_t size)
{
	char	*out;

	out = (char *)malloc(count * size);
	if (!out)
		return (NULL);
	while (count > 0)
		out[--count] = 0;
	return (out);
}

size_t	ft_gnl_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_gnl_strjoin(char *str1, char *str2)
{
	char	*out;
	int 	i;

	out = ft_gnl_calloc((ft_gnl_strlen(str1) + ft_gnl_strlen(str2) + 1), sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (*str1)
		out[i++] = *str1++;
	while (*str2)
		out[i++] = *str2++;
	out[i] = 0;
	return (out);
}

char	*ft_gnl_substr(char *s, size_t start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	strlen;

	strlen = ft_gnl_strlen((char *)s);
	if (!s)
		return (NULL);
	if (start > strlen)
		return ((char *)malloc(1 * sizeof(char)));
	if (len > strlen - start)
		len = strlen - start;
	out = (char *) malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = 0;
	return (out);
}
