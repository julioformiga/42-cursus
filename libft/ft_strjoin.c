/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:54:52 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/16 16:54:52 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ps3;
	char	*s3;
	size_t	s3_len;

	if (!s1 || !s2)
		return (NULL);
	s3_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = (char *)malloc(s3_len);
	if (s3 == NULL)
		return (NULL);
	ps3 = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (ps3);
}
