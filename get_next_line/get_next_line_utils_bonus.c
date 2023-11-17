/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:45:33 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/15 19:45:33 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, char c)
{
	unsigned int	i;
	char			sc;

	sc = (char)c;
	i = -1;
	while (i++, str[i])
		if (str[i] == sc)
			return ((char *)&str[i]);
	if (str[i] == sc)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char			*dest;
	unsigned int	i;

	dest = (char *)malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	i = -1;
	while (i++, str[i])
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	char	*ps3;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(len * sizeof(char));
	if (!s3)
	{
		free(s3);
		return (NULL);
	}
	ps3 = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = 0;
	return (ps3);
}
