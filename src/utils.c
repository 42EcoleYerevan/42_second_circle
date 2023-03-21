/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:03 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/17 18:06:25 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <stdlib.h>

void	ft_free_2d_array(int **array)
{
	int	n;

	n = 0;
	while (array[n])
		free(array[n++]);
	free(array);
}

void	ft_swap(int *x1, int *x2)
{
	int	tmp;
	
	tmp = *x2;
	*x2 = *x1;
	*x1 = tmp;
}

t_point	*ft_new_point(int x, int y, t_fdf *fdf)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = fdf->map->array[y][x];
	return (point);
}
