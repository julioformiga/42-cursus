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

int	print_char(char c)
{
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
			/* show_data(data); */
			print_data(data);
			free(data->print);
			free(data->format);
		}
		else
			data->len += print_char(*s);
		s++;
	}
}
