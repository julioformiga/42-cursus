/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:49:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/04/05 11:49:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define BLACK 0
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define WHITE 16777215

# include <stdio.h>
# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/minilibx/mlx.h"

typedef struct s_env
{
	void	*mlx;
	void	*win;
}	t_env;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
}	t_line;

int	closewin(int keycode, t_env *env);
int	create_trgb(int t, int r, int g, int b);

#endif
