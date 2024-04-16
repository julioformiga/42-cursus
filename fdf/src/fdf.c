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

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./fdf <file>\n", 2);
		exit(1);
	}
	env = ft_mlx_create_env();
	env.map = ft_parse_map(argv[1]);
	ft_mlx_hooks(&env);
	a.x = 430;
	a.y = 320;
	b.x = 550;
	b.y = 550;
	ft_mlx_draw_line(&env, a, b, WHITE);
	mlx_pixel_put(env.mlx, env.win, a.x, a.y, RED);
	mlx_pixel_put(env.mlx, env.win, b.x, b.y, RED);
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
