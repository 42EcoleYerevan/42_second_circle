/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:35:49 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/01 04:45:23 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	c = c % 256;
	tmp = (const char *) s;
	if (n < 1)
		return (0);
	while (i < n)
	{
		if (tmp[i] == c)
			return ((void *) s + i);
		i++;
	}
	return (0);
}
