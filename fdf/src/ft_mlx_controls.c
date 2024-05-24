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
	ft_printf("Mouse: %d x: %d y: %d\n", button, x, y);
	if (button == 5)
		ft_mlx_keypress('w', env);
	if (button == 4)
		ft_mlx_keypress('s', env);
	return (0);
}

void	ft_mlx_hooks(t_env *env)
{
	mlx_hook(env->win, KeyPress, KeyPressMask, ft_mlx_keypress, env);
	mlx_hook(env->win, ButtonPress, ButtonPressMask, ft_mlx_mouse, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask,
		ft_mlx_destroy_window, env);
}

void	ft_mlx_map_zoom(t_env *env, char zoom)
{
	if (zoom == '+')
	{
		env->view.zoom += 2;
		env->init.x -= env->view.zoom / 2;
		env->init.y -= env->view.zoom / 2;
	}
	if (zoom == '-')
	{
		env->view.zoom -= 2;
		env->init.x += env->view.zoom / 2;
		env->init.y += env->view.zoom / 2;
	}
	env->view.angle = env->view.zoom / 2;
}

int	ft_mlx_keypress(int keycode, t_env *env)
{
	if (keycode == XK_Escape || keycode == 'q')
		ft_mlx_destroy_window(env);
	mlx_clear_window(env->mlx, env->win);
	if (keycode == 'w')
		ft_mlx_map_zoom(env, '+');
	if (keycode == 's' && env->view.zoom > 2)
		ft_mlx_map_zoom(env, '-');
	if (keycode == XK_Up || keycode == 'k')
		env->init.y -= 10;
	if (keycode == XK_Down || keycode == 'j')
		env->init.y += 10;
	if (keycode == XK_Left || keycode == 'h')
		env->init.x -= 10;
	if (keycode == XK_Right || keycode == 'l')
		env->init.x += 10;
	ft_map_draw(env);
	return (0);
}
