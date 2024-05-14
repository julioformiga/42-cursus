/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:51:23 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/15 13:51:23 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_read_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nopen() failed\n", 2);
		exit(1);
	}
	return (fd);
}

static int	ft_count_lines(char *file)
{
	int		fd;
	char	*line;
	int		lines;

	fd = ft_read_file(file);
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

t_map	ft_map_parse(char *file)
{
	t_map	map;
	int		fd;
	char	*line;
	char	**split;
	int		i;

	map.width = 0;
	map.height = 0;
	map.data = (int **)malloc((ft_count_lines(file) + 1) * sizeof(int *));
	fd = ft_read_file(file);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		i = 0;
		while (split[i])
			i++;
		if (map.width == 0)
			map.width = i;
		else if (map.width != i)
		{
			ft_putstr_fd("Error: Map is not rectangular\n", 2);
			exit(1);
		}
		map.data[map.height] = (int *)malloc((map.width + 1) * sizeof(int));
		i = -1;
		while (i++ < map.width && split[i])
			map.data[map.height][i] = ft_atoi(split[i]);
		map.height++;
		i = map.width;
		while (i--)
			free(split[i]);
		free(split);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	free(line);
	close(fd);
	return (map);
}
