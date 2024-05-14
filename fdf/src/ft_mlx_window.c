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

	env.mlx = mlx_init();
	if (!env.mlx)
	{
		ft_putstr_fd("Error\nmlx_init() failed\n", 2);
		exit(1);
	}
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!env.win)
	{
		free(env.win);
		ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
		exit(1);
	}
	env.map = ft_map_parse(file);
	env.cursor_x = WIN_WIDTH / 2;
	env.cursor_y = WIN_HEIGHT / 2;
	return (env);
}

int	ft_mlx_destroy_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	while (env->map.height--)
		free(env->map.data[env->map.height]);
	free(env->map.data);
	exit(EXIT_SUCCESS);
	return (0);
}
