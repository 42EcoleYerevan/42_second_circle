#include "../fdf.h"

void ft_norm_point(t_fdf *fdf, float *p)
{
	p[0] -= fdf->map->hwidth;
	p[1] -= fdf->map->hheight;
	p[0] /= fdf->map->hwidth;
	p[1] /= fdf->map->hheight;
	p[2] /= (float)fdf->map->z_scale / fdf->map->coef;
}


void ft_point_scale(t_fdf *fdf, float *p)
{
	p[0] *= fdf->map->wscale;
	p[1] *= fdf->map->hscale;
	p[0] += fdf->map->sx;
	p[1] += fdf->map->sy;
}

void ft_to_coords(float *p)
{
	p[2] /= -p[3];
	p[0] /= p[3] * p[2];
	p[1] /= p[3] * p[2];
}

void ft_set_matrix(t_fdf *fdf, float result[4][4])
{
	ft_xrotate(fdf, result);
	ft_yrotate(fdf, result);
	ft_zrotate(fdf, result);
	ft_offset(fdf, result);
	ft_projection(fdf, result);
}

void ft_proc(t_fdf *fdf, float result[4][4], float *p)
{
	ft_norm_point(fdf, p);
	ft_dot(p, result);
	ft_to_coords(p);
	ft_point_scale(fdf, p);
}
