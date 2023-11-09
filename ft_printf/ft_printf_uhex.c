/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:46:53 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/08 16:46:53 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hash_flag_handler(char *str, t_data *data)
{
	int	i;

	i = -1;
	if (data->type == 'X')
	{
		write(1, "0X", 2);
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	}
	else
		write(1, "0x", 2);
	write(1, str, ft_strlen(str));
	i = ft_strlen(str) + 2;
	free(str);
	return (i);
}

static int	no_hash_flag(char *str, t_data *data)
{
	int	i;

	i = -1;
	if (data->type == 'X')
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	write(1, str, ft_strlen(str));
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	print_unsigned_hex(unsigned int nbr, t_data *data)
{
	char			*str;
	unsigned long	i;

	i = -1;
	str = ft_uitoa_base((unsigned long)nbr, HEX_STR, 16);
	if (data->hashflag && nbr != 0)
		i = hash_flag_handler(str, data);
	else
		i = no_hash_flag(str, data);
	return (i);
}
