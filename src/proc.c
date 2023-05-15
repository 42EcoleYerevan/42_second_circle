/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:26:58 by agladkov          #+#    #+#             */
/*   Updated: 2023/05/13 17:07:03 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_norm_point(t_fdf *fdf, float *p)
{
	p[0] -= fdf->map->hwidth;
	p[1] -= fdf->map->hheight;
	p[0] /= fdf->map->hwidth;
	p[1] /= fdf->map->hheight;
	if (fdf->map->z_scale != 0)
		p[2] /= (float)fdf->map->z_scale / fdf->map->coef;
	else
		p[2] *= fdf->map->coef;
}

void	ft_point_scale(t_fdf *fdf, float *p)
{
	p[0] *= fdf->map->hwidth * fdf->map->scale;
	p[1] *= fdf->map->hheight * fdf->map->scale;
	p[0] += fdf->map->sx;
	p[1] += fdf->map->sy;
}

void	ft_to_coords(float *p)
{
	p[0] /= p[3];
	p[1] /= p[3];
}

void	ft_set_matrix(t_fdf *fdf, float result[4][4])
{
	ft_zrotate(fdf, result);
	ft_xrotate(fdf, result);
	ft_yrotate(fdf, result);
	ft_offset(fdf, result);
	if (fdf->perspective)
		ft_projection(fdf, result);
}

void	ft_proc(t_fdf *fdf, float result[4][4], float *p)
{
	ft_norm_point(fdf, p);
	ft_dot(p, result);
	ft_to_coords(p);
	ft_point_scale(fdf, p);
}
