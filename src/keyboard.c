/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:39 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/29 17:30:06 by agladkov         ###   ########.fr       */
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
	if (ft_abs(fdf->yfi) > M_PI * 2)
		fdf->yfi = 0.0f;
}

void	ft_camera_move_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_RIGHT)
		fdf->map->sx -= 10;
	else if (keycode == ARROW_LEFT)
		fdf->map->sx += 10;
	else if (keycode == ARROW_UP)
		fdf->map->sy += 10;
	else if (keycode == ARROW_DOWN)
		fdf->map->sy -= 10;
	else if (keycode == KU)
		fdf->map->scale += 1;
	else if (keycode == KI)
		fdf->map->scale -= 1;
}

int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KT)
	{
		if (fdf->istriangle == 0)
			fdf->istriangle += 1;
		else
			fdf->istriangle -= 1;
	}
	else if (keycode == KP)
	{
		if (fdf->perspective == 0)
			fdf->perspective += 1;
		else
			fdf->perspective -= 1;
	}
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

int	ft_close_hook(t_fdf *fdf)
{
	if (fdf->image != NULL)
		mlx_destroy_image(fdf->mlx, fdf->image);
	if (fdf->window != NULL)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->map != NULL)
	{
		ft_free_2d_array(fdf->map->array, fdf->map->height);
		ft_free_2d_array(fdf->map->colors, fdf->map->height);
	}
	if (fdf->map)
		free(fdf->map);
	if (fdf->mouse)
		free(fdf->mouse);
	if (fdf->camera)
		free(fdf->camera);
	exit(1);
	return (0);
}
