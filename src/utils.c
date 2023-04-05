/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:03 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/05 12:18:55 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"
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

int	*ft_new_point(int x, int y, t_fdf *fdf)
{
	int *point;

	point = (int *)malloc(sizeof(int) * 4);
	if (!point)
		return (NULL);
	point[0] = x;
	point[1] = y;
	point[2] = fdf->map->array[y][x];
	point[3] = 1;
	return (point);
}
