/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:42:09 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/02 18:12:45 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	c = (unsigned char) c;
	while (*s)
		s++;
	while (s != tmp)
	{
		if (*s == c)
			return ((char *) s);
		s--;
	}
	if (*s == c)
		return ((char *) s);
	return (0);
}
