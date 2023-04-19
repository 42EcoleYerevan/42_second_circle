/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:39 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/19 16:55:09 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	{
		tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

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
	ft_rotate_hook(keycode, fdf);
	for (int i = 0; i < HEIGHT; i++)
		for(int j = 0; j < WIDTH; j++)
			ft_put_pixel(fdf, j, i, 0x000000);
	ft_draw_map(fdf);
	return (0);
}	

