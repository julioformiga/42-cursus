/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:53:40 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/02/02 14:53:40 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_replace(char *str, char s, char r)
{
	int	i;

	i = -1;
	while (i++, str[i])
		if (str[i] == s)
			str[i] = r;
	return (str);
}

int	ft_isblank(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	return (1);
}

int	has_blank(const char *str)
{
	int	i;

	i = -1;
	while (i++, str[i])
		if (ft_isblank(str[i]))
			return (1);
	return (0);
}
