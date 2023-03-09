/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:23:29 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/02 18:03:53 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_number(long n)
{
	int	len;

	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	else if (n == 0)
		return (1);
	else
		len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	num;
	char			*out;

	len = len_number(n);
	if (n < 0)
		num = -(unsigned int) n;
	else
		num = (unsigned int) n;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	out[len--] = 0;
	if (n == 0)
		out[len--] = '0';
	while (num > 0)
	{
		out[len] = num % 10 + 48;
		len--;
		num /= 10;
	}
	if (len == 0)
		out[len] = '-';
	return (out);
}
