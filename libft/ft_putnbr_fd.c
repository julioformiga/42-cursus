/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:02:17 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/18 20:02:19 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbrs;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		nbrs = ft_itoa(n);
		if (nbrs == NULL)
			return ;
		write(fd, nbrs, ft_strlen(nbrs));
		free(nbrs);
	}
}
