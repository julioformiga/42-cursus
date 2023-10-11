/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:42:10 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/11 00:44:33 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*pdest;
	const char	*psrc;
	char		*tmp;

	pdest = dest;
	psrc = src;
	tmp = malloc(sizeof(char) * n);
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (i++, i < n)
		*(tmp + i) = *(psrc + i);
	i = -1;
	while (i++, i < n)
		*(pdest + i) = *(tmp + i);
	free(tmp);
	return (dest);
}
