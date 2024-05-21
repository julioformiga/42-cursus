/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 03:53:30 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/17 03:53:30 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = -1;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (lines);
}

static void	ft_check_map_parse(char **split, t_map *map)
{
	int	i;

	i = 0;
	if (!split)
	{
		ft_free_array(map->data);
		ft_mlx_error("Error splitting line\n");
	}
	i = 0;
	while (split[i])
		i++;
	if (i == 0)
		ft_mlx_error("Empty line\n");
	if (map->width == 0)
		map->width = i;
	else if (map->width != i)
	{
		ft_free_array(map->data);
		ft_free_array_char(split);
		ft_mlx_error("Map is not rectangular\n");
	}
}

static void	ft_map_fill_values(t_map *map, char **split)
{
	int		i;

	i = -1;
	while (i++, i < map->width && split[i])
		map->data[map->height][i] = ft_atoi(split[i]);
	map->height++;
	ft_free_array_char(split);
}

t_map	ft_map_parse(char *file)
{
	t_map	map;
	int		fd;
	char	*line;
	char	**split;
	int		i;

	map.width = 0;
	map.height = 0;
	i = ft_count_lines(open(file, O_RDONLY)) + 1;
	fd = open(file, O_RDONLY);
	map.data = (int **)malloc(i * sizeof(int *));
	memset(map.data, 0, i * sizeof(int *));
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		free(line);
		ft_check_map_parse(split, &map);
		map.data[map.height] = (int *)malloc((map.width + 1) * sizeof(int));
		ft_map_fill_values(&map, split);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
