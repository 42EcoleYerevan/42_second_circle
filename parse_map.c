/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:44:52 by agladkov          #+#    #+#             */
/*   Updated: 2023/03/12 13:53:15 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	*ft_parse_line(char *str, int width)
{
	int		n;
	int		*array;
	char	**tmp;

	array = (int *)malloc(sizeof(int) * width);
	if (!array)
		return (NULL);
	tmp = ft_split(str, ' ');
	n = 0;
	while (n < width)
	{
		array[n] = ft_atoi(tmp[n]);
		n++;
	}
	return (array);
}

int	**ft_fill_array(int fd, int width, int height)
{
	int		i;
	int		**array;
	char	*line;

	array = (int **)malloc(sizeof(int *) * height);
	if (!array)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		array[i] = ft_parse_line(line, width);
		if (!array[i++])
		{
			free(line);
			ft_free_2d_array(array);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (array);
}

t_map	*ft_create_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	map = (t_map *)malloc(sizeof(t_map));
	if (fd < 0 || !map)
		return (NULL);
	map->width = ft_read_map_width(filename);
	map->height = ft_read_map_height(filename);
	map->array = ft_fill_array(fd, map->width, map->height);
	if (!map->array)
		return (NULL);
	return (map);
}

/* int	main(int argc, char **argv) */
/* { */
/* 	t_map	*map; */
/* 	if (argc > 1) */
/* 	{ */
/* 		map = ft_create_map(argv[1]); */
/* 	} */
/* 	for (int row = 0; row < map->height; row++) */
/* 	{ */
/* 		for (int col = 0;  col < map->width; col++) */
/* 			printf("%d ", map->array[row][col]); */
/* 		printf("\n"); */
/* 	} */
/* } */
