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

int	ft_mlx_line_color(t_env *env, int i, int j, char type)
{
	t_color	color;
	t_range	r_in;
	t_range	r_out;
	int		c_color;

	r_in = (t_range){40, 255};
	r_out = (t_range){0, 10};
	color = (t_color){0, 40, 100, 40};
	if (j > 0 && env->map.data[i][j] == env->map.data[i][j - 1] && type == 'h')
		color.g = ft_map_value(r_in, r_out, env->map.data[i][j]);
	if (i > 0 && env->map.data[i][j] == env->map.data[i - 1][j] && type == 'v')
		color.g = ft_map_value(r_in, r_out, env->map.data[i][j]);
	c_color = ft_mlx_color(color);
	return (c_color);
}

void	ft_mlx_draw_lines(t_env *env, char type, int i, int j)
{
	t_point	dest;

	if (type == 'h' && j > 0)
	{
		dest = (t_point){
			env->cursor_x - env->view.zoom,
			env->cursor_y - (env->map.data[i][j - 1] * env->view.height)
		};
		ft_mlx_draw_line(env,
			(t_point){env->cursor_x,
			env->cursor_y - (env->map.data[i][j] * env->view.height)},
			dest, ft_mlx_line_color(env, i, j, 'h'));
	}
	if (type == 'v' && i > 0)
	{
		dest = (t_point){
			((env->cursor_x + env->view.zoom) - (env->view.angle * 2)),
			env->cursor_y - env->view.zoom
			- (env->map.data[i - 1][j] * env->view.height)
		};
		ft_mlx_draw_line(env,
			(t_point){env->cursor_x,
			env->cursor_y - (env->map.data[i][j] * env->view.height)},
			dest, ft_mlx_line_color(env, i, j, 'v'));
	}
}

void	ft_mlx_draw_line(t_env *env, t_point begin, t_point end, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;
	char	*dst;

	d.x = abs(end.x - begin.x);
	d.y = -abs(end.y - begin.y);
	s = set_point(begin, end);
	err = d.x + d.y;
	while (begin.x != end.x || begin.y != end.y)
	{
		dst = env->screen.addr + (begin.y * env->screen.line + begin.x
				* (env->screen.bpp / 8));
		*(unsigned int *)dst = color;
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
