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
	int		w;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF 42 Firenze");
	mlx_hook(env.win, 2, 1L << 0, closewin, &env);
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
	i = 0;
	// while (i++ < WIN_HEIGHT)
	// {
	// 	w = -1;
	// 	while (w++ < WIN_WIDTH)
	// 		mlx_pixel_put(env.mlx, env.win,
	// 		w, i,
	// 		i * (WHITE / WIN_HEIGHT)
	// 		);
	// }
	mlx_loop(env.mlx);
	return (0);
}
