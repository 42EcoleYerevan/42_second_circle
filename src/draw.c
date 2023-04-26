/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/26 19:54:50 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
		tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

static void ft_put_line(t_fdf *fdf, float *p1, float *p2, int color)
{
	int		max;
	int		i;
	float	dx;
	float	dy;
	float	xstep;
	float	ystep;

	dx = p2[0] - p1[0];
	dy = p2[1] - p1[1];
	max = MAX(ABS(dx), ABS(dy));
	xstep = dx / max;
	ystep = dy / max;
	i = 0;
	while (i < max)
	{
		ft_put_pixel(
				fdf,
			   	(p1[0] + xstep * i),
			   	(p1[1] + ystep * i),
			   	color
				);
		i++;
	}
}

void	ft_draw_line(t_fdf *fdf, float *p1, float *p2, float result[4][4])
{
	int color;

	color = fdf->map->colors[(int)p2[1]][(int)p2[0]];
	if (color == 0 && (p2[2] != 0 || p1[2] != 0))
		color = 0xFF0000;
	else if (color == 0 && (p2[2] == 0 || p1[2] == 0))
		color = 0xFFFFFF;
	ft_proc(fdf, result, p1);
	ft_proc(fdf, result, p2);
	ft_put_line(fdf, p1, p2, color);
	free(p1);
	free(p2);
}

void	ft_draw_triangle(t_fdf *fdf, int row, int col, float result[4][4])
{
	if (col < fdf->map->width - 1)
		ft_draw_line(fdf, ft_new_point(col, row, fdf),
				ft_new_point(col + 1, row, fdf),
				result);			
	if (row < fdf->map->height - 1)
		ft_draw_line(fdf, ft_new_point(col, row, fdf),
			   ft_new_point(col, row + 1, fdf),
			   result);			
	if (fdf->istriangle && row < fdf->map->height - 1 && col < fdf->map->width - 1)
		ft_draw_line(fdf, ft_new_point(col + 1, row, fdf),
			   ft_new_point(col, row + 1, fdf),
			   result);			
}
