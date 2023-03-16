/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/16 20:55:45 by agladkov         ###   ########.fr       */
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

void	bresenham(t_fdf *fdf, int x1, int y1, int x2, int y2, int color)
{
	float k;
	float b;

	if (ABS(y2 - y1) > ABS(x2 - x1))
	{
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
	else
	{
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
}

int func(t_fdf *fdf)
{
	int a;
	int new_x; int new_y;
	static float crad = 3.14 / 180;
	static int n;


	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->image,
								&fdf->bits_per_pixel,
								&fdf->line_length,
								&fdf->endian);

	a = n % 360;
	new_x = 200 + 200 * cos(a * crad);
	new_y = 200 + 200 * sin(a * crad);
	bresenham(fdf, 200, 200, new_x, new_y, (n % 256 << 8) + (~(n % 256 << 16)));
	printf("x: %3d | y: %3d\n", new_x, new_y);
	n++;
	
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	mlx_destroy_image(fdf->mlx, fdf->image);
	usleep(10000);
	return (0);
}

int	main(void)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (2);
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "(: Hello world fdf :)");

	mlx_loop_hook(fdf->mlx, func, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
