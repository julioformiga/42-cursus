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
#include <unistd.h>

void	ft_map_draw(t_env env)
{
	t_point	dest;
	t_color	color;
	int		i;
	int		j;
	int		c_color;

	env.cursor_x = env.init.x;
	env.cursor_y = env.init.y;
	dest = (t_point){env.cursor_x + env.view.zoom, env.cursor_y};
	i = -1;
	color = (t_color){0, 100, 255, 100};
	while (i++ < env.map.height - 1)
	{
		j = -1;
		while (j++ < env.map.width - 1)
		{
			color.g = 255;
			if (env.map.data[i][j] == 0)
				color.g = 100;
			if (j < env.map.width && j > 0)
			{
				if (env.map.data[i][j] == 0 && env.map.data[i][j - 1] != 0)
					color.g = 255;
				c_color = ft_mlx_color(color);
				dest = (t_point){
					env.cursor_x - env.view.zoom,
					env.cursor_y - (env.map.data[i][j - 1] * 2)
				};
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x,
					env.cursor_y - (env.map.data[i][j] * 2)},
					dest, c_color);
			}
			if (env.map.data[i][j] == 0)
				color.g = 100;
			if (i < env.map.height && i > 0)
			{
				if (env.map.data[i][j] == 0 && env.map.data[i - 1][j] != 0)
					color.g = 255;
				c_color = ft_mlx_color(color);
				dest = (t_point){
					((env.cursor_x + env.view.zoom) - (env.view.angle * 2)),
					env.cursor_y - env.view.zoom - (env.map.data[i - 1][j] * 2)
				};
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x,
					env.cursor_y - (env.map.data[i][j] * 2)},
					dest, c_color);
			}
			env.cursor_x += env.view.zoom;
		}
		env.init.x -= env.view.angle;
		env.cursor_x = env.init.x;
		env.cursor_y += env.view.zoom + env.map.data[i][j + 1];
		env.init.y--;
	}
}

int	main(int argc, char **argv )
{
	t_env	env;
	t_color	color;
	int		i;
	int		y;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./fdf <file>\n", 2);
		exit(1);
	}
	env = ft_mlx_create_env(argv[1]);
	env.view.zoom = 36;
	env.view.angle = env.view.zoom / 3;
	ft_printf("Angle: %d\n", env.view.angle);
	env.init.x = (env.view.zoom * env.map.width) / 2;
	env.init.y = (env.view.zoom * env.map.height) / 2;
	ft_printf("Init x: %d y: %d\n", env.init.x, env.init.y);
	ft_map_draw(env);
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
	ft_mlx_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}
