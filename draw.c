/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/14 01:44:56 by agladkov         ###   ########.fr       */
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

void ft_swap(int *x1, int *x2)
{
	int tmp;
	
	tmp = *x2;
	*x2 = *x1;
	*x1 = tmp;
}

void	bresenham(t_fdf *fdf, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int e;

	if (x1 > x2 || y1 > y2)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	dx = (x2 - x1);
	dy = (y2 - y1);
	e = 2 * dy - dx;
	if (dx >= dy)
	{
		while (x1 != x2)
		{
			ft_put_pixel(fdf, x1,  y1, 0xffffff);
			if (e > 0)
			{
				y1++;
				e = e + 2 * (dy - dx);
			}
			else
				e = e + 2 * dy;
			x1++;
		}
	}
	else
	{
		while (y1 != y2)
		{
			ft_put_pixel(fdf, x1,  y1, 0xffffff);
			if (e > 0)
			{
				x1++;
				e = e + 2 * (dx - dy);
			}
			else
				e = e + 2 * dx;
			y1++;
		}
	}
}

int func(t_fdf *fdf)
{
	/* int a; */

	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->image,
								&fdf->bits_per_pixel,
								&fdf->line_length,
								&fdf->endian);

	/* a = fdf->n % 360; */
	/* bresenham(fdf, 200, 200, 200 + 200 * cos(a), 200 + 200 * sin(a)); */
	bresenham(fdf, 200, 200, 400, 200);
	bresenham(fdf, 200, 200, 200, 400);
	bresenham(fdf, 300, 300, 200, 200);
	/* fdf->n++; */
	
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->image);
	usleep(100000);
	return (0);
}


int	main(void)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (2);
	fdf->n = 0;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "(: Hello world fdf :)");

	mlx_loop_hook(fdf->mlx, func, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
