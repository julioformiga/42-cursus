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

t_map	ft_parse_map(char *file)
{
	t_map	map;
	int		fd;
	char	*line;
	char	**split;
	int		i;

	fd = ft_read_file(file);
	map.width = 0;
	map.height = 0;
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
		map.height++;
		while (i--)
			free(split[i]);
		free(split);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
