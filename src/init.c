/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:36 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/19 16:43:14 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_init_camera(t_fdf *fdf)
{
	fdf->camera = (t_camera *)malloc(sizeof(t_camera));
	fdf->camera->position[0] = 0.0f;
	fdf->camera->position[1] = 0.0f;
	fdf->camera->position[2] = -2.0f;
	fdf->camera->aspect = (float)WIDTH / (float)HEIGHT;
	fdf->camera->fov = 90.0f / 2.0f;
	fdf->camera->fovy = 1.0f / tanhf(M_PI / 180.0f * fdf->camera->fov);
	fdf->camera->n = 0.1f;
	fdf->camera->f = 1000.0f;
}

void ft_init_map(t_fdf *fdf, char *path)
{
	fdf->map = ft_create_map(path);
	fdf->map->scale = (float)WIDTH / MAX(fdf->map->width, fdf->map->height) / 2;
	fdf->map->sx = WIDTH / 2.0f;
	fdf->map->sy = HEIGHT / 2.0f;
	fdf->map->coef = 0.2f;
	fdf->map->hwidth = (float)fdf->map->width / 2;
	fdf->map->hheight = (float)fdf->map->height / 2;
	fdf->map->hscale = fdf->map->hheight * fdf->map->scale;
	fdf->map->wscale = fdf->map->hwidth * fdf->map->scale;
}
