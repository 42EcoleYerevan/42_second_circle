#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "fdf.h"


int	ft_read_map_height(char *filename)
{
	int height;
	int fd;
	char *line;

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

int ft_read_map_width(char *filename)
{
	int width;
	char *line;
	int i;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	i = 0;
	width = 0;
	line = get_next_line(fd);
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	while ((line = get_next_line(fd)))
		free(line);
	close(fd);
	return (width);
}

int main(int argc, char **argv)
{
	int width;
	int height;
	if (argc > 1)
	{
		width = ft_read_map_width(argv[1]);
		height = ft_read_map_height(argv[1]);
		printf("width %d\n", width);
		printf("height %d\n", height);
	}
}
