#include "fdf.h"

static int ft_hex(char c)
{
	int i;
	char base[] = "0123456789ABCDEF";

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

int ft_atohex(char *str)
{
	unsigned int out;

	out = 0;
	while (*str && *str != 'x' && *str != '\n')
		str++;
	if (*str == '\0' || *str == '\n')
		return (0);
	str++;
	while (*str && *str != '\n')
	{
		out = out * 16 + ft_hex(ft_toupper(*str));
		str++;
	}
	return (out);
}

int	ft_read_map_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	ft_read_map_width(char *filename)
{
	int		width;
	char	*line;
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	i = 0;
	width = 0;
	line = get_next_line(fd);
	while (line[i] != '\0' && line[i] != '\n')
		if (line[i++] != ' ')
			if (line[i] == ' ' || line[i] == '\0' || line[i] == '\n')
				width++;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (width);
}

void	ft_z_scale(t_map *map)
{
	int row;
	int col;
	int max;
	int min;

	min = map->array[0][0];
	max = map->array[0][0];
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->array[row][col] < min)
				min = map->array[row][col];
			if (map->array[row][col] > max)
				max = map->array[row][col];
			col++;
		}
		row++;
	}
	map->z_scale = max - min;
}
