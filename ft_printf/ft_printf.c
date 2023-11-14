/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:24:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/27 22:24:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	show_data(t_data *data)
{
	write(1, "\n=== show_data ===\n", 20);
	printf("type: %c\n", data->type);
	printf("format_type: %c\n", data->format_type);
	printf("format: %s\n", data->format);
	printf("print: %s\n", data->print);
	printf("len: %d\n", data->len);
	write(1, "=================\n", 19);
}

static void	reset_data(t_data *data)
{
	data->type = 0;
	data->format_type = 0;
	data->format = NULL;
	data->print = NULL;
}

void	get_data_print(t_data *data, va_list args)
{
	if (data->type == 'c')
		data->print_char = va_arg(args, int);
	else if (data->type == 's')
		data->print = get_string(va_arg(args, char *));
	else if (data->type == 'p')
		data->print = (char *)get_ptr_addrs(va_arg(args, void *));
	else if (ft_strchr("u", data->type))
		data->print = ft_uitoa(va_arg(args, int));
	else if (ft_strchr("xX", data->type))
		data->print = get_unsigned_hex(va_arg(args, int), data);
	else if (ft_strchr("id", data->type))
		data->print = ft_itoa(va_arg(args, int));
}

static void	print_data(t_data *data)
{
	int		i;
	int		i_format;
	int		i_printlen;

	if (data->type == '%')
		data->len += print_char('%');
	else if (data->type == 'c')
		data->len += print_char(data->print_char);
	else if (ft_strchr("spxX", data->type))
		data->len += print_string(data->print);
	else if (ft_strchr("diu", data->type))
	{
		if (!data->format_type && !data->format)
			data->len += print_string(data->print);
		else if (data->format_type == '-' || data->format_type == '0')
		{
			i_format = ft_atoi(data->format);
			i_printlen = ft_strlen(data->print);
			if (data->format_type == '0' && i_format > 0)
			{
				i = -1;
				while (i++, i < (i_format - i_printlen)
					&& i_format > i_printlen)
					data->len += print_char('0');
				data->len += print_string(data->print);
			}
			else
			{
				if (i_format < 0)
					i_format *= -1;
				data->len += print_string(data->print);
				i = -1;
				while (i++, i < (i_format - i_printlen))
					data->len += print_char(' ');
			}
		}
		else if (!data->format_type && data->format)
		{
			i_format = ft_atoi(data->format);
			i_printlen = ft_strlen(data->print);
			i = -1;
			while (i++, i < (i_format - i_printlen) && i_format > i_printlen)
				data->len += print_char(' ');
			data->len += print_string(data->print);
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_data	data;

	reset_data(&data);
	data.len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			reset_data(&data);
			while (s++, !ft_strchr(PRINTF_TYPES, *s))
			{
				if (ft_strchr(PRINTF_FORMAT, *s)
					&& data.format_type == 0 && !data.format)
					data.format_type = *s;
				else
				{
					if (!data.format)
						data.format = ft_calloc(1, sizeof(char *));
					data.format[ft_strlen(data.format)] = *s;
				}
			}
			if (ft_strchr(PRINTF_TYPES, *s))
				data.type = *s;
			get_data_print(&data, args);
			print_data(&data);
			free(data.print);
			/* show_data(&data); */
		}
		else
			data.len += print_char(*s);
		s++;
	}
	va_end(args);
	free(data.format);
	return (data.len);
}

/* int	main(void) */
/* { */
/* 	char	*format; */
/* 	int		val_int; */
/* 	char	val_char; */
/* 	char	*val_str; */
/* 	int		count; */
/*  */
/* 	format = "| %% | %x | %X | %-10d |\n"; */
/* 	val_int = 1232329; */
/* 	val_char = '-'; */
/* 	val_str = "42 Firenze"; */
/* 	(void)val_str; */
/* 	printf("----- PRINTF ------\n"); */
/* 	count = printf(format, val_char, val_int, 42); */
/* 	printf("count: %d\n", count); */
/* 	ft_printf("\n---- FT_PRINTF ----\n"); */
/* 	count = ft_printf(format, val_char, val_int, 42); */
/* 	ft_printf("count: %d\n", count); */
/* 	return (0); */
/* } */
