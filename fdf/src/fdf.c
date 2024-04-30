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
	color = 0;
	while (i++ < WIN_HEIGHT - 1)
	{
		mlx_pixel_put(env.mlx, env.win, env.map.width, i, color += (1024 * 64));
		if (i % 30 == 0)
			mlx_string_put(env.mlx, env.win, env.map.width + 10, i, color, "Color");
	}
	i = -1;
	while (i++ < env.map.height - 1)
	{
		j = -1;
		while (j++ < env.map.width - 1)
		{
			if (env.map.data[i][j] == 0)
				color = DARK_GRAY;
			else
				color = GREEN;
			mlx_pixel_put(env.mlx, env.win, env.cursor_x, env.cursor_y, color);
			if (j < env.map.width && j > 0)
			{
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x, env.cursor_y},
					(t_point){env.cursor_x - env.view.distance, env.cursor_y},
					color
					);
			}
			if (i < env.map.height && i > 0)
			{
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x, env.cursor_y},
					(t_point){
					((env.cursor_x + env.view.distance) - (env.view.angle * 2)),
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
	init.x = (env.view.distance * env.map.width) / 3;
	init.y = (env.view.distance * env.map.height) / 2;
	env.cursor_x = init.x;
	env.cursor_y = init.y;
	i = -1;
	while (i++ < env.map.height - 1)
	{
		j = -1;
		while (j++ < env.map.width - 1)
		{
			mlx_pixel_put(env.mlx, env.win, env.cursor_x, env.cursor_y, WHITE);
			env.cursor_x += env.view.distance;
		}
		init.x -= env.view.angle;
		env.cursor_x = init.x;
		env.cursor_y += env.view.distance;
		init.y--;
	}
	ft_mlx_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}
