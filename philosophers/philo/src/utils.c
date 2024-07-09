/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:08:01 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/08 13:08:01 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		++str;
	else if (*str == '-')
		ft_error("Invalid input (negative number)");
	if (!is_digit(*str))
		ft_error("Invalid input (not a number)");
	number = str;
	while (is_digit(*str))
		++len;
	if (len > 10)
		ft_error("Invalid input (number too big)");
	return (number);
}

long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		ft_error("Invalid input (number too big)");
	return (num);
}

void	ft_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}
