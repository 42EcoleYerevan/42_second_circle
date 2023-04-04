/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:19 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/04 19:12:58 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../minilibx/mlx.h"

static void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*tmp;

	if (x < WIDTH && y < HEIGHT && x >=0 && y >= 0)
	{
		tmp = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)tmp = color;
	}
}

static void ft_put_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	int		dx;
	int		dy;
	int		max;
	int		i;
	float	xstep;
	float	ystep;

	dx = (p2[0] - p1[0]);
	dy = (p2[1] - p1[1]);
	max = MAX(ABS(dx), ABS(dy));
	xstep = (float)dx / max;
	ystep = (float)dy / max;
	i = 0;
	while (i < max)
	{
		ft_put_pixel(
				fdf,
			   	(p1[0] + xstep * i),
			   	(p1[1] + ystep * i),
			   	color
				);
		i++;
	}
}

static void	ft_dot(int *vec, float **arr)
{
	int i;
	int j;
	int out[4] = {0, 0, 0, 0};

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out[i] += arr[j][i] * vec[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		vec[i] = out[i];
		i++;
	}
}

void	ft_arrcpy(float **arr1, float arr2[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr1[i][j] = arr2[i][j];
			j++;
		}
		i++;
	}
}

void ft_matmul(float **arr1, float arr2[4][4])
{
	float out[4][4] = { 0 };
	int i;
	int j;
	int k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				out[i][j] += arr1[i][k] * arr2[k][j]; 
				k++;
			}
			j++;
		}
		i++;
	}
	ft_arrcpy(arr1, out);
}

void ft_free_2d_arr(float **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}

float **ft_init_float_diagonal_matrix(int rows, int cols)
{
	int i;
	float **out;

	i = 0;
	out = (float **)malloc(sizeof(float *) * 4);
	while (i < rows)
	{
		out[i] = (float *)malloc(sizeof(float) * cols);
		if (!out[i])
		{
			ft_free_2d_arr(out);
			return (NULL);
		}
		out[i][i] = 1.0f;
		i++;
	}
	return (out);
}

void	ft_draw_line(t_fdf *fdf, int *p1, int *p2, int color)
{
	float project[4][4] = {
		{cos(fdf->map->xfi), sin(fdf->map->xfi), 0, 0},
		{-cos(fdf->map->yfi), sin(fdf->map->yfi), 0, 0},
		{0, -1, 1, 0},
		{0, 0, 0, 1},
	};
	float xrotate[4][4] = {
		{1, 0, 0, 0},
		{0, cos(fdf->xfi), -sin(fdf->xfi), 0},
		{0, sin(fdf->xfi), cos(fdf->xfi), 0},
		{0, 0, 0, 1}
	};
	float yrotate[4][4] = {
		{cos(fdf->yfi), 0, -sin(fdf->yfi), 0},
		{0, 1, 0, 0},
		{sin(fdf->yfi), 0, cos(fdf->yfi), 0},
		{0, 0, 0, 1}

	};
	float zrotate[4][4] = {
		{cos(fdf->zfi), sin(fdf->zfi), 0, 0},
		{-sin(fdf->zfi), cos(fdf->zfi), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	float scale[4][4] = {
		{fdf->map->scale, 0, 0, 0},
		{0, fdf->map->scale, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	float center[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{-(float)fdf->map->width * fdf->map->scale / 2,
		 -(float)fdf->map->height * fdf->map->scale / 2, 0, 1}
	};
	float offset[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{fdf->map->sx, fdf->map->sy, 0, 1}
	};

	//change color
	if (color == 0 && (p1[2] <= 0 || p2[2] <= 0))
		color = 0xFFFFFF;
	else if (color == 0 && (p1[2] > 0 || p2[2] > 0))
		color = 0xFF0000;

	float **result;

	result = ft_init_float_diagonal_matrix(4, 4);
	if (!result)
		return;

	ft_matmul(result, scale);
	ft_matmul(result, center);
	ft_matmul(result, project);
	ft_matmul(result, xrotate);
	ft_matmul(result, yrotate);
	ft_matmul(result, zrotate);
	ft_matmul(result, offset);

	ft_dot(p1, result);
	ft_dot(p2, result);

	/* // scale */
	/* ft_dot(p1, scale); */
	/* ft_dot(p2, scale); */

	/* // center */
	/* ft_dot(p1, center); */
	/* ft_dot(p2, center); */

	/* // iso */
	/* ft_dot(p1, project); */
	/* ft_dot(p2, project); */

	/* // rotate */
	/* ft_dot(p1, xrotate); */
	/* ft_dot(p1, yrotate); */
	/* ft_dot(p1, zrotate); */
	/* ft_dot(p2, xrotate); */
	/* ft_dot(p2, yrotate); */
	/* ft_dot(p2, zrotate); */

	/* // offset */
	/* ft_dot(p1, offset); */
	/* ft_dot(p2, offset); */

	// animation
	/* fdf->xfi += 0.00000001; */
	/* fdf->yfi += 0.00000001; */
	/* fdf->zfi += 0.00000001; */


	//drawing line
	ft_put_line(fdf, p1, p2, color);
}
