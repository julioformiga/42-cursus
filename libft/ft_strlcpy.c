/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 04:11:55 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/12 04:11:55 by julsanti         ###   ########.fr       */
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
