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

int	ft_mlx_draw_line(t_env *env, t_point begin, t_point end, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = abs(end.x - begin.x);
	d.y = -abs(end.y - begin.y);
	s.x = -1;
	if (begin.x < end.x)
		s.x = 1;
	s.y = -1;
	if (begin.y < end.y)
		s.y = 1;
	err = d.x + d.y;
	e2 = 0;
	while (1)
	{
		mlx_pixel_put(env->mlx, env->win, begin.x, begin.y, color);
		if (begin.x == end.x && begin.y == end.y)
			break ;
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
	return (0);
}

int	ft_mlx_draw_line_old(t_env *env, t_point begin, t_point end, int color)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = begin.x;
	deltay = begin.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	ft_printf("pixels = %d\n", pixels);
	while (--pixels)
	{
		mlx_pixel_put(env->mlx, env->win, deltax, deltay, color);
		deltax += (end.x - deltax) / pixels;
		deltay += (end.y - deltay) / pixels;
	}
	return (0);
}
