/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julsanti <julsanti@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:14:32 by julsanti          #+#    #+#             */
/*   Updated: 2023/10/17 10:14:32 by julsanti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(const char *s, char c)
{
	char	**s_array;
	size_t	word;
	size_t	init;
	size_t	i;
	size_t	j;

	if (!s || !c)
		return (NULL);
	i = -1;
	while (i++, s++)
		if (*s == c)
			i++;
	s_array = malloc(sizeof(char **) * i);
	i = -1;
	word = 0;
	init = 0;
	j = 0;
	while (i++, *s++)
	{
		printf("%c", *s);
		if (*s == c || *s == 0)
		{
			s_array[word][j] = 0;
			word++;
			j = 0;
		}
		else
		{
			s_array[word][j] = *s;
			j = 0;
		}
	}
	return (s_array);
}

int	main(void)
{
	char	*s = "aacbbbcdddcee";
	char	**sa;

	printf("test");
	sa = ft_split(s, 'c');
	while (**sa)
		printf("%s\n", *sa++);
	return (0);
}
