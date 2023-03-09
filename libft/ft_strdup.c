/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:15:53 by agladkov          #+#    #+#             */
/*   Updated: 2023/02/05 18:26:56 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1, len + 1);
	return (out);
}
