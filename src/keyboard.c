/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:39 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/26 17:01:57 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_rotate_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KW)
		fdf->xfi += 0.05f;
	else if (keycode == KQ)
		fdf->xfi -= 0.05f;
	else if (keycode == KA)
		fdf->yfi -= 0.05f;
	else if (keycode == KS)
		fdf->yfi += 0.05f;
	else if (keycode == KZ)
		fdf->zfi -= 0.05f;
	else if (keycode == KX)
		fdf->zfi += 0.05f;
	if(ABS(fdf->yfi) > M_PI * 2)
		fdf->yfi = 0.0f;
}

void ft_camera_move_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_RIGHT)
		fdf->map->sx += 10;
	else if (keycode == ARROW_LEFT)
		fdf->map->sx -= 10;
	else if (keycode == ARROW_UP)
		fdf->map->sy += 10;
	else if (keycode == ARROW_DOWN)
		fdf->map->sy -= 10;
	else if (keycode == KU)
		fdf->map->scale += 1;
	else if (keycode == KI)
		fdf->map->scale -= 1;
}

int ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KT)
		fdf->istriangle += (fdf->istriangle == 0)? 1: -1;
	else if (keycode == KP)
		fdf->perspective += (fdf->perspective == 0)? 1: -1;
	else if (keycode == PLUS)
		fdf->map->coef += 0.1f;
	else if (keycode == MINUS)
		fdf->map->coef -= 0.1f;
	else if (keycode == ESC)
		ft_close_hook(fdf);
	ft_clear_image(fdf);
	ft_rotate_hook(keycode, fdf);
	ft_camera_move_hook(keycode, fdf);
	ft_draw_map(fdf);
	return (0);
}	

int ft_close_hook(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image);
	mlx_destroy_window(fdf->mlx, fdf->window);
	ft_free_2d_array(fdf->map->array, fdf->map->height);
	ft_free_2d_array(fdf->map->colors, fdf->map->height);
	free(fdf->map);
	free(fdf->camera);
	free(fdf);
	system("leaks fdf");
	exit(0);
	return (0);
}
