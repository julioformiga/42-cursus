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

void	ft_draw_map(t_env env)
{
	t_point	dest;
	int		i;
	int		j;
	int		color;

	env.cursor_x = env.init.x;
	env.cursor_y = env.init.y;
	dest = (t_point){env.cursor_x + env.view.zoom, env.cursor_y};
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
			if (j < env.map.width && j > 0)
			{
				if (env.map.data[i][j] == 0 && env.map.data[i][j - 1] != 0)
					color = GREEN;
				dest = (t_point){
					env.cursor_x - env.view.zoom,
					env.cursor_y - (env.map.data[i][j - 1] * 2)
				};
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x,
					env.cursor_y - (env.map.data[i][j] * 2)},
					dest,
					color
					);
			}
			if (env.map.data[i][j] == 0)
				color = DARK_GRAY;
			else
				color = GREEN;
			if (i < env.map.height && i > 0)
			{
				if (env.map.data[i][j] == 0 && env.map.data[i - 1][j] != 0)
					color = GREEN;
				dest = (t_point){
					((env.cursor_x + env.view.zoom) - (env.view.angle * 2)),
					env.cursor_y - env.view.zoom - (env.map.data[i - 1][j] * 2)
				};
				ft_mlx_draw_line(&env,
					(t_point){env.cursor_x,
					env.cursor_y - (env.map.data[i][j] * 2)},
					dest,
					color
					);
			}
			env.cursor_x += env.view.zoom;
		}
		env.init.x -= env.view.angle;
		env.cursor_x = env.init.x;
		env.cursor_y += env.view.zoom + env.map.data[i][j + 1];
		env.init.y--;
	}
	env.cursor_x = env.init.x;
	env.cursor_y = env.init.y;
}

int	main(int argc, char **argv )
{
	t_env	env;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./fdf <file>\n", 2);
		exit(1);
	}
	env = ft_mlx_create_env(argv[1]);
	env.view.zoom = 27;
	env.view.angle = env.view.zoom / 3;
	env.init.x = (env.view.zoom * env.map.width) / 2;
	env.init.y = (env.view.zoom * env.map.height) / 2 + 80;
	ft_draw_map(env);
	ft_mlx_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}
