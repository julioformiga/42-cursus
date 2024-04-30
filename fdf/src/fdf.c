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
	t_point	init;
	int		i;
	int		j;
	int		color;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./fdf <file>\n", 2);
		exit(1);
	}
	env = ft_mlx_create_env(argv[1]);
	env.view.angle = 10;
	env.view.distance = 30;
	init.x = (env.view.distance * env.map.width) / 3;
	init.y = (env.view.distance * env.map.height) / 2;
	env.cursor_x = init.x;
	env.cursor_y = init.y;
	ft_printf("x = %d, y = %d\n", env.cursor_x, env.cursor_y);
	ft_printf("width = %d, height = %d\n", env.map.width, env.map.height);
	i = -1;
	color = WHITE;
	while (i++ < env.map.height - 1)
	{
		j = -1;
		while (j++ < env.map.width - 1)
		{
			if (env.map.data[i][j] == 0)
				color = GRAY;
			else
				color = GREEN;
			mlx_pixel_put(env.mlx, env.win, env.cursor_x, env.cursor_y, color);
			if (j > 0)
			{
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x, env.cursor_y},
					(t_point){env.cursor_x - env.view.distance, env.cursor_y},
					color
					);
			}
			if (i > 0)
			{
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x, env.cursor_y},
					(t_point){
					((env.cursor_x + env.view.distance) - env.view.angle * 2),
					env.cursor_y - env.view.distance
				},
					color
					);
			}
			env.cursor_x += env.view.distance;
			ft_printf("%3d ", env.map.data[i][j]);
		}
		init.x -= env.view.angle;
		env.cursor_x = init.x;
		env.cursor_y += env.view.distance;
		init.y--;
		ft_printf("\n");
	}
	ft_mlx_hooks(&env);
	// i = 0;
	// while (i++ < 80)
	// {
	// 	mlx_pixel_put(env.mlx, env.win,
	// 		(WIN_WIDTH / 2) - 10 + i, (WIN_HEIGHT / 2) + 2,
	// 		GREEN
	// 		);
	// }
	// i = 0;
	// while (i++ < 400)
	// {
		// a.x = 130; a.y = 20; b.x = 550 + i; b.y = 550;
		// ft_mlx_draw_line(&env, a, b, WHITE);
		// mlx_pixel_put(env.mlx, env.win, a.x, a.y, RED);
		// mlx_pixel_put(env.mlx, env.win, b.x, b.y, RED);
		// usleep(50000);
		// ft_mlx_draw_line(&env, a, b, BLACK);
		// mlx_pixel_put(env.mlx, env.win, a.x, a.y, BLACK);
		// mlx_pixel_put(env.mlx, env.win, b.x, b.y, BLACK);
	// }
	mlx_loop(env.mlx);
	return (0);
}
