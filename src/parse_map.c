/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <agladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:44:52 by agladkov          #+#    #+#             */
/*   Updated: 2023/04/22 14:25:13 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../fdf.h"
#include "../libft/libft.h"

static int	*ft_parse_line(char *str, int width)
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

static int	*ft_parse_colors(char *str, int width)
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
		array[n] = ft_atohex(tmp[n]);
		n++;
	}
	return (array);
}

static int	**ft_fill_array(int fd, int width, int height)
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
			ft_free_2d_array_with_null(array);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (array);
}

static int	**ft_fill_colors(int fd, int width, int height)
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
		array[i] = ft_parse_colors(line, width);
		if (!array[i++])
		{
			free(line);
			ft_free_2d_array_with_null(array);
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
	if (fd < 0 || read(fd, 0, 0) < 0 || !map)
		return (NULL);
	map->width = ft_read_map_width(filename);
	map->height = ft_read_map_height(filename);
	map->array = ft_fill_array(fd, map->width, map->height);
	close(fd);
	fd = open(filename, O_RDONLY);
	map->colors = ft_fill_colors(fd, map->width, map->height);
	ft_z_scale(map);
	if (!map->array || !map->colors)
		return (NULL);
	return (map);
}

