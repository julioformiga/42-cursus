/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:07 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/14 17:28:07 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_mlx_line_color(t_env *env, int i, int j, char type)
{
	t_color	color;
	t_range	r_in;
	t_range	r_out;
	int		c_color;

	r_in = (t_range){40, 255};
	r_out = (t_range){0, 10};
	color = (t_color){0, 40, 100, 40};
	if (env->map.data[i][j] == env->map.data[i][j - 1] && type == 'h')
		color.g = ft_map_value(r_in, r_out, env->map.data[i][j]);
	if (env->map.data[i][j] == env->map.data[i - 1][j] && type == 'v')
		color.g = ft_map_value(r_in, r_out, env->map.data[i][j]);
	c_color = ft_mlx_color(color);
	return (c_color);
}

static void	ft_mlx_draw_lines(t_env env, char type, int i, int j)
{
	t_point	dest;

	if (type == 'h')
	{
		dest = (t_point){
			env.cursor_x - env.view.zoom,
			env.cursor_y - (env.map.data[i][j - 1] * 2)
		};
		ft_mlx_draw_line(&env,
			(t_point){env.cursor_x,
			env.cursor_y - (env.map.data[i][j] * 2)},
			dest, ft_mlx_line_color(&env, i, j, 'h'));
	}
	if (type == 'v')
	{
		dest = (t_point){
			((env.cursor_x + env.view.zoom) - (env.view.angle * 2)),
			env.cursor_y - env.view.zoom - (env.map.data[i - 1][j] * 2)
		};
		ft_mlx_draw_line(&env,
			(t_point){env.cursor_x,
			env.cursor_y - (env.map.data[i][j] * 2)},
			dest, ft_mlx_line_color(&env, i, j, 'v'));
	}
}

void	ft_map_draw(t_env env)
{
	int		i;
	int		j;

	env.cursor_x = env.init.x;
	env.cursor_y = env.init.y;
	i = -1;
	while (i++ < env.map.height - 1)
	{
		j = -1;
		while (j++ < env.map.width - 1)
		{
			if (j < env.map.width && j > 0)
				ft_mlx_draw_lines(env, 'h', i, j);
			if (i < env.map.height && i > 0)
				ft_mlx_draw_lines(env, 'v', i, j);
			env.cursor_x += env.view.zoom;
		}
		env.init.x -= env.view.angle;
		env.cursor_x = env.init.x;
		env.cursor_y += env.view.zoom + env.map.data[i][j + 1];
		env.init.y--;
	}
	ft_mlx_scale(env);
	ft_mlx_xpm(&env, "./image/header.xpm");
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
	env.view.zoom = 36;
	env.view.angle = env.view.zoom / 3;
	ft_printf("Angle: %d\n", env.view.angle);
	env.init.x = (env.view.zoom * env.map.width) / 2;
	env.init.y = (env.view.zoom * env.map.height) / 2;
	ft_printf("Init x: %d y: %d\n", env.init.x, env.init.y);
	ft_map_draw(env);
	ft_mlx_hooks(&env);
	mlx_loop(env.mlx);
	return (0);
}
