/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:44:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/15 19:44:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 43
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

char	*ft_strchr(const char *str, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);

char	*get_next_line(int fd);

#endif
