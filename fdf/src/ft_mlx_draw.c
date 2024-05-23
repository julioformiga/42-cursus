/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:39:16 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/16 11:39:16 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		env->cursor_x = env->init.x;
		env->cursor_y += env->view.zoom;
	}
	ft_mlx_scale(env);
	ft_mlx_put_image(env);
}

void	ft_mlx_scale(t_env *env)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	while (i++, i < WIN_WIDTH)
	{
		x = 10;
		mlx_pixel_put(env->mlx, env->win, i, WIN_HEIGHT - 2, GRAY_DARK);
		mlx_pixel_put(env->mlx, env->win, i, WIN_HEIGHT - 1, GRAY_DARK);
		if (i % env->view.zoom > -2 && i % env->view.zoom < 2)
			while (x--, x > 2)
				mlx_pixel_put(env->mlx, env->win, i, WIN_HEIGHT - x, GRAY);
	}
	i = -1;
	while (i++, i < WIN_HEIGHT)
	{
		y = 10;
		mlx_pixel_put(env->mlx, env->win, 2, i, GRAY_DARK);
		mlx_pixel_put(env->mlx, env->win, 1, i, GRAY_DARK);
		if (i % env->view.zoom > -2 && i % env->view.zoom < 2)
			while (y--, y > 2)
				mlx_pixel_put(env->mlx, env->win, y, i, GRAY);
	}
}
