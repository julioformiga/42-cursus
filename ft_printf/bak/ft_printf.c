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

static void	init_arg(t_data *data, va_list args)
{
	if (data->type == 's')
		data->str = va_arg(args, char *);
	else if (data->type == 'p')
		data->hex_ptr = va_arg(args, void *);
	else if (data->type == 'd' || data->type == 'i')
		data->nbr = va_arg(args, int);
	else if (data->type == 'u' || data->type == 'x' || data->type == 'X')
		data->unsig = va_arg(args, unsigned int);
	else
		data->ch = va_arg(args, int);
}

static void	call_conversion(t_data *data)
{
	if (data->type == 'c')
		data->len += print_char(data->ch);
	if (data->type == 's')
		data->len += print_string(data->str);
	if (data->type == 'p')
		data->len += print_ptr_addrs(data->hex_ptr);
	if (data->type == 'd' || data->type == 'i')
		data->len += print_nbr(data->nbr, data);
	if (data->type == 'u')
		data->len += print_unsigned(data->unsig);
	if (data->type == 'x' || data->type == 'X')
		data->len += print_unsigned_hex(data->unsig, data);
	if (data->type == '%')
		data->len += print_char('%');
}

static int	count_args(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			i++;
			s++;
		}
		s++;
	}
	return (i);
}

static int	write_filler(const char *s, t_data *data)
{
	int	i;

	i = 0;
	while (s[i] != '%' && s[i])
		++i;
	write(1, s, i);
	data->len += i;
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_data	data;

	data.len = 0;
	va_start(args, s);
	data.argc = count_args(s);
	while (data.argc--)
	{
		init_flags(&data);
		s += write_filler(s, &data);
		data.type = printf_parser(s, &data);
		s += data.offset;
		if (data.type != '%')
			init_arg(&data, args);
		call_conversion(&data);
	}
	s += write_filler(s, &data);
	va_end(args);
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
/* 	format = "| %5i | %5c | %-15s |\n"; */
/* 	val_int = 3; */
/* 	val_char = 'C'; */
/* 	val_str = "42 Firenze"; */
/* 	(void)val_int; */
/* 	(void)val_char; */
/* 	(void)val_str; */
/* 	printf("----- PRINTF ------\n"); */
/* 	count = printf(format, val_int, val_char, val_str); */
/* 	printf("count: %d\n", count); */
/* 	printf("\n---- FT_PRINTF ----\n"); */
/* 	count = ft_printf(format, val_int, val_char, val_str); */
/* 	ft_printf("count: %d\n", count); */
/* 	return (0); */
/* } */
