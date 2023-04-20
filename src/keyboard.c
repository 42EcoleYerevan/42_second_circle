/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:39 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/20 20:45:10 by agladkov         ###   ########.fr       */
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
}

int ft_key_hook(int keycode, t_fdf *fdf)
{
	printf("hello form key_hook %d\n", keycode);
	if (keycode == ARROW_RIGHT)
		fdf->camera->position[0] += 0.1f;
	else if (keycode == ARROW_LEFT)
		fdf->camera->position[0] -= 0.1f;
	else if (keycode == ARROW_UP)
		fdf->camera->position[1] += 0.1f;
	else if (keycode == ARROW_DOWN)
		fdf->camera->position[1] -= 0.1f;
	else if (keycode == KU)
		fdf->camera->position[2] += 1.0f;
	else if (keycode == KI)
		fdf->camera->position[2] -= 1.0f;
	else if (keycode == KT)
		fdf->istriangle += (fdf->istriangle == 0)? 1: -1;
	else if (keycode == KP)
		fdf->perspective += (fdf->perspective == 0)? 1: -1;
	else if (keycode == PLUS)
		fdf->map->coef += 0.1f;
	else if (keycode == MINUS)
		fdf->map->coef -= 0.1f;
	ft_clear_image(fdf);
	ft_rotate_hook(keycode, fdf);
	ft_draw_map(fdf);
	return (0);
}	

int ft_close_hook(t_fdf *fdf)
{
	ft_free_2d_array(fdf->map->array, fdf->map->height);
	ft_free_2d_array(fdf->map->colors, fdf->map->height);
	free(fdf->map);
	free(fdf->camera);
	free(fdf);
	exit(0);
	return (0);
}

int	ft_mousedown_hook(int button, int x, int y, t_fdf *fdf)
{
	fdf->istriangle = 0;
	printf("%d %d %d\n", x, y, button);
	return (0);
}

int ft_mousemove_hook(int x, int y, t_fdf *fdf)
{
	fdf->istriangle = 0;
	x = 0;
	y = 0;
	/* printf("%d %d\n", x, y); */
	return (0);
}
