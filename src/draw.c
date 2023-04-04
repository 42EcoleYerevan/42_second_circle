/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/04 10:58:51 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include "../minilibx/mlx.h"

/* static void	ft_iso(t_fdf *fdf, int *x, int *y, int z) */
/* { */
/* 	int	tmp; */

/* 	tmp = (*x - *y) * cos(fdf->map->xfi); */
/* 	*y = (*x + *y) * sin(fdf->map->yfi) - z; */
/* 	*x = tmp; */
/* } */

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x < WIDTH && y < HEIGHT && x >=0 && y >= 0)
	{
		tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

static void ft_put_line(t_fdf *fdf, t_point *p1, t_point *p2, int color)
{
	int		dx;
	int		dy;
	int		max;
	int		i;
	float	xstep;
	float	ystep;

	dx = (p2->x - p1->x);
	dy = (p2->y - p1->y);
	max = MAX(ABS(dx), ABS(dy));
	xstep = (float)dx / max;
	ystep = (float)dy / max;
	i = 0;
	while (i < max)
	{
		ft_put_pixel(
				fdf,
			   	(p1->x + xstep * i),
			   	(p1->y + ystep * i),
			   	color
				);
		i++;
	}
}

float *ft_dot(float vec[4], float arr[4][4])
{
	int i;
	int j;
	float *out;

	out = (float *)calloc(sizeof(float), 4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out[i] += arr[j][i] * vec[j];
			j++;
		}
		i++;
	}
	return (out);
}

void norm(float vec[4])
{
	float length;
	int i;

	i = 0;
	while (i < 4)
	{
		length += vec[i] * vec[i];
		i++;
	}
	length = sqrt(length);
	i = 0;
	while (i < 4)
	{
		vec[i] = vec[i] / length;
		i++;
	}
}

void	ft_draw_line(t_fdf *fdf, t_point *p1, t_point *p2, int color)
{
	float project[4][4] = {
		{cos(fdf->map->xfi), sin(fdf->map->xfi), 0, 0},
		{-sin(fdf->map->yfi), cos(fdf->map->yfi), 0, 0},
		{0, -1, 1, 0},
		{0, 0, 0, 1},
	};
	float xrotate[4][4] = {
		{1, 0, 0, 0},
		{0, cos(fdf->xfi), -sin(fdf->xfi), 0},
		{0, sin(fdf->xfi), cos(fdf->xfi), 0},
		{0, 0, 0, 1}
	};
	float yrotate[4][4] = {
		{cos(fdf->yfi), 0, sin(fdf->yfi), 0},
		{0, 1, 0, 0},
		{-sin(fdf->yfi), 0, cos(fdf->yfi), 0},
		{0, 0, 0, 1}

	};
	float zrotate[4][4] = {
		{cos(fdf->zfi), -sin(fdf->zfi), 0, 0},
		{sin(fdf->zfi), cos(fdf->zfi), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	p1->x = p1->x * fdf->map->scale + fdf->map->sx - (int)fdf->map->width / 2;
	p1->y = p1->y * fdf->map->scale + fdf->map->sy - (int)fdf->map->height / 2;
	p2->x = p2->x * fdf->map->scale + fdf->map->sx - (int)fdf->map->width / 2;
	p2->y = p2->y * fdf->map->scale + fdf->map->sy - (int)fdf->map->height / 2;

	float vec1[4] = {p1->x, p1->y, p1->z, 1};
	float vec2[4] = {p2->x, p2->y, p2->z, 1};
	/* norm(vec1); */
	/* norm(vec2); */

	float *out1 = ft_dot(vec1, project);
	out1 = ft_dot(out1, xrotate);
	out1 = ft_dot(out1, yrotate);
	out1 = ft_dot(out1, zrotate);
	float *out2 = ft_dot(vec2, project);
	out2 = ft_dot(out2, xrotate);
	out2 = ft_dot(out2, yrotate);
	out2 = ft_dot(out2, zrotate);

	p1->x = out1[0];
	p1->y = out1[1];
	/* p1->z = out1[2]; */

	p2->x = out2[0];
	p2->y = out2[1];
	/* p2->z = out2[2]; */


	//change color
	if (color == 0 && (p1->z <= 0 || p2->z <= 0))
		color = 0xFFFFFF;
	else if (color == 0 && (p1->z > 0 || p2->z > 0))
		color = 0xFF0000;

	//drawing line
	ft_put_line(fdf, p1, p2, color);
}
