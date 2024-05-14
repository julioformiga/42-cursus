/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:39:04 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/14 17:39:04 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_map_value(t_range range_in, t_range range_out, int value)
{
	return (range_in.min
		+ ((range_in.max - range_in.min) / (range_out.max - range_out.min))
		* (value - range_out.min));
}

void	ft_mlx_scale(t_env env)
{
	t_color	color;
	int		i;
	int		y;

	i = -1;
	color = (t_color){0, 100, 100, 100};
	while (i++, i < WIN_WIDTH)
	{
		y = 15;
		color.g++;
		if (color.g > 255)
			color.g = 100;
		mlx_pixel_put(env.mlx, env.win, i, 10, ft_mlx_color(color));
		if (i % 100 > -2 && i % 100 < 2)
			while (y++, y < 40)
				mlx_pixel_put(env.mlx, env.win, i, y, WHITE);
	}
}
