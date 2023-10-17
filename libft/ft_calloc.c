/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:22:01 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/15 16:22:02 by julsanti         ###   ########.fr       */
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
