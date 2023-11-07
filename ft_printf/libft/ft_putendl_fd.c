/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:06:33 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 20:06:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s || !fd)
		return (count);
	while (*s)
	{
		write(fd, s++, 1);
		count++;
	}
	write(fd, "\n", 1);
	return (count);
}
