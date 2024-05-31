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
	t_point	point;

	ft_bzero(env->screen.addr, WIN_WIDTH * WIN_HEIGHT * (env->screen.bpp / 8));
	i = -1;
	while (i++, i < env->map.height)
	{
		j = -1;
		while (j++, j < env->map.width)
		{
			point = ft_select_projection(j, i, env->map.data[i][j], env->view);
			env->cursor_x = env->init.x + point.x;
			env->cursor_y = env->init.y + point.y;
			if (j < env->map.width - 1)
				ft_mlx_draw_lines(env, 'h', i, j);
			if (i < env->map.height - 1)
				ft_mlx_draw_lines(env, 'v', i, j);
		}
	}
	ft_mlx_scale(env);
	mlx_put_image_to_window(env->mlx, env->win, env->screen.img, 0, 0);
	ft_mlx_put_image(env);
	mlx_do_sync(env->mlx);
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
		ft_draw_line_to_image(env, i, WIN_HEIGHT - 1, GREEN);
		if (i % (int)env->view.zoom > -2 && i % (int)env->view.zoom < 2)
			while (x--, x > 2)
				ft_draw_line_to_image(env, i, WIN_HEIGHT - x, GREEN_DARK);
	}
	i = -1;
	while (i++, i < WIN_HEIGHT)
	{
		y = 10;
		ft_draw_line_to_image(env, 1, i, GREEN);
		if (i % (int)env->view.zoom > -2 && i % (int)env->view.zoom < 2)
			while (y--, y > 2)
				ft_draw_line_to_image(env, y, i, GREEN_DARK);
	}
}
