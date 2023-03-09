/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:40:50 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/07 19:45:41 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!s1 || !s2)
		return (0);
	tmp1 = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (*tmp1 == *tmp2 && *tmp1 && --n > 0)
	{
		tmp1++;
		tmp2++;
	}
	return (*tmp1 - *tmp2);
}
