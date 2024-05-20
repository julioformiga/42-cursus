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

void	ft_map_draw(t_env *env)
{
	int		i;
	int		j;

	env->cursor_x = env->init.x;
	env->cursor_y = env->init.y;
	i = -1;
	while (i++ < env->map.height - 1)
	{
		j = -1;
		while (j++ < env->map.width - 1)
		{
			if (j < env->map.width && j > 0)
				ft_mlx_draw_lines(env, 'h', i, j);
			if (i < env->map.height && i > 0)
				ft_mlx_draw_lines(env, 'v', i, j);
			env->cursor_x += env->view.zoom;
		}
		// env->init.x -= env->view.zoom;
		env->cursor_x = env->init.x;
		env->cursor_y += env->view.zoom;
		// env->cursor_y = env->view.zoom + env->map.data[i][j];
		// if (j < env->map.width)
		// 	env->cursor_y += env->view.zoom + env->map.data[i][j + 1];
		// else
		//  env->cursor_y += env->view.zoom;
		// env->init.y--;
	}
	ft_mlx_scale(env);
	// ft_mlx_xpm(env, "./image/header.xpm");
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
		if (!split)
		{
			perror("Error splitting line");
			close(fd);
			i = -1;
			while (i++, map.data[i])
				free(map.data[i]);
			free(map.data);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (split[i])
			i++;
		if (i == 0)
		{
			ft_putstr_fd("Error: Empty line\n", 2);
			exit(1);
		}
		if (map.width == 0)
			map.width = i;
		else if (map.width != i)
		{
			ft_putstr_fd("Error: Map is not rectangular\n", 2);
			exit(1);
		}
		map.data[map.height] = (int *)malloc((map.width + 1) * sizeof(int));
		i = -1;
		while (i++, i < map.width && split[i])
			map.data[map.height][i] = ft_atoi(split[i]);
		map.height++;
		i = -1;
		while (i++, split[i])
			free(split[i]);
		free(split);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
