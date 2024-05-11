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

// static void	ft_mlx_create_point(t_env *env)
// {
// 	mlx_pixel_put(env->mlx, env->win, env->cursor_x, env->cursor_y, WHITE);
// }

int	ft_mlx_keypress(int keycode, t_env *env)
{
	if (keycode == XK_Escape || keycode == 'q')
		ft_mlx_destroy_window(env);
	if (keycode == 'w')
	{
		mlx_clear_window(env->mlx, env->win);
		env->view.zoom += 3;
		env->view.angle = env->view.zoom / 3;
		ft_draw_map(*env);
	}
	if (keycode == 's')
	{
		mlx_clear_window(env->mlx, env->win);
		env->view.zoom -= 3;
		env->view.angle = env->view.zoom / 3;
		ft_draw_map(*env);
	}
	if (keycode == XK_Up)
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.y -= 10;
		ft_draw_map(*env);
	}
	if (keycode == XK_Down)
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.y += 10;
		ft_draw_map(*env);
	}
	if (keycode == XK_Left || keycode == 'a')
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.x -= 10;
		ft_draw_map(*env);
	}
	if (keycode == XK_Right || keycode == 'd')
	{
		mlx_clear_window(env->mlx, env->win);
		env->init.x += 10;
		ft_draw_map(*env);
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
