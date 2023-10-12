/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 01:56:45 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/12 01:56:45 by julsanti         ###   ########.fr       */
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
