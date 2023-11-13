/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:48:26 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/08 16:48:26 by julio.formiga    ###   ########.fr       */
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
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

int	print_ptr_addrs(void *ptr)
{
	char			*str;
	unsigned long	i;

	i = (unsigned long)ptr;
	str = ft_uitoa_base(i, HEX_STR, 16);
	if (!*str || i == 0)
	{
		write(1, "(nil)", 5);
		free(str);
		return (5);
	}
	else
	{
		write (1, "0x", 2);
		write(1, str, ft_strlen(str));
	}
	i = 0;
	i += ft_strlen(str) + 2;
	free(str);
	return (i);
}

int	print_unsigned(unsigned int nbr)
{
	char	*str;
	int		i;

	str = ft_uitoa(nbr);
	i = ft_strlen(str);
	write(1, str, i);
	free(str);
	return (i);
}

int	print_nbr(int nbr, t_data *data)
{
	char	*str;
	int		i;

	str = ft_itoa(nbr);
	i = ft_strlen(str);
	if (data->flag_plus && nbr >= 0)
	{
		write(1, "+", 1);
		i++;
	}
	else if (data->flag_space && nbr >= 0)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, str, ft_strlen(str));
	free (str);
	return (i);
}
