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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size <= 0)
		return (len_src);
	i = -1;
	while (i++, i < size - 1 && i < len_src)
		dest[i] = src[i];
	dest[i] = '\0';
	return (len_src);
}
