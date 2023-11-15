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

void	reset_data(t_data *data)
{
	data->type = 0;
	data->format_type = 0;
	data->format = NULL;
	data->print = NULL;
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

void	print_pre_format(t_data *data)
{
	int		len;
	int		i;
	int		i_format;
	int		i_lenprint;
	char	*tmp;

	i = -1;
	if (data->type == 's' && data->format_type == '.')
	{
		if (data->format == NULL)
			ft_memcpy(data->print, "", 1);
		else
		{
			i_format = ft_atoi(data->format);
			i_lenprint = ft_strlen(data->print);
			if (i_format < i_lenprint)
			{
				tmp = ft_calloc(i_format + 1, sizeof(char));
				ft_memcpy(tmp, data->print, i_format);
				ft_memcpy(data->print, tmp, i_format + 1);
				free(tmp);
			}
		}
	}
	if (data->format_type == ' ' && data->format == NULL)
	{
		if (ft_strchr("s", data->type)
			&& ft_strlen(data->print) > 1
			&& !ft_strchr(data->print, ' ')
			&& ft_strncmp(data->print, "(null)", 6) != 0)
			data->len += print_char(' ');
		if (ft_strchr("di", data->type) && ft_atoi(data->print) >= 0)
			data->len += print_char(' ');
	}
	if (data->format_type == '+')
	{
		if (ft_strchr("di", data->type)
			&& ft_atoi(data->print) >= 0)
			data->len += print_char(data->format_type);
	}
	if (data->format == NULL)
		return ;
	i_format = ft_atoi(data->format);
	if (data->format_type == '0' || data->format_type == '.' || data->format_type == ' ')
	{
		if (data->type == 'c')
			len = 1;
		else
			len = ft_strlen(data->print);
		if (data->type == 's'
			&& (
				(data->format_type == '.' && ft_strlen(data->print) > 1)
				||
				(data->format_type == ' ' && ft_atoi(data->format) > 0)
			)
			&& !ft_strchr(data->print, ' ')
			&& ft_strncmp(data->print, "(null)", 6) != 0)
			data->len += print_char(' ');
		if (ft_strchr("di", data->type) && data->format_type == ' ' && i_format >= 1)
			data->len += print_char(' ');
		if (ft_strchr("dis", data->type) && ft_atoi(data->print) < 0)
		{
			i_lenprint = ft_atoi(data->print);
			tmp = ft_itoa(i_lenprint * -1);
			ft_memcpy(data->print, tmp, ft_strlen(tmp) + 1);
			if (i_lenprint > INT_MIN)
				data->len += print_char('-');
			if (data->format_type == '.' && i_lenprint < 0 && i_format >= len)
				data->len += print_char('0');
			free(tmp);
		}
		while (i++, i < (i_format - len) && data->type != 's')
			data->len += print_char('0');
	}
}
void	print_pos_format(t_data *data)
{
	int		len;
	int		i;
	int		i_max;

	i = -1;
	if (data->format == NULL)
		return ;
	i_max = ft_atoi(data->format);
	if (ft_strchr("-", data->format_type))
	{
		if (data->type == 'c')
			len = 1;
		else
			len = ft_strlen(data->print);
		while (i++, i < (i_max - len))
			data->len += print_char(' ');
	}
}

void	get_arg_format(char c, t_data *data)
{
	if (ft_strchr(PRINTF_FORMAT, c)
		&& data->format_type == 0 && !data->format)
		data->format_type = c;
	else
	{
		if (!data->format)
			data->format = ft_calloc(1, sizeof(char *));
		data->format[ft_strlen(data->format)] = c;
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
			/* show_data(data); */
			free(data->print);
			free(data->format);
		}
		else
			data->len += print_char(*s);
		s++;
	}
}
