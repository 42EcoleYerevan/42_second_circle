/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:54:03 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/21 18:07:12 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

void	ft_free_2d_array_with_null(int **array)
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

float	*ft_new_point(int x, int y, t_fdf *fdf)
{
	float *point;

	point = (float*)malloc(sizeof(float) * 4);
	if (!point)
		return (NULL);
	point[0] = x;
	point[1] = y;
	point[2] = fdf->map->array[y][x];
	point[3] = 1;
	return (point);
}

void ft_clear_image(t_fdf *fdf)
{
	for (int i = 0; i < HEIGHT; i++)
		for(int j = 0; j < WIDTH; j++)
			ft_put_pixel(fdf, j, i, 0x000000);
}

void	ft_free_2d_array(int **array, int height)
{
	while (--height >= 0)
		free(array[height]);
	free(array);
}
