/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:53:59 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/13 10:53:59 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < size)
		len++;
	i = len;
	len--;
	while (len++, src[len - i] && (len + 1) < size)
		dst[len] = src[len - i];
	if (i < size)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}
