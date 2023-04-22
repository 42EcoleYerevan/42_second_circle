/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:27:04 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/22 17:15:12 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void ft_offset(t_fdf *fdf, float result[4][4])
{
	float offset[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{fdf->camera->position[0],
		 fdf->camera->position[1], 
		 fdf->camera->position[2], 1.0f}
	};
	ft_matmul(result, offset);
}

void ft_projection(t_fdf *fdf, float result[4][4])
{
	float projection[4][4] = {
		{fdf->camera->fovy, 0.0f, 0.0f, 0.0f},
		{0.0f, fdf->camera->fovy, 0.0f, 0.0f},
		{0.0f, 0.0f, -(fdf->camera->f + fdf->camera->n)/
				(fdf->camera->f - fdf->camera->n), -1.0f},
		{0.0f, 0.0f, -2.0f*(fdf->camera->f * fdf->camera->n)/
				(fdf->camera->f - fdf->camera->n), 0.0f}
	};
	ft_matmul(result, projection);
}

void ft_xrotate(t_fdf *fdf, float result[4][4])
{
	float xrotate[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.0f},
		{0.0f, cos(fdf->xfi), sin(fdf->xfi), 0.0f},
		{0.0f, -sin(fdf->xfi), cos(fdf->xfi), 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};
	ft_matmul(result, xrotate);
}

void ft_yrotate(t_fdf *fdf, float result[4][4])
{
	float yrotate[4][4] = {
		{cos(fdf->yfi), 0.0f, -sin(fdf->yfi), 0.0f},
		{0.0f, 1.0f, 0.0f, 0.0f},
		{sin(fdf->yfi), 0.0f, cos(fdf->yfi), 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};
	ft_matmul(result, yrotate);
}

void ft_zrotate(t_fdf *fdf, float result[4][4])
{
	float zrotate[4][4] = {
		{cos(fdf->zfi), sin(fdf->zfi), 0.0f, 0.0f},
		{-sin(fdf->zfi), cos(fdf->zfi), 0.0f, 0.0f},
		{0.0f, 0.0f, 1.0f, 0.0f},
		{0.0f, 0.0f, 0.0f, 1.0f}
	};
	ft_matmul(result, zrotate);
}
