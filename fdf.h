#ifndef FDF_H
# define FDF_H

# define WIDTH 1200
# define HEIGHT 800


# ifdef __linux__

#  define KA 97
#  define KS 115
#  define KD 100
#  define KW 119
#  define KQ 113
#  define KZ 122
#  define KX 120 
#  define KY 99
#  define KT 116
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define ARROW_UP 65362
#  define ARROW_DOWN 65364
#  define PLUS 65451
#  define MINUS 65453

# else

#  define KA 0
#  define KS 1
#  define KD 2
#  define KW 13
#  define KQ 12
#  define KZ 6
#  define KX 7
#  define KY 8
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define ARROW_UP 126
#  define ARROW_DOWN 125
#  define PLUS 69
#  define MINUS 78

# endif


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

/* typedef struct s_point */
/* { */
/* 	int x; */
/* 	int y; */
/* 	int z; */
/* 	int w; */
/* } t_point; */

typedef struct s_map
{
	int	width;
	int	height;
	int sx;
	int sy;
	int scale;
	float xfi;
	float yfi;
	float coef;
	int z_scale;
	int z_min;
	int z_max;
	int	**array;
	int **colors;
} t_map;

typedef struct s_camera
{
	float position[3];
	float fov;
	float fovy;
	float n;
	float f;
	float aspect;
} t_camera;

typedef struct s_fdf
{
	void	*mlx;
	void	*window;
	void	*image;
	char 	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	int		istriangle;
	float	xfi;
	float	yfi;
	float	zfi;
	t_map	*map;
	t_camera *camera;
} t_fdf;


// utils
void	ft_free_2d_array(int **array);
void	ft_swap(int *x1, int *x2);
/* int	*ft_new_point(int x, int y, t_fdf *fdf); */

// parser map
t_map	*ft_create_map(char *filename);

// draw
void	ft_draw_line(t_fdf *fdf, int *p1, int *p2, int color);

// draw map
int		ft_draw_map(t_fdf *fdf);

//parser utils
int		ft_atohex(char *str);
int		ft_read_map_height(char *filename);
int		ft_read_map_width(char *filename);
void	ft_z_scale(t_map *map);

#endif
