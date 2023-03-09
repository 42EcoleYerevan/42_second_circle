/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:41:21 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/02 18:10:33 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	i;
	size_t	d;

	if (!haystack || !needle)
		return (NULL);
	i = 0;
	d = 0;
	h = (char *) haystack;
	if (*needle == 0)
		return (h);
	while (h[d] && d < len)
	{
		if (h[d] == needle[0])
		{
			i = 0;
			while (h[d + i] == needle[i] && needle[i] && d + i < len)
				i++;
			if (needle[i] == '\0')
				return (h + d);
		}
		d++;
	}
	return (0);
}
