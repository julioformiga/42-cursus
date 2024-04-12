/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:48:07 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/05 11:48:07 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_env	env;
	int		i;

	env = ft_mlx_create_env();
	ft_mlx_hooks(&env);
	mlx_string_put(env.mlx, env.win, WIN_WIDTH / 2, WIN_HEIGHT / 2, RED,
		"42 Firenze");
	i = 0;
	while (i++ < 80)
	{
		mlx_pixel_put(env.mlx, env.win,
			(WIN_WIDTH / 2) - 10 + i, (WIN_HEIGHT / 2) + 2,
			GREEN
			);
	}
	mlx_loop(env.mlx);
	return (0);
}
