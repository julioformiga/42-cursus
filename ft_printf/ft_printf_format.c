/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:57:23 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/15 09:57:23 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pre_format_char(t_data *data)
{
	int	i;
	int	i_format;

	if (data->type == 'c' && !ft_strchr("-.", data->format_type))
	{
		i_format = 1;
		i = 0;
		if (data->format != 0)
			i_format = ft_atoi(data->format);
		while (i++, i < i_format)
			data->len += print_char(' ');
	}
	if (data->type == 'c' && ft_strlen(data->print) == 0)
		data->len++;
}

static void	print_pre_format_dis_negative(t_data *data)
{
	int		len;
	int		i_format;
	int		i_lenprint;
	char	*tmp;

	if (ft_strchr("dis", data->type) && ft_atoi(data->print) < 0)
	{
		i_format = ft_atoi(data->format);
		len = ft_strlen(data->print);
		i_lenprint = ft_atoi(data->print);
		tmp = ft_itoa(i_lenprint * -1);
		ft_memcpy(data->print, tmp, ft_strlen(tmp) + 1);
		if (i_lenprint > INT_MIN)
			data->len += print_char('-');
		if (data->format_type == '.' && i_lenprint < 0 && i_format >= len)
			data->len += print_char('0');
		free(tmp);
	}
}

static void	print_pre_format_dis(t_data *data)
{
	int		i_format;

	print_pre_format_dis_negative(data);
	if (data->format == NULL)
		return ;
	i_format = ft_atoi(data->format);
	if (data->type == 's'
		&& (ft_strchr(" +", data->format_type) && i_format >= 0)
		&& !ft_strchr(data->print, ' ')
		&& ft_strncmp(data->print, "(null)", 6) != 0)
		data->len += print_char(' ');
	if (data->type == 's' && i_format >= 1
		&& (ft_strchr(" 0+", data->format_type) || data->format_type == 0))
		while (i_format--, (int)(i_format - ft_strlen(data->print)) >= 0)
			data->len += print_char(' ');
	if (ft_strchr("diu", data->type)
		&& data->format_type == ' ' && i_format < 0)
		data->len += print_char(' ');
}

void	print_pre_format(t_data *data)
{
	int		len;
	int		i;
	int		i_format;

	i = -1;
	print_pre_format_char(data);
	print_pre_format_space_plus(data);
	print_pre_format_number(data);
	print_pre_format_string(data);
	if (data->format == NULL)
		return ;
	if (!ft_strchr("scup%", data->type) && ft_strchr("0. ", data->format_type))
	{
		i_format = ft_atoi(data->format);
		len = ft_strlen(data->print);
		print_pre_format_dis(data);
		while (i++, i < (i_format - len) && data->type != 's')
		{
			if (ft_strchr("0.", data->format_type)
				&& (i_format >= 0 || data->type == 'u'))
				data->len += print_char('0');
			else
				data->len += print_char(' ');
		}
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
	if (ft_strchr("scdipuxX", data->type) && i_max < 0
		&& ft_strchr("0+# ", data->format_type))
	{
		i_max *= -1;
		if (ft_strchr("dip", data->type)
			&& data->format_type != '#'
			&& ft_atoi(data->print) >= 0)
			i_max--;
		while (i++, i < (int)(i_max - ft_strlen(data->print)))
			data->len += print_char(' ');
	}
	if (data->format_type == '-')
	{
		len = ft_strlen(data->print);
		while (i++, i < (i_max - len))
			data->len += print_char(' ');
	}
}
