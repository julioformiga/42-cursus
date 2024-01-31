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

void	reset_data(t_data *data)
{
	data->type = 0;
	data->format_type = 0;
	data->format = NULL;
	data->print = NULL;
}

char	*get_data_char(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	get_data_strings(t_data *data, va_list args)
{
	char	data_char;

	data_char = '%';
	if (data->type == 'c')
	{
		data_char = va_arg(args, int);
		if (data_char == '\0')
			data->printing = 0;
	}
	if (data->type == '%' || data->type == 'c')
		data->print = get_data_char(data_char);
	else if (data->type == 's')
		data->print = get_string(va_arg(args, char *));
	else if (data->type == 'p')
		data->print = (char *)get_ptr_addrs(va_arg(args, void *));
	else if (data->type == 'u')
		data->print = ft_uitoa(va_arg(args, int));
	else if (ft_strchr("di", data->type))
		data->print = ft_itoa(va_arg(args, int));
	else if (ft_strchr("xX", data->type))
		data->print = get_unsigned_hex(va_arg(args, int), data);
}

void	print_data(t_data *data)
{
	print_pre_format(data);
	if (data->type == 'c' && data->print[0] == '\0')
		data->len += print_char('\0');
	if (data->printing == 1)
		data->len += print_string(data->print);
	else
		data->len += ft_strlen(data->print);
	print_pos_format(data);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_data	data;

	reset_data(&data);
	data.len = 0;
	data.printing = 1;
	va_start(args, s);
	print_args(s, &data, args);
	va_end(args);
	return (data.len);
}

// int	main(void)
// {
// 	char	*format;
// 	int		v_int;
// 	char	*v_str;
// 	char	v_char;
// 	int		count;
//
// 	v_int = -4;
// 	v_char = 0;
// 	v_str = "Firenze";
// 	format = "%c %c %c";
// 	format = "%% | %3c | %#12s | %.1d | %04d | %-0d | %d |\n";
// 	printf(":PRINTF   : %s", format);
// 	count = printf(format, v_char, v_str, v_int, v_int, v_int, v_int);
// 	// count = printf(format, '0', 0, '2');
// 	printf("count: %d\n", count);
// 	ft_printf("\n:FT_PRINTF: %s", format);
// 	count = ft_printf(format, v_char, v_str, v_int, v_int, v_int, v_int);
// 	// count = ft_printf(format, '0', 0, '2');
// 	ft_printf("count: %d\n", count);
// 	return (0);
// }
