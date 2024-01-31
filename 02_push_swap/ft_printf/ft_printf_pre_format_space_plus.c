/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pre_format_space_plus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:51:45 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/15 09:51:45 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	space_dis(t_data *data)
{
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
}

void	print_pre_format_space_plus(t_data *data)
{
	int		i_format;
	int		i_lenprint;
	char	*tmp;

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
	space_dis(data);
}
