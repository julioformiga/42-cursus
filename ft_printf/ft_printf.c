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
#include "libft/libft.h"
#include <stddef.h>
#include <stdio.h>

void	show_data(t_data *data)
{
	write(1, "\n=== show_data ===\n", 20);
	printf("type: %c\n", data->type);
	printf("format_type: %c\n", data->format_type);
	printf("format: %s\n", data->format);
	printf("print: %s\n", data->print);
	write(1, "=================\n", 19);
}

static void	reset_data(t_data *data)
{
	data->type = 0;
	data->format_type = 0;
	data->format = NULL;
	data->print = 0;
}

static char	*ft_add_char_to_str(char *dest, char src)
{
	char	*str;

	if (!dest)
	{
		str = ft_strdup("");
		str[0] = (char)src;
		return (str);
	}
	str = ft_strdup(dest);
	str[ft_strlen(str)] = (char)src;
	return (str);
}

static void	get_data_print(t_data *data, va_list args)
{
	if (data->type == 's')
		data->print = va_arg(args, char *);
	else if (data->type == 'p')
		data->print = print_ptr_addrs(va_arg(args, void *));
	else if (data->type == 'u' || data->type == 'x' || data->type == 'X')
		data->print = ft_uitoa(va_arg(args, int));
	else
		data->print = get_nbr(va_arg(args, int));
}

static void	print_data(t_data *data)
{
	size_t	i;
	size_t	i_format;
	size_t	i_printlen;

	if (data->type == 'd' || data->type == 'i')
	{
		if (!data->format_type && !data->format)
			data->len += print_string(data->print);
		else if (data->format_type == '-' || data->format_type == '0')
		{
			i_format = ft_atoi(data->format);
			i_printlen = ft_strlen(data->print);
			if (data->format_type == '0' && (int)i_format > 0)
			{
				i = -1;
				while (i++, i < (i_format - i_printlen) && i_format > i_printlen && i < 30)
					data->len += print_char('0');
				data->len += print_string(data->print);
			}
			else
			{
				if ((int)i_format < 0)
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

static void	init_data(t_data *data)
{
	data->type = 0;
	data->format_type = 0;
	data->format = NULL;
	data->print = 0;
	data->len = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_data	data;

	init_data(&data);
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
					data.format = ft_add_char_to_str(data.format, (char)*s);
			}
			if (ft_strchr(PRINTF_TYPES, *s))
				data.type = *s;
			get_data_print(&data, args);
			print_data(&data);
			/* show_data(&data); */
		}
		else
			data.len += print_char(*s);
		s++;
	}
	va_end(args);
	return (data.len);
}

int	main(void)
{
	char	*format;
	int		val_int;
	char	val_char;
	char	*val_str;
	int		count;

	format = "| %010d | %-15d |\n";
	val_int = 30;
	val_char = 'C';
	val_str = "42 Firenze";
	(void)val_int;
	(void)val_char;
	(void)val_str;
	printf("----- PRINTF ------\n");
	count = printf(format, val_int, 42);
	printf("count: %d\n", count);
	ft_printf("\n---- FT_PRINTF ----\n");
	count = ft_printf(format, val_int, 42);
	ft_printf("count: %d\n", count);
	return (0);
}
