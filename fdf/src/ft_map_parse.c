/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:59:54 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/22 01:59:54 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_map_value(t_range range_in, t_range range_out, int value)
{
	if (range_out.max - range_out.min == 0)
		range_out.max = range_out.min + 1;
	return (range_in.min
		+ ((range_in.max - range_in.min) / (range_out.max - range_out.min))
		* (value - range_out.min));
}

static int	ft_check_map_parse(t_map *map, char **split)
{
	int	i;

	if (!split)
	{
		ft_free_array(map->data);
		ft_mlx_error("Splitting line\n");
	}
	i = 0;
	while (split[i] && ft_isprint(split[i][0]))
		i++;
	if (i == 0)
		ft_mlx_error("Empty line\n");
	if (map->width == 0)
		map->width = i;
	else if (map->width != i)
		return (0);
	map->data[map->height] = (int *)malloc((i + 1) * sizeof(int));
	return (1);
}

static void	ft_map_fill_values(t_map *map, char **split)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (i++, i < map->width && split[i])
	{
		n = ft_atoi(split[i]);
		map->data[map->height][i] = n;
		if (n > map->max)
			map->max = n;
		if (n < map->min)
			map->min = n;
	}
	map->height++;
	ft_free_array_char(split);
}

static void	ft_check_map_error(t_map *map, char **split, char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_free_array_char(split);
	ft_free_array(map->data);
	close(fd);
	ft_mlx_error("Map is not rectangular\n");
}

t_map	ft_map_parse(char *file)
{
	t_map	map;
	int		fd;
	char	*line;
	char	**split;

	ft_map_init(&map, ft_file_count_lines(open(file, O_RDONLY)) + 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		if (!ft_check_map_parse(&map, split))
			ft_check_map_error(&map, split, line, fd);
		free(line);
		ft_map_fill_values(&map, split);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
