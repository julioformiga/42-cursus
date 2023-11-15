/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:53:26 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 19:53:32 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (count++, *s)
		write(fd, s++, 1);
	count--;
	return (count);
}
