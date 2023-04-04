/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/05 00:21:47 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../minilibx/mlx.h"

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x < WIDTH && y < HEIGHT && x >=0 && y >= 0)
	{
		tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

static void ft_put_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		max;
	int		i;
	float	xstep;
	float	ystep;

	dx = (p2[0] - p1[0]);
	dy = (p2[1] - p1[1]);
	max = MAX(ABS(dx), ABS(dy));
	xstep = (float)dx / max;
	ystep = (float)dy / max;
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

void project(t_fdf *fdf, int *p)
{
	int x;

	x = p[0] * cos(fdf->map->xfi) - p[1] * cos(fdf->map->yfi);
	p[1] = p[0] * sin(fdf->map->xfi) + p[1] * sin(fdf->map->yfi) - p[2];
	p[0] = x;
}

void xrotate(t_fdf *fdf, int *p)
{
	int y;

	y = p[1] * cos(fdf->xfi) + p[2] * sin(fdf->xfi);
	p[2] = p[2] * cos(fdf->xfi) - p[1] * sin(fdf->xfi);
	p[1] = y;
}

void yrotate(t_fdf *fdf, int *p)
{
	int y;

	y = p[0] * cos(fdf->yfi) + p[2] * sin(fdf->yfi);
	p[2] = p[2] * cos(fdf->yfi) - p[0] * sin(fdf->yfi);
	p[0] = y;
}

void zrotate(t_fdf *fdf, int *p)
{
	int x;

	x = p[0] * cos(fdf->zfi) - p[1] * sin(fdf->zfi);
	p[1] = p[0] * sin(fdf->zfi) + p[1] * cos(fdf->zfi);
	p[0] = x;
}

void scale(t_fdf *fdf, int *p)
{
	p[0] *= fdf->map->scale;
	p[1] *= fdf->map->scale;
}

void center(t_fdf *fdf, int *p)
{
	p[0] -= fdf->map->width * fdf->map->scale / 2;
	p[1] -= fdf->map->height * fdf->map->scale / 2;
}

void offset(t_fdf *fdf, int *p)
{
	p[0] += fdf->map->sx;
	p[1] += fdf->map->sy;
}

void	ft_draw_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	//change color
	if (color == 0 && (p1[2] <= 0 || p2[2] <= 0))
		color = 0xFFFFFF;
	else if (color == 0 && (p1[2] > 0 || p2[2] > 0))
		color = 0xFF0000;

	// scale
	scale(fdf, p1);
	scale(fdf, p2);

	// center
	center(fdf, p1);
	center(fdf, p2);

	// project
	project(fdf, p1);
	project(fdf, p2);

	// rotate
	xrotate(fdf, p1);
	xrotate(fdf, p2);
	yrotate(fdf, p1);
	yrotate(fdf, p2);
	zrotate(fdf, p1);
	zrotate(fdf, p2);

	// offset
	offset(fdf, p1);
	offset(fdf, p2);

	//drawing line
	ft_put_line(fdf, p1, p2, color);
	free(p1);
	free(p2);
}
