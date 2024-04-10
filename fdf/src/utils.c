/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:13:34 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/10 16:13:34 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closewin(int keycode, t_env *env)
{
	if (keycode == 'q' || keycode == 65307)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

void	ft_put_line(t_data *data, t_line line, int color1, int color2)
{

}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

