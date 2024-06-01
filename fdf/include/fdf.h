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
# define WIN_WIDTH 1280
# define WIN_HEIGHT 1024

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
# include <math.h>
# include <unistd.h>
# include <time.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../lib/ft_printf/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/.minilibx/mlx.h"

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	int		**data;
	int		width;
	int		height;
	int		min;
	int		max;
}	t_map;

typedef struct s_view
{
	int		projection;
	float	zoom;
	float	angle;
	float	angle_rotate;
	float	height;
	float	rotation_angle_x;
	float	rotation_angle_y;
	float	rotation_angle_z;
}	t_view;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point3d
{
	int	x;
	int	y;
	int	z;
}	t_point3d;

typedef struct s_size
{
	int	w;
	int	h;
}	t_size;

typedef struct s_img
{
	void	*img;
	t_size	size;
}	t_img;

typedef struct s_scr
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_scr;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		cursor_x;
	int		cursor_y;
	t_scr	screen;
	t_img	*imgs;
	t_map	map;
	t_view	view;
	t_point	init;
}	t_env;

typedef struct s_line
{
	int		color;
	t_point	p0;
	t_point	p1;
}	t_line;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

void		ft_check_file(char *file);
t_env		*ft_mlx_create_env(void);
void		ft_mlx_hooks(t_env *env);
int			ft_mlx_keypress(int keycode, t_env *env);
int			ft_mlx_destroy_window(t_env *env);
int			ft_mlx_color(t_color color);
void		ft_mlx_draw_line(t_env *env, t_point p0, t_point p1, int color);
int			ft_mlx_line_color(t_env *env, int i, int j, char type);
void		ft_draw_line_to_image(t_env *env, int x, int y, int color);
int			ft_map_value(t_range range_in, t_range range_out, int value);
void		ft_mlx_scale(t_env *env);
void		ft_mlx_info(t_env *env);
void		ft_mlx_draw_lines(t_env *env, char type, int i, int j);
t_point		ft_select_projection(int x, int y, int z, t_view view);
t_point		ft_iso_transform(int x, int y, int z, t_view view);
t_point		ft_parallel_transform(int x, int y, int z, t_view view);
t_point3d	ft_map_rotate3d(int x, int y, int z, t_view view);
void		ft_map_init(t_map *map, int n);

int			ft_file_count_lines(int fd);
void		ft_mlx_map_zoom(t_env *env, char zoom);
void		ft_free_array(int **ar);
void		ft_free_array_char(char **ar);
void		ft_mlx_xpm(t_env *env, char *filename);
t_map		ft_map_parse(char *file);
void		ft_map_draw(t_env *env);
void		ft_mlx_put_image(t_env *env);
void		ft_mlx_error(char *msg);

#endif
