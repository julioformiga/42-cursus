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
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	mlx = mlx_new_window(mlx, 800, 600, "Hello, World!");
	mlx_loop(mlx);
	return (0);
}
