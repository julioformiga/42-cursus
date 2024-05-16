/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:35:05 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/14 01:35:05 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	ft_mlx_create_env(char *file)
{
	t_env	env;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nopen() failed\n", 2);
		exit(1);
	}
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!env.win || !env.mlx)
	{
		ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
		exit(1);
	}
	env.map = ft_map_parse(env, file);
	env.cursor_x = WIN_WIDTH / 2;
	env.cursor_y = WIN_HEIGHT / 2;
	return (env);
}

int	ft_mlx_destroy_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
