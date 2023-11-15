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

void	get_data_strings(t_data *data, va_list args)
{
	if (data->type == '%')
		data->print_char = '%';
	else if (data->type == 'c')
		data->print_char = va_arg(args, int);
	else if (data->type == 's')
		data->print = get_string(va_arg(args, char *));
	else if (data->type == 'p')
		data->print = (char *)get_ptr_addrs(va_arg(args, void *));
	else if (ft_strchr("di", data->type))
		data->print = ft_itoa(va_arg(args, int));
	else if (ft_strchr("u", data->type))
		data->print = ft_uitoa(va_arg(args, int));
	else if (ft_strchr("xX", data->type))
		data->print = get_unsigned_hex(va_arg(args, int), data);
}

void	print_data(t_data *data)
{
	print_pre_format(data);
	if (ft_strchr("%c", data->type))
		data->len += print_char(data->print_char);
	else if (ft_strchr("spiduxX", data->type))
		data->len += print_string(data->print);
	print_pos_format(data);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_data	data;

	reset_data(&data);
	data.len = 0;
	va_start(args, s);
	print_args(s, &data, args);
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
/* 	//format = "| %c | %s | %p | %d | %x | %X | \n"; */
/* 	//format = "| %-5c | %.s | %.1d | %04d | %-0d | %d \n"; */
/* 	format = "| % 1d | % 1i |\n"; */
/* 	val_int = -4; */
/* 	val_char = '7'; */
/* 	val_str = "Firenze"; */
/* 	(void)val_int; */
/* 	(void)val_char; */
/* 	(void)val_str; */
/* 	printf("----- PRINTF ------\n"); */
/* 	//count = printf(format, val_char, val_str, val_int, val_int, val_int, 42); */
/* 	count = printf(format, 1, 1); */
/* 	printf("count: %d\n", count); */
/* 	ft_printf("\n---- FT_PRINTF ----\n"); */
/* 	//count = ft_printf(format, val_char, val_str, val_int, val_int, val_int, 42); */
/* 	count = ft_printf(format, 1, 1); */
/* 	ft_printf("count: %d\n", count); */
/* 	return (0); */
/* } */
