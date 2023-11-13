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
#include "libft/libft.h"

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

char	*print_ptr_addrs(void *ptr)
{
	char			*str;
	unsigned long	i;

	i = (unsigned long)ptr;
	str = ft_uitoa_base(i, HEX_STR, 16);
	if (!*str || i == 0)
	{
		free(str);
		return ("(nil)");
	}
	else
	{
		return (ft_strjoin("0x", str));
	}
	return (str);
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

char	*get_char(char c)
{
	char	*str;

	str = &c;
	return (str);
}

char	*get_nbr(int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	return (str);
}
