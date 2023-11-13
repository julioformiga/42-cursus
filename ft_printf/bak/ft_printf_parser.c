/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:49:13 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/08 16:49:13 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isconverter(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	init_flags(t_data *data)
{
	data->offset = 0;
	data->flag_space = 0;
	data->flag_zero = 0;
	data->flag_minus = 0;
	data->flag_plus = 0;
	data->flag_hash = 0;
}

char	printf_parser(const char *s, t_data *data)
{
	int	i;

	i = 1;
	while (s[i] && !isconverter(s[i], "cdpsiuxX%"))
	{
		if (s[i] == ' ' && !data->flag_space)
			data->flag_space = 1;
		else if (s[i] == '+' && !data->flag_plus)
			data->flag_plus = 1;
		else if (s[i] == '#' && !data->flag_hash)
			data->flag_hash = 1;
		i++;
	}
	data->offset = i + 1;
	return (s[i]);
}
