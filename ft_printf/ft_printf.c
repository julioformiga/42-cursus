/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:24:21 by julio.formiga     #+#    #+#             */
/*   Updated: 2023/10/27 22:24:21 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(long n, int fd)
{
	int		base;
	char	*symbols;

	symbols = "0123456789abcdef";
	base = ft_strlen(symbols);
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_puthex_fd(-n, fd);
	}
	if (n < base)
		ft_putchar_fd(symbols[n], fd);
	else
	{
		ft_puthex_fd(n / base, fd);
		ft_puthex_fd(n % base, fd);
	}
	return (4);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	char	*p;
	char	pnext;
	va_list	ap;

	va_start(ap, format);
	count = 0;
	p = (char *)format;
	p--;
	while (p++, *p)
	{
		if (*p != '%')
		{
			count += ft_putchar_fd(*p, 1);
			continue ;
		}
		pnext = *++p;
		if (pnext == '%')
			count += ft_putchar_fd(pnext, 1);
		else if (pnext == 'd' || pnext == 'i')
			count += ft_putnbr_fd(va_arg(ap, int), 1);
		else if (pnext == 'c')
			count += ft_putchar_fd(va_arg(ap, int), 1);
		else if (pnext == 's')
			count += ft_putstr_fd(va_arg(ap, char *), 1);
		else if (pnext == 'x' || pnext == 'X' || pnext == 'p')
			count += ft_puthex_fd(va_arg(ap, int), 1);
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	char	*format;
	int		hex;
	int		count;

	format = "%%int: %d\t| char: %c\t| texto: %s\t| hex: %x\t| pointer: %x\n";
	hex = 21321;
	count = printf(format, hex, 'a', "string", hex, hex);
	printf("count: %d\n", count);
	count = ft_printf(format, hex, 'a', "string", hex, hex);
	printf("count: %d\n", count);
	return (0);
}
