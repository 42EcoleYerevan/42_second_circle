/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/17 14:29:02 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx/mlx.h"
#include <math.h>
#include <unistd.h>

static void	ft_iso(int *x, int *y, int z)
{
	int	tmp;

	tmp = (*x - *y) * cos(0.4);
	*y = (*x + *y) * sin(0.4) - z;
	*x = tmp;
}

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)tmp = color;
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

void	ft_draw_line(t_fdf *fdf, t_point *p1, t_point *p2, int color)
{
	// scaling
	p1->x = p1->x * fdf->map->scale + fdf->map->sx;
	p1->y = p1->y * fdf->map->scale + fdf->map->sy;
	p2->x = p2->x * fdf->map->scale + fdf->map->sx;
	p2->y = p2->y * fdf->map->scale + fdf->map->sy;

	//isometric
	ft_iso(&p1->x, &p1->y, p1->z);
	ft_iso(&p2->x, &p2->y, p2->z);

	//drawing line
	ft_put_line(fdf, p1, p2, color);
}
