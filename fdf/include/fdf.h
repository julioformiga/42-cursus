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
# define WIN_TITLE "FdF"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define BLACK 0
# define BLUE 255
# define GREEN 65280
# define RED 16711680
# define WHITE 16777215

# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/minilibx/mlx.h"

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	int		cursor_x;
	int		cursor_y;
	t_map	map;
}	t_env;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_line
{
	int		color;
	t_point	p0;
	t_point	p1;
}	t_line;

t_env	ft_mlx_create_env(void);
void	ft_mlx_hooks(t_env *env);
int		ft_mlx_keypress(int keycode, t_env *env);
int		ft_mlx_destroy_window(t_env *env);
int		create_trgb(int t, int r, int g, int b);
int		ft_mlx_draw_line(t_env *env, t_point p0, t_point p1, int color);

t_map	ft_parse_map(char *file);

#endif
