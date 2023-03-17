/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/17 13:35:06 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"
#include <math.h>
#include <unistd.h>

void	ft_iso(int *x, int *y, int z)
{
	int tmp;
	
	tmp = (*x - *y) * cos(0.4);
	*y = (*x + *y) * sin(0.4) - z;
	*x = tmp;
}

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char *tmp;

	tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;
}

void ft_put_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
	int dx;
	int dy;
	float xstep;
	float ystep;
	int max;
	int i;

	dx = (x2 - x1);
	dy = (y2 - y1);
	max = MAX(ABS(dx), ABS(dy));
	xstep = (float)dx / max;
	ystep = (float)dy / max;
	i = 0;
	while (i < max)
	{
		ft_put_pixel(
				fdf,
			   	(x1 + xstep * i),
			   	(y1 + ystep * i),
			   	color
				);
		i++;
	}
}

void	ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
	int z1;
	int z2;

	z1 = fdf->map->array[y1][x1];
	z2 = fdf->map->array[y2][x2];

	//change color
	if (fdf->map->array[y1][x1] > 0 && fdf->map->array[y2][x2] > 0)
		color = 0xFF0000;

	// scaling
	x1 = x1 * fdf->map->scale + fdf->map->sx;
	x2 = x2 * fdf->map->scale + fdf->map->sx;
	y1 = y1 * fdf->map->scale + fdf->map->sy;
	y2 = y2 * fdf->map->scale + fdf->map->sy;

	//isometric
	ft_iso(&x1, &y1, z1);
	ft_iso(&x2, &y2, z2);

	//drawing line
	ft_put_line(fdf, x1, y1, x2, y2, color);
}
