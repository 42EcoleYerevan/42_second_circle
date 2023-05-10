/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:27:04 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/10 15:39:00 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_offset(t_fdf *fdf, float result[4][4])
{
	float	offset[4][4];

	ft_set_diagonal(offset);
	offset[3][0] = fdf->camera->position[0];
	offset[3][1] = fdf->camera->position[1];
	offset[3][2] = fdf->camera->position[2];
	ft_matmul(result, offset);
}

void	ft_projection(t_fdf *fdf, float result[4][4])
{
	float	projection[4][4];

	ft_set_diagonal(projection);
	projection[0][0] = fdf->camera->fovy;
	projection[1][1] = fdf->camera->fovy;
	projection[2][2] = -(fdf->camera->f + fdf->camera->n) \
						/ (fdf->camera->f - fdf->camera->n);
	projection[2][3] = -1.0f;
	projection[3][2] = -2.0f * (fdf->camera->f * fdf->camera->n) \
							/ (fdf->camera->f - fdf->camera->n);
	projection[3][3] = 0.0f;
	ft_matmul(result, projection);
}

void	ft_xrotate(t_fdf *fdf, float result[4][4])
{
	float	xrotate[4][4];

	ft_set_diagonal(xrotate);
	xrotate[1][1] = cos(fdf->xfi);
	xrotate[1][2] = sin(fdf->xfi);
	xrotate[2][1] = -sin(fdf->xfi);
	xrotate[2][2] = cos(fdf->xfi);
	ft_matmul(result, xrotate);
}

void	ft_yrotate(t_fdf *fdf, float result[4][4])
{
	float	yrotate[4][4];

	ft_set_diagonal(yrotate);
	yrotate[0][0] = cos(fdf->yfi);
	yrotate[0][2] = -sin(fdf->yfi);
	yrotate[2][0] = sin(fdf->yfi);
	yrotate[2][2] = cos(fdf->yfi);
	ft_matmul(result, yrotate);
}

void	ft_zrotate(t_fdf *fdf, float result[4][4])
{
	float	zrotate[4][4];

	ft_set_diagonal(zrotate);
	zrotate[0][0] = cos(fdf->zfi);
	zrotate[0][1] = sin(fdf->zfi);
	zrotate[1][0] = -sin(fdf->zfi);
	zrotate[1][1] = cos(fdf->zfi);
	ft_matmul(result, zrotate);
}
