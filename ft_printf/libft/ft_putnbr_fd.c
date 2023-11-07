/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:43:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 20:43:48 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	char	*nbrs;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return (11);
	}
	nbrs = ft_itoa(n);
	if (nbrs == NULL)
	{
		free(nbrs);
		return (0);
	}
	count = ft_strlen(nbrs);
	write(fd, nbrs, count);
	free(nbrs);
	return (count);
}
