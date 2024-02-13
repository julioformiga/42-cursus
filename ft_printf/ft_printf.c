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
	data->number_neg = 0;
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
	if (data->type == '%')
		data->print = get_data_char('%');
	if (data->type == 'c')
		data->print = get_data_char(va_arg(args, int));
	else if (data->type == 's')
		data->print = get_string(va_arg(args, char *));
	else if (data->type == 'p')
		data->print = (char *)get_ptr_addrs(va_arg(args, void *));
	else if (data->type == 'u')
		data->print = ft_uitoa(va_arg(args, int));
	else if (ft_strchr("xX", data->type))
		data->print = get_unsigned_hex(va_arg(args, int), data);
	else if (ft_strchr("di", data->type))
	{
		data->print = ft_itoa(va_arg(args, int));
		if (ft_atoi(data->print) < 0)
			data->number_neg = 1;
	}
}

void	print_data(t_data *data)
{
	int	iformat;

	iformat = print_format_null(data);
	if (iformat == -1)
		return ;
	if (data->format_type == '.' && iformat < 0)
	{
		data->len += print_string("%.0");
		data->len += print_string(data->format);
		data->len += print_char(data->type);
	}
	else
	{
		print_pre_format(data);
		if (data->type == 'c' || data->type == '%')
			data->len += print_char(data->print[0]);
		else
			data->len += print_string(data->print);
		print_pos_format(data);
	}
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
/*
int	main(void)
{
	char	*format[19];
	int		v_int;
	char	*v_str;
	char	v_char;
	int		count;
	void	*v_ptr;

	v_int = INT_MIN + 1;
	v_int = INT_MAX;
	v_int = -1;
	v_int = 0;
	v_int = INT_MIN;
	v_ptr = &v_int;
	v_char = 'C';
	v_str = "42 Firenze";
	format[0] = "%%|%c|%s|%d|%i|%u|%p|%x|%X|";
	format[1] = "%5%|%5c|%14s|%12d|%12i|%14u|%14p|%14x|%14X|";
	format[2] = "%5%|%+5c|%+14s|%+12d|%+12i|%+14u|%+14p|%+14x|%+14X|";
	format[3] = "%5%|%#5c|%#14s|%#12d|%#12i|%#12u|%#14p|%#14x|%#12X|";
	format[4] = "%5%|% 5c|% 14s|% 14d|% 14i|% 14u|% 14p|% 14x|% 14X|";
	format[5] = "%5%|%05c|%014s|%014d|%014i|%014u|%014p|%012x|%012X|";
	format[6] = "%5%|%#-5c|%#-14s|%#-12d|%#-14i|%#-14u|%#-14p|%#-12x|%#-12X|";
	format[7] = "%5%|%-5c|%-14s|%-14d|%-12i|%-14u|%-12p|%-14x|%-14X|";
	format[8] = "%5%|%+-5c|%+-14s|%+-12d|%+-14i|%+-14u|%+-14p|%+-14x|%+-14X|";
	format[9] = "%5%|% -5c|% -14s|% -14d|% -14i|% -14u|% -14p|% -12x|% -12X|";
	format[10] = "%5%|%0-5c|%0-14s|%0-14d|%0-14i|%0-14u|%0-12p|%0-12x|%0-12X|";
	format[11] = "%5%|%.5c|%.14s|%.14d|%.14i|%.14u|%.14p|%.14x|%.12X|";
	format[12] = "%5%|%.-5c|%.-14s|%.-14d|%.-14i|%.-14u|%.-14p|%.-14x|%.-12X|";
	format[13] = "%%|%#c|%#s|%#d|%#i|%#u|%#p|%#x|%#X|";
	format[14] = "%%|%.c|%.s|%.d|%.i|%.u|%.p|%.x|%.X|";
	format[15] = "%%|%0c|%0s|%0d|%0i|%0u|%0p|%0x|%0X|";
	format[16] = "%%|% c|% s|% d|% i|% u|% p|% x|% X|";
	format[17] = "%%|%-c|%-s|%-d|%-i|%-u|%-p|%-x|%-X|";
	format[18] = "%%|%+c|%+s|%+d|%+i|%+u|%+p|%+x|%+X|";
	for (int i = 0; i <= 18; i++)
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
	printf("\n:     PRINTF : ");
	count = printf(" %c %c %c %14p", '0', 0, '1', v_ptr);
	printf("\ncount = %d\n", count);
	ft_printf(":  FT_PRINTF : ");
	count = ft_printf(" %c %c %c %14p", '0', 0, '1', v_ptr);
	printf("\ncount = %d\n", count);
	return (0);
}
*/
