/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:11 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/12 14:32:11 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	pdst = (char *) dst;
	psrc = (char *) src;
	if (src < dst)
	{
		while (n--)
			pdst[n] = psrc[n];
		return (dst);
	}
	ft_memcpy(pdst, psrc, n);
	return (dst);
}
