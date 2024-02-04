/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:07:55 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/12/09 00:07:55 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pre_format_number_precision(t_data *data)
{
	int		i;
	int		i_max;
	char	*data_print;
	char	**split_dot;

	if (data->type != 's')
		return ;
	split_dot = ft_split(data->format, '.');
	if (split_dot[1] != NULL)
	{
		i_max = ft_atoi(split_dot[1]);
		data_print = ft_substr(data->print, 0, i_max);
		free(data->print);
		data->print = data_print;
	}
	i = 0;
	while (split_dot[i])
		free(split_dot[i++]);
	free(split_dot);
}

void	print_pre_format_pointer_precision(t_data *data)
{
	int		i;
	int		i_max;
	char	*data_print;
	char	**split_dot;

	if (data->type != 'p')
		return ;
	split_dot = ft_split(data->format, '.');
	if (split_dot[1] != NULL)
	{
		i_max = ft_atoi(split_dot[1]);
		data_print = ft_substr(data->print, 0, i_max);
		free(data->print);
		data->print = data_print;
	}
	i = 0;
	while (split_dot[i])
		free(split_dot[i++]);
	free(split_dot);
}

void	print_pre_format_string_precision(t_data *data)
{
	int		i;
	int		i_max;
	char	*data_print;
	char	**split_dot;

	if (data->type != 's')
		return ;
	split_dot = ft_split(data->format, '.');
	if (split_dot[1] != NULL)
	{
		i_max = ft_atoi(split_dot[1]);
		data_print = ft_substr(data->print, 0, i_max);
		free(data->print);
		data->print = data_print;
	}
	i = 0;
	while (split_dot[i])
		free(split_dot[i++]);
	free(split_dot);
}
