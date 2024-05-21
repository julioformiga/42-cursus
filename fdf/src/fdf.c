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

int	ft_mlx_line_color(t_env *env, int i, int j, char type)
{
	t_color	color;
	t_range	r_in;
	t_range	r_out;
	int		c_color;

	r_in = (t_range){40, 255};
	r_out = (t_range){0, 10};
	color = (t_color){0, 40, 100, 40};
	if (j > 0 && env->map.data[i][j] == env->map.data[i][j - 1] && type == 'h')
		color.g = ft_map_value(r_in, r_out, env->map.data[i][j]);
	if (i > 0 && env->map.data[i][j] == env->map.data[i - 1][j] && type == 'v')
		color.g = ft_map_value(r_in, r_out, env->map.data[i][j]);
	c_color = ft_mlx_color(color);
	return (c_color);
}

void	ft_mlx_draw_lines(t_env *env, char type, int i, int j)
{
	t_point	dest;

	if (type == 'h' && j > 0)
	{
		dest = (t_point){
			env->cursor_x - env->view.zoom,
			env->cursor_y - (env->map.data[i][j - 1] * 2)
		};
		ft_mlx_draw_line(env,
			(t_point){env->cursor_x,
			env->cursor_y - (env->map.data[i][j] * 2)},
			dest, ft_mlx_line_color(env, i, j, 'h'));
	}
	if (type == 'v' && i > 0)
	{
		dest = (t_point){
			((env->cursor_x + env->view.zoom) - (env->view.angle * 2)),
			env->cursor_y - env->view.zoom - (env->map.data[i - 1][j] * 2)
		};
		ft_mlx_draw_line(env,
			(t_point){env->cursor_x,
			env->cursor_y - (env->map.data[i][j] * 2)},
			dest, ft_mlx_line_color(env, i, j, 'v'));
	}
}

static void	int_handler(int _)
{
	(void)_;
	ft_printf("\b\bPress 'q' or 'ESC'\n");
}

int	main(int argc, char **argv)
{
	t_env	*env;

	signal (SIGINT, int_handler);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./fdf <file>\n", 2);
		exit(1);
	}
	env = ft_mlx_create_env();
	env->map = ft_map_parse(argv[1]);
	env->init.x = (env->view.zoom * env->map.width) / 2;
	env->init.y = (env->view.zoom * env->map.height) / 2;
	ft_map_draw(env);
	ft_mlx_hooks(env);
	mlx_loop(env->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
