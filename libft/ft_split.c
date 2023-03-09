/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:00:02 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 16:58:15 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		count_words(const char *s, char c);
int		len_word(const char *s, char c);
void	free_2d_char(char **arr);

int	count_words(const char *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((i > 0 && s[i] && s[i - 1] == c) || (i == 0 && s[i] != c))
			n++;
		i++;
	}
	return (n);
}

int	len_word(const char *s, char c)
{
	int	n;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

void	free_2d_char(char **arr)
{
	while (*arr)
		free(*arr++);
	free(arr);
}

char	**ft_strsplit(char **out, const char *s, char c)
{
	int	len;
	int	i;

	while (*s == c)
		s++;
	i = 0;
	while (*s)
	{
		len = len_word(s, c);
		out[i] = ft_substr(s, 0, len);
		if (!out[i])
		{
			free_2d_char(out);
			return (NULL);
		}
		s += len;
		while (*s && *s == c)
			s++;
		i++;
	}
	out[i] = NULL;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**out;

	len = count_words(s, c);
	out = (char **)malloc((len + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	if (len < 1)
	{
		out[0] = NULL;
		return (out);
	}
	out = ft_strsplit(out, s, c);
	if (!out)
		return (NULL);
	return (out);
}
