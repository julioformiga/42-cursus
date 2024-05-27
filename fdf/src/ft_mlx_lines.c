/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 02:24:18 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/23 02:24:18 by julio.formiga    ###   ########.fr       */
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

void	ft_draw_line_to_image(t_env *env, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = env->screen.addr
			+ (y * env->screen.line + x * (env->screen.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_mlx_draw_lines(t_env *env, char type, int i, int j)
{
	t_point	start;
	t_point	dest;

	start = ft_iso_transform(j, i, env->map.data[i][j], env->view);
	start.x += env->init.x;
	start.y += env->init.y;
	if (type == 'h' && j < env->map.width - 1)
	{
		dest = ft_iso_transform(j + 1, i, env->map.data[i][j + 1], env->view);
		dest.x += env->init.x;
		dest.y += env->init.y;
		ft_mlx_draw_line(env, start, dest, ft_mlx_line_color(env, i, j, 'h'));
	}
	if (type == 'v' && i < env->map.height - 1)
	{
		dest = ft_iso_transform(j, i + 1, env->map.data[i + 1][j], env->view);
		dest.x += env->init.x;
		dest.y += env->init.y;
		ft_mlx_draw_line(env, start, dest, ft_mlx_line_color(env, i, j, 'v'));
	}
}

void	ft_mlx_draw_line(t_env *env, t_point begin, t_point end, int color)
{
	t_point	d;
	t_point	s;
	int		e2;
	int		err;

	d.x = abs(end.x - begin.x);
	d.y = -abs(end.y - begin.y);
	s = set_point(begin, end);
	err = d.x + d.y;
	while (begin.x != end.x || begin.y != end.y)
	{
		ft_draw_line_to_image(env, begin.x, begin.y, color);
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
