/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:01:21 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/10 14:11:24 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_mousedown_hook(int button, int x, int y, t_fdf *fdf)
{
	if (button == 4)
	{
		if (fdf->map->scale > 0)
			fdf->map->scale -= 1;
		else
			fdf->map->scale = 0;
	}
	else if (button == 5)
		fdf->map->scale += 1;
	else
	{
		fdf->mouse->ispressed = button;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
	}
	ft_clear_image(fdf);
	ft_draw_map(fdf);
	return (0);
}

int	ft_mouseup_hook(int button, int x, int y, t_fdf *fdf)
{
	if (button > 0)
	{
		fdf->mouse->ispressed = 0;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
	}
	return (0);
}

int	ft_mousemove_hook(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse->ispressed == 1)
	{
		fdf->yfi -= 0.01f * (fdf->mouse->x - x);
		if (ft_abs(fdf->yfi) > M_PI * 2)
			fdf->yfi = 0.0f;
		if (ft_abs(fdf->yfi) > M_PI / 2 && ft_abs(fdf->yfi) < M_PI * 1.5f)
			fdf->xfi -= 0.01f * (fdf->mouse->y - y);
		else
			fdf->xfi += 0.01f * (fdf->mouse->y - y);
		fdf->mouse->x = x;
		fdf->mouse->y = y;
	}
	else if (fdf->mouse->ispressed == 2)
	{
		fdf->map->sx -= fdf->mouse->x - x;
		fdf->map->sy -= fdf->mouse->y - y;
		fdf->mouse->x = x;
		fdf->mouse->y = y;
	}
	ft_clear_image(fdf);
	ft_draw_map(fdf);
	return (0);
}
