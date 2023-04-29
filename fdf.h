/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:16:18 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/29 17:26:24 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800

# define KA 0
# define KS 1
# define KD 2
# define KW 13
# define KQ 12
# define KZ 6
# define KX 7
# define KY 8
# define KT 17
# define KP 35
# define KU 32
# define KI 34
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125
# define PLUS 69
# define MINUS 78

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>

# include "get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef struct s_map
{
	int		width;
	int		height;
	int		sx;
	int		sy;
	float	scale;
	float	hwidth;
	float	hheight;
	float	hscale;
	float	wscale;
	float	xfi;
	float	yfi;
	float	coef;
	int		z_scale;
	int		z_min;
	int		z_max;
	int		**array;
	int		**colors;
}	t_map;

typedef struct s_camera
{
	float	position[3];
	float	fov;
	float	fovy;
	float	n;
	float	f;
	float	aspect;
}	t_camera;

typedef struct s_mouse
{
	int	ispressed;
	int	x;
	int	y;
}	t_mouse;

typedef struct s_fdf
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			istriangle;
	int			perspective;
	float		xfi;
	float		yfi;
	float		zfi;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
}	t_fdf;

// utils
void	ft_free_2d_array_with_null(int **array);
void	ft_free_2d_array(int **array, int height);
void	ft_swap(int *x1, int *x2);
void	ft_clear_image(t_fdf *fdf);
float	*ft_new_point(int x, int y, t_fdf *fdf);

// parser map
t_map	*ft_create_map(char *filename);

// draw
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);
void	ft_draw_line(t_fdf *fdf, float *p1, float *p2, float result[4][4]);
void	ft_draw_triangle(t_fdf *fdf, int row, int col, float result[4][4]);

// draw map
int		ft_draw_map(t_fdf *fdf);

//parser utils
int		ft_atohex(char *str);
int		ft_read_map_height(char *filename);
int		ft_read_map_width(char *filename);
void	ft_z_scale(t_map *map);

// linal
void	ft_matmul(float arr1[4][4], float arr2[4][4]);
void	ft_dot(float *vec, float arr[4][4]);
void	ft_set_diagonal(float result[4][4]);
float	ft_abs(float a);
float	ft_max(float a, float b);

// project
void	ft_xrotate(t_fdf *fdf, float result[4][4]);
void	ft_yrotate(t_fdf *fdf, float result[4][4]);
void	ft_zrotate(t_fdf *fdf, float result[4][4]);
void	ft_offset(t_fdf *fdf, float result[4][4]);
void	ft_projection(t_fdf *fdf, float result[4][4]);

// keyboard
int		ft_key_hook(int keycode, t_fdf *fdf);
int		ft_close_hook(t_fdf *fdf);
int		ft_mousemove_hook(int x, int y, t_fdf *fdf);
int		ft_mousedown_hook(int button, int x, int y, t_fdf *fdf);
int		ft_mouseup_hook(int button, int x, int y, t_fdf *fdf);

// proc
void	ft_norm_point(t_fdf *fdf, float *p);
void	ft_point_scale(t_fdf *fdf, float *p);
void	ft_to_coords(float *p);
void	ft_set_matrix(t_fdf *fdf, float result[4][4]);
void	ft_proc(t_fdf *fdf, float result[4][4], float *p);

// init
void	ft_init_camera(t_fdf *fdf);
void	ft_init_map(t_fdf *fdf, char *path);
void	ft_init_mouse(t_fdf *fdf);
void	ft_init_hook(t_fdf *fdf);
void	ft_init_fdf(t_fdf *fdf, char **argv);

#endif
