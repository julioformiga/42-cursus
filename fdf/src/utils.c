/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:13:34 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/10 16:13:34 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	ft_mlx_create_env(void)
{
	t_env	env;

	env.mlx = mlx_init();
	if (!env.mlx)
	{
		ft_putstr_fd("Error\nmlx_init() failed\n", 2);
		exit(1);
	}
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF 42 Firenze");
	if (!env.win)
	{
		free(env.win);
		ft_putstr_fd("Error\nmlx_new_window() failed\n", 2);
		exit(1);
	}
	return (env);
}

static int	ft_mlx_mouse(int button, int x, int y, t_env *env)
{
	(void)env;
	ft_printf("Mouse: %d x: %d y: %d\n", button, x, y);
	return (0);
}

void	ft_mlx_hooks(t_env *env)
{
	mlx_hook(env->win, KeyPress, KeyPressMask, ft_mlx_keypress, env);
	mlx_hook(env->win, ButtonPress, ButtonPressMask, ft_mlx_mouse, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask,
		ft_mlx_destroy_window, env);
}

int	ft_mlx_keypress(int keycode, t_env *env)
{
	if (keycode == XK_Escape || keycode == 'q')
		ft_mlx_destroy_window(env);
	if (keycode == XK_Up || keycode == 'w')
		ft_printf("Keycode: %d\n", keycode);
	return (0);
}

int	ft_mlx_destroy_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
