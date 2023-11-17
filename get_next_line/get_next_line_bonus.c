/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:03:03 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/15 21:03:03 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c[MAX_FD];
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = fill_line_buffer(fd, left_c[fd], buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_c[fd] = set_line(line);
	return (line);
}

/* int	main(void) */
/* { */
/* 	int		fd; */
/* 	int		lines; */
/* 	char	*line; */
/*  */
/* 	lines = 0; */
/* 	fd = open("./example.txt", O_RDONLY); */
/* 	while ((line = get_next_line(fd))) */
/* 	{ */
/* 		printf("%d -> %s\n", lines++, line); */
/* 		free(line); */
/* 	} */
/* 	free(line); */
/* 	close(fd); */
/* 	return (0); */
/* } */
