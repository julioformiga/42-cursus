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
	t_point	delta;
	int		pixels;

	delta.x = begin.x;
	delta.y = begin.y;
	pixels = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	ft_printf("pixels = %d\n", pixels);
	while (--pixels)
	{
		mlx_pixel_put(env->mlx, env->win, delta.x, delta.y, color);
		delta.x += (end.x - delta.x) / pixels;
		delta.y += (end.y - delta.y) / pixels;
	}
	return (0);
}
