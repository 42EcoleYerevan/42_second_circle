#ifndef FDF_H
# define FDF_H

# define WIDTH 600
# define HEIGHT 600

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_map
{
	int	width;
	int	height;
	int	***array;
} t_map;

#endif
