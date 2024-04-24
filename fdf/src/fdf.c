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

int	main(int argc, char **argv )
{
	t_env	env;
	t_point	a;
	t_point	b;
	int		i;
	int		j;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./fdf <file>\n", 2);
		exit(1);
	}
	env = ft_mlx_create_env(argv[1]);
	i = -1;
	while (i++ < env.map.height - 1)
	{
		j = -1;
		while (j++ < env.map.width - 1)
			ft_printf("%3d ", env.map.data[i][j]);
		ft_printf("\n");
	}
	ft_mlx_hooks(&env);
	mlx_string_put(env.mlx, env.win, WIN_WIDTH / 2, WIN_HEIGHT / 2, RED,
		"FdF Project - 42 Firenze");
	i = 0;
	while (i++ < 80)
	{
		mlx_pixel_put(env.mlx, env.win,
			(WIN_WIDTH / 2) - 10 + i, (WIN_HEIGHT / 2) + 2,
			GREEN
			);
	}
	// i = 0;
	// while (i++ < 400)
	// {
		a.x = 130; a.y = 20; b.x = 550 + i; b.y = 550;
		ft_mlx_draw_line(&env, a, b, WHITE);
		mlx_pixel_put(env.mlx, env.win, a.x, a.y, RED);
		mlx_pixel_put(env.mlx, env.win, b.x, b.y, RED);
		// usleep(50000);
		// ft_mlx_draw_line(&env, a, b, BLACK);
		// mlx_pixel_put(env.mlx, env.win, a.x, a.y, BLACK);
		// mlx_pixel_put(env.mlx, env.win, b.x, b.y, BLACK);
	// }
	mlx_loop(env.mlx);
	return (0);
}
