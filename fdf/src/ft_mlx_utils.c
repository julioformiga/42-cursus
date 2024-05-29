/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:39:04 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/05/14 17:39:04 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_free_array(int **ar)
{
	int	i;

	i = -1;
	while (i++, ar[i])
		free(ar[i]);
	free(ar);
}

void	ft_free_array_char(char **ar)
{
	int	i;

	i = -1;
	while (i++, ar[i])
		free(ar[i]);
	free(ar);
}

void	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_mlx_error("Opening file");
	close(fd);
}

int	ft_file_count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = -1;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (lines);
}
