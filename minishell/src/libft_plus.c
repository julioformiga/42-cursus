/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:31:38 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/09/16 15:31:38 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	if (!s1 || n == 0)
		return (NULL);
	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
