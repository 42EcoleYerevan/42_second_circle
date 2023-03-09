/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:36:18 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/02 19:47:35 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ms1;
	unsigned char	*ms2;
	size_t			i;

	i = 0;
	ms1 = (unsigned char *) s1;
	ms2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (ms1[i] == ms2[i] && i < n - 1)
		i++;
	return (ms1[i] - ms2[i]);
}
