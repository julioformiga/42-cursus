/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:09:57 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/13 13:09:57 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
		c %= 256;
	s--;
	while (s++, *s)
		if (*s == c)
			return ((char *)s);
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
