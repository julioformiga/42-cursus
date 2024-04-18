/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:46:13 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 19:50:19 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dest;
	unsigned int	i;

	dest = (char *)malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	i = -1;
	while (i++, s[i])
		dest[i] = s[i];
	dest[i] = 0;
	return (dest);
}
