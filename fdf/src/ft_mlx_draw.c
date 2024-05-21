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

static t_point	set_point(t_point begin, t_point end)
{
	t_point	point_s;

	point_s.x = -1;
	if (begin.x < end.x)
		point_s.x = 1;
	point_s.y = -1;
	if (begin.y < end.y)
		point_s.y = 1;
	return (point_s);
}

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

void	ft_mlx_draw_line(t_env *env, t_point begin, t_point end, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = abs(end.x - begin.x);
	d.y = -abs(end.y - begin.y);
	s = set_point(begin, end);
	err = d.x + d.y;
	e2 = 0;
	while (begin.x != end.x || begin.y != end.y)
	{
		mlx_pixel_put(env->mlx, env->win, begin.x, begin.y, color);
		e2 = 2 * err;
		if (e2 >= d.y)
		{
			err += d.y;
			begin.x += s.x;
		}
		if (e2 <= d.x)
		{
			err += d.x;
			begin.y += s.y;
		}
	}
}
