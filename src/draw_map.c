/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/21 15:06:31 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_put_map(t_fdf *fdf)
{
	int row;
	int col;
	float result[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};

	ft_set_matrix(fdf, result);
	row = 0;
	while (row < fdf->map->height)
	{
		col = 0;
		while (col < fdf->map->width)
		{
			ft_draw_triangle(fdf, row, col, result);
			col++;
		}
		row++;
	}
}

int	ft_draw_map(t_fdf *fdf)
{
	/* fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT); */
	/* fdf->addr = mlx_get_data_addr(fdf->image, */
	/* 	   	&fdf->bits_per_pixel, */
	/* 	   	&fdf->line_length, */
	/* 	   	&fdf->endian); */
	ft_put_map(fdf);
	mlx_put_image_to_window(fdf->mlx,
		   	fdf->window,
		    fdf->image, 0, 0);
	/* usleep(10000); */
	/* mlx_destroy_image(fdf->mlx, fdf->image); */
	return (0);
}
