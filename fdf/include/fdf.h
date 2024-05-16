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
// # define WIN_WIDTH 1024
// # define WIN_HEIGHT 768
# define WIN_WIDTH 1200
# define WIN_HEIGHT 800

# define BLACK 0
# define BLUE 255
# define GREEN_DARK 32768
# define GREEN 65280
# define CYAN 65535
# define GRAY 8421504
# define GRAY_DARK 2631720
# define RED 16711680
# define MAGENTA 16711935
# define YELLOW 16776960
# define WHITE 16777215

# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <unistd.h>
# include <time.h>
# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/minilibx/mlx.h"

typedef struct color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct map
{
	int		**data;
	int		width;
	int		height;
}	t_map;

typedef struct view
{
	int	zoom;
	int	angle;
}	t_view;

typedef struct point
{
	int	x;
	int	y;
}	t_point;

typedef struct env
{
	void	*mlx;
	void	*win;
	int		cursor_x;
	int		cursor_y;
	t_map	map;
	t_view	view;
	t_point	init;
}	t_env;

typedef struct line
{
	int		color;
	t_point	p0;
	t_point	p1;
}	t_line;

typedef struct range
{
	int	min;
	int	max;
}	t_range;

t_env	ft_mlx_create_env(char *file);
void	ft_mlx_hooks(t_env *env);
int		ft_mlx_keypress(int keycode, t_env *env);
int		ft_mlx_destroy_window(t_env *env);
int		ft_mlx_color(t_color color);
void	ft_mlx_draw_line(t_env *env, t_point p0, t_point p1, int color);
int		ft_map_value(t_range range_in, t_range range_out, int value);
void	ft_mlx_scale(t_env env);

void	ft_mlx_xpm(t_env *env, char *filename);
t_map	ft_map_parse(t_env env, char *file);
void	ft_map_draw(t_env env);

#endif
