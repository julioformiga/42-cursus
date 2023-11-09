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
	data->spaceflag = 0;
	data->unsigflag = 0;
	data->plusflag = 0;
	data->hashflag = 0;
}

char	printf_parser(const char *s, t_data *data)
{
	int	i;

	i = 1;
	while (s[i] && !isconverter(s[i], "cdpsiuxX%"))
	{
		if (s[i] == ' ' && !data->spaceflag)
			data->spaceflag = 1;
		else if (s[i] == '+' && !data->plusflag)
			data->plusflag = 1;
		else if (s[i] == '#' && !data->hashflag)
			data->hashflag = 1;
		i++;
	}
	data->offset = i + 1;
	return (s[i]);
}
