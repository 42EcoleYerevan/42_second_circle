/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/29 17:56:06 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_put_map(t_fdf *fdf)
{
	int		row;
	int		col;
	float	result[4][4];

	ft_set_diagonal(result);
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
	ft_put_map(fdf);
	mlx_put_image_to_window(fdf->mlx,
		fdf->window,
		fdf->image, 0, 0);
	return (0);
}
