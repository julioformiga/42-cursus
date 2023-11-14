/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 03:51:02 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/11/14 03:51:02 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(char c)
{
	char	*str;

	str = &c;
	return (str);
}

char	*get_string(char *str)
{
	if (!str)
	{
		free(str);
		return (ft_strdup("(null)"));
	}
	return (ft_strdup(str));
}

char	*get_ptr_addrs(void *ptr)
{
	char			*str;
	char			*dest;
	unsigned long	i;

	i = (unsigned long)ptr;
	str = ft_uitoa_base(i, HEX_STR, 16);
	if (!str || i == 0)
	{
		free(str);
		return (ft_strdup("(nil)"));
	}
	dest = ft_strjoin("0x", str);
	free(str);
	return (dest);
}

char	*get_nbr(int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	return (str);
}

char	*get_unsigned_hex(unsigned int nbr, t_data *data)
{
	char			*str;
	unsigned long	i;

	i = -1;
	str = ft_uitoa_base((unsigned long)nbr, HEX_STR, 16);
	if (data->type == 'X')
		while (str[++i])
			str[i] = ft_toupper(str[i]);
	return (str);
}
