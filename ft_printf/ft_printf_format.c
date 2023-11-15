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

static void	print_pre_format_dis_negative(t_data *data)
{
	int		len;
	int		i_format;
	int		i_lenprint;
	char	*tmp;

	i_format = ft_atoi(data->format);
	len = ft_strlen(data->print);
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
}

static void	print_pre_format_dis(t_data *data)
{
	int		i_format;

	if (data->format == NULL)
		return ;
	i_format = ft_atoi(data->format);
	if (data->type == 's'
		&& (
			(data->format_type == '.' && ft_strlen(data->print) > 1)
			|| (data->format_type == ' ' && ft_atoi(data->format) > 0)
		)
		&& !ft_strchr(data->print, ' ')
		&& ft_strncmp(data->print, "(null)", 6) != 0)
		data->len += print_char(' ');
	if (ft_strchr("di", data->type)
		&& data->format_type == ' ' && i_format >= 1)
		data->len += print_char(' ');
}

void	print_pre_format(t_data *data)
{
	int		len;
	int		i;
	int		i_format;

	i = -1;
	print_pre_format_space_plus(data);
	if (data->format == NULL)
		return ;
	i_format = ft_atoi(data->format);
	if (ft_strchr("0. ", data->format_type))
	{
		if (data->type == 'c')
			len = 1;
		else
			len = ft_strlen(data->print);
		print_pre_format_dis(data);
		print_pre_format_dis_negative(data);
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
