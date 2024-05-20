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

t_env	*ft_mlx_create_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
	{
		ft_putstr_fd("Error\nmalloc() failed\n", 2);
		exit(1);
	}
	env->mlx = mlx_init();
	if (!env->mlx)
	{
		ft_putstr_fd("Error\nmlx_init() failed\n", 2);
		exit(1);
	}
	env->win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (!env->win)
	{
		ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
		exit(1);
	}
	env->view.zoom = 36;
	env->view.angle = env->view.zoom / 2;
	env->cursor_x = WIN_WIDTH / 2;
	env->cursor_y = WIN_HEIGHT / 2;
	env->init = (t_point){0, 0};
	// env->cursor_x = (env->view.zoom * env->map.width) / 2;
	// env->cursor_y = (env->view.zoom * env->map.height) / 2;
	return (env);
}

int	ft_mlx_destroy_window(t_env *env)
{
	if (env->mlx)
	{
		// if (env->img)
		// 	mlx_destroy_image(env->mlx, env->img);
		if (env->win)
			mlx_destroy_window(env->mlx, env->win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		while (env->map.height--)
			free(env->map.data[env->map.height]);
		free(env->map.data);
		free(env);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
