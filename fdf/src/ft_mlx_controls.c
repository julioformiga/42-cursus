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

static void	ft_mlx_create_point(t_env *env)
{
	mlx_pixel_put(env->mlx, env->win, env->cursor_x, env->cursor_y, WHITE);
}

static void	ft_mlx_create_line(t_env *env, t_line line)
{
	t_point	l;

	l.x = line.p0.x;
	l.y = line.p0.y;
	while (l.x <= line.p1.x)
	{
		mlx_pixel_put(env->mlx, env->win, l.x, l.y, line.color);
		l.x++;
		l.y++;
	}
}

int	ft_mlx_keypress(int keycode, t_env *env)
{
	t_line	line;

	ft_mlx_create_line(env, line);
	if (keycode == XK_Escape || keycode == 'q')
		ft_mlx_destroy_window(env);
	if (keycode == XK_Up || keycode == 'w')
	{
		line.p0.x = 300;
		line.p0.y = 300;
		line.p1.x = 400;
		line.p1.y = 400;
		line.color = WHITE;
		ft_mlx_create_line(env, line);
		ft_mlx_create_point(env);
		env->cursor_y -= 10;
	}
	if (keycode == XK_Down || keycode == 's')
	{
		ft_mlx_create_point(env);
		env->cursor_y += 10;
	}
	if (keycode == XK_Left || keycode == 'a')
	{
		ft_mlx_create_point(env);
		env->cursor_x -= 10;
	}
	if (keycode == XK_Right || keycode == 'd')
	{
		ft_mlx_create_point(env);
		env->cursor_x += 10;
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
