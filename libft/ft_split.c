/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:10:26 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/17 19:10:26 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	token_count(char const *s, char c)
{
	size_t	index;
	size_t	count;
	size_t	length;

	count = 0;
	length = 0;
	index = -1;
	while (index++, s[index])
	{
		if (s[index] == c)
		{
			if (length != 0)
				count++;
			length = 0;
		}
		else
			length++;
	}
	if (length != 0)
		return (count + 1);
	return (count);
}

void	token_array(char const *s, char c, char **array, size_t item_count)
{
	char	*str;
	size_t	array_index;
	size_t	index;
	size_t	length;

	array_index = 0;
	length = 0;
	index = -1;
	while (index++, array_index < item_count)
	{
		if (s[index] == c || s[index] == '\0')
		{
			if (length != 0)
			{
				str = ft_calloc(length + 1, sizeof(char *));
				if (!str)
					return ;
				ft_memcpy(str, s + index - length, length);
				array[array_index++] = str;
			}
			length = 0;
		}
		else
			length++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	item_count;
	char	**array;

	if (s == NULL)
		return (NULL);
	item_count = token_count(s, c);
	array = (char **)malloc((item_count + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	token_array(s, c, array, item_count);
	array[item_count] = NULL;
	return (array);
}
