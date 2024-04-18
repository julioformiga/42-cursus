/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:23:36 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 19:50:19 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			sc;

	if (c > 127)
		c %= 256;
	sc = (char)c;
	i = -1;
	while (i++, s[i])
		if (s[i] == sc)
			return ((char *)&s[i]);
	if (s[i] == sc)
		return ((char *)&s[i]);
	return (NULL);
}
