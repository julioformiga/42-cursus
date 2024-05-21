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

void	ft_mlx_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_map_value(t_range range_in, t_range range_out, int value)
{
	return (range_in.min
		+ ((range_in.max - range_in.min) / (range_out.max - range_out.min))
		* (value - range_out.min));
}

void	ft_free_array(int **ar)
{
	int	i;

	i = -1;
	while (i++, ar[i])
		free(ar[i]);
	free(ar);
}

void	ft_free_array_char(char **ar)
{
	int	i;

	i = -1;
	while (i++, ar[i])
		free(ar[i]);
	free(ar);
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
