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

int	main(int argc, char **argv)
{
	t_env	*env;
	t_map	map;

	if (argc != 2)
		ft_mlx_error("Usage: ./fdf <file>");
	ft_check_file(argv[1]);
	map = ft_map_parse(argv[1]);
	env = ft_mlx_create_env();
	env->map = map;
	env->screen.img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->screen.addr = mlx_get_data_addr(env->screen.img,
			&env->screen.bpp, &env->screen.line, &env->screen.endian);
	env->view.zoom = WIN_WIDTH / env->map.width / 2;
	if (env->view.zoom % 2)
		env->view.zoom++;
	env->view.angle = env->view.zoom / 2;
	env->view.height = 0;
	env->init.x = (WIN_WIDTH / 2) - (env->view.zoom * (env->map.width - 1)) / 2;
	env->init.y = (WIN_HEIGHT / 2) - (env->view.zoom * env->map.height) / 2;
	ft_map_draw(env);
	ft_mlx_hooks(env);
	mlx_loop(env->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
