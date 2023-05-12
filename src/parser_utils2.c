/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:36:42 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/12 13:54:44 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int	ft_is_valid(char *str)
{
	int	d;

	if (!str)
		return (0);
	d = 0;
	while (*str)
	{
		if (ft_isdigit(*str) == 1)
			d = 1;
		str++;
	}
	return (d);
}

void	ft_clear_gnl(char *line, int fd)
{
	if (line != NULL)
		free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
