#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800
# define DEFAULT_COLOR 0xFFFFFF

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#ifndef __unix__
#  include "./minilibx-linux/mlx.h"
#else
#  include "./minilibx/mlx.h"
#endif

#include "get_next_line/get_next_line.h"
#include "./libft/libft.h"

# define ABS(a) ((a < 0)? -(a): a)
# define MAX(a, b) ((a > b)? a: b)

typedef struct s_point
{
	int x;
	int y;
	int z;
} t_point;

typedef struct s_map
{
	int	width;
	int	height;
	int	scale;
	int sx;
	int sy;
	int z_scale;
	int z_min;
	int z_max;
	int	**array;
	int **colors;
} t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	void	*image;
	char 	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	t_map	*map;
} t_fdf;

// utils
void	ft_free_2d_array(int **array);
void	ft_swap(int *x1, int *x2);

t_point	*ft_new_point(int x, int y, t_fdf *fdf);

// parser map
t_map	*ft_create_map(char *filename);

// draw
void	ft_draw_line(t_fdf *fdf, t_point *p1, t_point *p2, int color);

// draw map
int		ft_draw_map(t_fdf *fdf);

//parser utils
int		ft_atohex(char *str);
int		ft_read_map_height(char *filename);
int		ft_read_map_width(char *filename);
void	ft_z_scale(t_map *map);

#endif
