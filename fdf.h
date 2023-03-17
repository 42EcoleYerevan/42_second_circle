#ifndef FDF_H
# define FDF_H

# define WIDTH 1000
# define HEIGHT 600

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

typedef struct s_map
{
	int	width;
	int	height;
	int	scale;
	int sx;
	int sy;
	int	**array;
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

void	ft_free_2d_array(int **array);
void	ft_swap(int *x1, int *x2);
t_map	*ft_create_map(char *filename);
void	ft_draw_line(t_fdf *fdf, int x1, int y1, int x2, int y2, int color);
void	ft_put_pixel(t_fdf *fdf, int x, int y, int color);

#endif
