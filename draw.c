/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/17 06:10:24 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"
#include <math.h>

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char *tmp;

	tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;
}

void	draw_line_by_x(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
	float k;
	int b;

	if (x1 > x2)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	k = (float)(y2 - y1) / (x2 - x1);
	b = y1 - x1 * k;
	while (x1 <= x2) 
	{
		ft_put_pixel(fdf, x1, x1 * k + b, color);	
		x1++;
	}
}

void	draw_line_by_y(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
	float k;
	int b;

	if (y1 > y2)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	k = (float)(x2 - x1) / (y2 - y1);
	b = x1 - y1 * k;
	while (y1 <= y2) 
	{
		ft_put_pixel(fdf, y1 * k + b, y1, color);	
		y1++;
	}
}

void	draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
	if (ABS(x2 - x1) >= ABS(y2 - y1))
		draw_line_by_x(fdf, x1, y1, x2, y2, color);
	else
		draw_line_by_y(fdf, x1, y1, x2, y2, color);
}
