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

#include "get_next_line.h"

static char	*fill_line_buffer(int fd, char *left_char, char *buffer)
{
	ssize_t	buffer_read;
	char	*tmp;

	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(left_char);
			return (NULL);
		}
		if (buffer_read == 0)
			break ;
		buffer[buffer_read] = 0;
		if (!left_char)
			left_char = ft_strdup("");
		tmp = left_char;
		left_char = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_char);
}

static char	*set_line(char *line_buffer)
{
	char	*left_chars;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != 0)
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_chars = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*left_chars == 0)
	{
		free(left_chars);
		left_chars = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_chars);
}

char	*get_next_line(int fd)
{
	static char	*left_chars;
	char		*line;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(left_chars);
		buffer = NULL;
		left_chars = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, left_chars, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_chars = set_line(line);
	return (line);
}

/* int	main(void) */
/* { */
/* 	int		fd; */
/* 	int		lines; */
/* 	char	*line; */
/*  */
/* 	lines = 1; */
/* 	fd = open("./example.txt", O_RDONLY); */
/* 	line = get_next_line(fd); */
/* 	while (line) */
/* 	{ */
/* 		printf("%2d: %s", lines++, line); */
/* 		free(line); */
/* 		line = get_next_line(fd); */
/* 	} */
/* 	close(fd); */
/* 	return (0); */
/* } */
