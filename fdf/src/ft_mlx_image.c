/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:44:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/15 13:44:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_xpm(t_env *env, char *filename)
{
	void	*img;
	int		x_init;
	t_point	size;

	size = (t_point){340, 115};
	x_init = (WIN_WIDTH / 2) - (size.x / 2);
	img = mlx_xpm_file_to_image(env->mlx, filename, &size.x, &size.y);
	mlx_xpm_to_image(env->mlx, img, &size.x, &size.y);
	mlx_put_image_to_window(env->mlx, env->win, img, x_init, 0);
	mlx_do_sync(env->mlx);
}
