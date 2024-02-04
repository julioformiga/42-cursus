/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cspudi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 03:46:48 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/14 03:46:48 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	show_data(t_data *data)
{
	printf("\n=== show_data ===\n");
	printf("type: %c\n", data->type);
	printf("format_type: |%c|\n", data->format_type);
	printf("format: |%s|\n", data->format);
	printf("print: |%s|\n", data->print);
	printf("len: |%d|\n", data->len);
	printf("==================\n");
}

int	print_char(char c)
{
	if (c == '\0')
		return (0);
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

void	print_pre_format_number(t_data *data)
{
	int		i;
	int		i_max;

	i = -1;
	if (ft_strchr("dip", data->type) && data->format)
	{
		print_pre_format_number_precision(data);
		if (ft_strchr("#", data->format_type))
		{
			i_max = ft_atoi(data->format);
			while (i++, i < (int)(i_max - ft_strlen(data->print)))
				data->len += print_char(' ');
		}
	}
}

void	print_pre_format_string(t_data *data)
{
	int		i;
	int		i_max;

	i = -1;
	if (data->type == 'c' && !data->format_type && data->format)
	{
		i_max = ft_atoi(data->format);
		while (i++, i < (int)(i_max - 1))
			data->len += print_char(' ');
	}
	if (ft_strchr("suxX", data->type) && data->format)
	{
		print_pre_format_string_precision(data);
		if (ft_strchr("# +", data->format_type))
		{
			i_max = ft_atoi(data->format);
			while (i++, i < (int)(i_max - ft_strlen(data->print)))
				data->len += print_char(' ');
		}
	}
}

void	print_args(const char *s, t_data *data, va_list args)
{
	while (*s)
	{
		reset_data(data);
		if (*s == '%')
		{
			while (s++, !ft_strchr(PRINTF_TYPES, *s))
				get_arg_format(*s, data);
			if (ft_strchr(PRINTF_TYPES, *s))
				data->type = *s;
			get_data_strings(data, args);
			print_data(data);
			free(data->print);
			free(data->format);
		}
		else
			data->len += print_char(*s);
		s++;
	}
}
