/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:37:58 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/15 21:37:59 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*strout;

	size = ft_strlen(s) + 1;
	strout = (char *)malloc(size);
	if (strout == NULL)
		return (NULL);
	ft_strlcpy(strout, s, size);
	return (strout);
}
