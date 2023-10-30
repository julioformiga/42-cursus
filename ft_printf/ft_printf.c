/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:24:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/27 22:24:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*p;
	char	pnext;

	va_start(ap, format);
	p = (char *)format;
	p--;
	while (p++, *p)
	{
		if (*p != '%')
		{
			write(1, p, 1);
			continue ;
		}
		pnext = *++p;
		if (pnext == '%')
			write(1, &pnext, 1);
		else if (pnext == 'd')
			ft_putnbr_fd(va_arg(ap, int), 1);
		else if (pnext == 'c')
			ft_putchar_fd(va_arg(ap, int), 1);
		else if (pnext == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	char	*format;
	int		hex;

	format = "%%int: %d\t| char: %c\t| texto: %s\t| hex: %x\n";
	hex = 127;
	printf(format, 1232123211, 'a', "string", hex);
	ft_printf(format, 1232123211, 'a', "string", hex);
	return (0);
}
