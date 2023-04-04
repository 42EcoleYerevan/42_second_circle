/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/04 13:34:10 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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

void	ft_dot(int vec[4], float arr[4][4])
{
	int i;
	int j;
	int out[4] = {0, 0, 0, 0};

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
	i = 0;
	while (i < 4)
	{
		vec[i] = out[i];
		i++;
	}
}

void	ft_draw_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	float project[4][4] = {
		{cos(fdf->map->xfi), sin(fdf->map->xfi), 0, 0},
		{-cos(fdf->map->yfi), sin(fdf->map->yfi), 0, 0},
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
		{cos(fdf->yfi), 0, -sin(fdf->yfi), 0},
		{0, 1, 0, 0},
		{sin(fdf->yfi), 0, cos(fdf->yfi), 0},
		{0, 0, 0, 1}

	};
	float zrotate[4][4] = {
		{cos(fdf->zfi), sin(fdf->zfi), 0, 0},
		{-sin(fdf->zfi), cos(fdf->zfi), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	float scale[4][4] = {
		{fdf->map->scale, 0, 0, 0},
		{0, fdf->map->scale, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	float center[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{-(float)fdf->map->width * fdf->map->scale / 2,
		 -(float)fdf->map->height * fdf->map->scale / 2, 0, 1}
	};
	float offset[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{fdf->map->sx, fdf->map->sy, 0, 1}
	};

	//change color
	if (color == 0 && (p1[2] <= 0 || p2[2] <= 0))
		color = 0xFFFFFF;
	else if (color == 0 && (p1[2] > 0 || p2[2] > 0))
		color = 0xFF0000;


	// scale
	ft_dot(p1, scale);
	ft_dot(p2, scale);

	// center
	ft_dot(p1, center);
	ft_dot(p2, center);

	// iso
	ft_dot(p1, project);
	ft_dot(p2, project);

	// rotate
	ft_dot(p1, xrotate);
	ft_dot(p1, yrotate);
	ft_dot(p1, zrotate);
	ft_dot(p2, xrotate);
	ft_dot(p2, yrotate);
	ft_dot(p2, zrotate);

	// animation
	fdf->xfi += 0.00001;
	fdf->yfi += 0.00001;
	fdf->zfi += 0.00001;


	//drawing line
	ft_put_line(fdf, p1, p2, color);
}
