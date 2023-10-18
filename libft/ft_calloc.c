/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:12:12 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 20:13:19 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	total_size;

	total_size = nmemb * size;
	pos = malloc(total_size);
	if (!pos || total_size > INT_MAX)
		return (NULL);
	ft_memset(pos, 0, total_size);
	return ((void *)pos);
}
