/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:12:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/18 20:13:19 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	str_len;
	unsigned int	max_len;
	char			*substr;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	max_len = 0;
	if (start < str_len)
		max_len = str_len - start;
	if (max_len > len)
		max_len = len;
	max_len++;
	substr = (char *)malloc(max_len * sizeof(char));
	if (substr == NULL)
		return (NULL);
	if (start < UINT_MAX)
		ft_strlcpy(substr, s + start, max_len);
	else
		ft_strlcpy(substr, "", 1);
	return (substr);
}
