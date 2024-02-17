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

#include "ft_printf/libft/libft.h"
#include "push_swap.h"

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

int	ft_has_blank(const char *str)
{
	int	i;

	i = -1;
	while (i++, str[i])
		if (ft_isblank(str[i]))
			return (1);
	return (0);
}

int	ft_check_int_out_of_range(const char *str)
{
	int	len;

	len = ft_strlen(str);
	if ((len <= 9 && ft_isdigit(str[0]))
		|| (len <= 10 && ft_strchr("-+", str[0])))
		return (0);
	if (len == 10 && ft_strchr("012", str[0]) && ft_atoi(str) > 0)
		return (0);
	if (len == 11 && ft_strchr("-+", str[0]) && ft_strchr("012", str[1]))
	{
		if (str[0] == '-' && ft_atoi(str) < 0)
			return (0);
		if (str[0] == '+' && ft_atoi(str) > 0)
			return (0);
	}
	return (1);
}
