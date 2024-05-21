/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 01:36:09 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/14 01:36:09 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_mlx_mouse(t_env *env, int button, int x, int y)
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

// static void	ft_mlx_create_point(t_env *env)
// {
// 	mlx_pixel_put(env.mlx, env.win, env.cursor_x, env.cursor_y, WHITE);
// }

int	ft_mlx_keypress(int keycode, t_env *env)
{
	if (keycode == XK_Escape || keycode == 'q')
		ft_mlx_destroy_window(env);
	if (keycode == 'w')
	{
		mlx_clear_window(env->mlx, env->win);
		env->view.zoom += 2;
		env->view.angle = env->view.zoom / 2;
		ft_map_draw(env);
	}
	if (keycode == 's' && env->view.zoom > 2)
	{
		mlx_clear_window(env->mlx, env->win);
		env->view.zoom -= 2;
		env->view.angle = env->view.zoom / 2;
		ft_map_draw(env);
	}
	if (keycode == XK_Up || keycode == 'k')
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.y -= 10;
		ft_map_draw(env);
	}
	if (keycode == XK_Down || keycode == 'j')
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.y += 10;
		ft_map_draw(env);
	}
	if (keycode == XK_Left || keycode == 'h')
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.x -= 10;
		ft_map_draw(env);
	}
	if (keycode == XK_Right || keycode == 'l')
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.x += 10;
		ft_map_draw(env);
	}
	return (0);
}
