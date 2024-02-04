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
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	get_data_strings(t_data *data, va_list args)
{
	char	data_char;

	data_char = '%';
	if (data->type == 'c')
		data_char = va_arg(args, int);
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

int	main(void)
{
	char	*format[8];
	int		v_int;
	char	*v_str;
	char	v_char;
	int		count;

	v_int = -42427212;
	v_char = 'C';
	v_str = "42 Firenze";
	format[0] = "%%|%c|%s|%d|%i|%u|%p|%x|%X|";
	format[1] = "%5%|%+3c|%+14s|%+12d|%+12i|%+12u|%+13p|%+11x|%+10X|";
	format[2] = "%5%|%+-3c|%+-14s|%+-12d|%+-10i|%+-12u|%+-11p|%+-10x|%+-10X|";
	format[3] = "%5%|%#3c|%#14s|%#12d|%#10i|%#12u|%#12p|%#12x|%#12X|";
	format[4] = "%5%|%#-3c|%#-14s|%#-12d|%#-10i|%#-12u|%#-12p|%#-12x|%#-12X|";
	format[5] = "%5%|% 3c|% 14s|% 12d|% 10i|% 12u|% 12p|% 10x|% 10X|";
	format[6] = "%5%|% -3c|% -14s|% -12d|% -10i|% -12u|% -10p|% -10x|% -10X|";
	format[7] = "%5%|%.3c|%.14s|%.12d|%.10i|%.12u|%17.10p|%.12x|%.10X|";
	for (int i = 0; i < 8; i++)
	{
		ft_printf("----------------- TEST [%d] ----------- \n", i);
		printf(":__ FORMAT __: %s", format[i]);
		printf("\n:     PRINTF : ");
		count = printf(format[i], v_char, v_str,
				v_int, v_int, v_int, v_int, v_int, v_int);
		printf(" count = %d|\n", count);
		ft_printf(":  FT_PRINTF : ");
		count = ft_printf(format[i], v_char, v_str,
				v_int, v_int, v_int, v_int, v_int, v_int);
		ft_printf(" count = %d|\n", count, i);
	}
	return (0);
}
