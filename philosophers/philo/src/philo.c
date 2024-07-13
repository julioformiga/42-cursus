/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:17:44 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/06/04 00:17:44 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;
	char 	*av[] = {"./philo", "5", "800", "200", "200", NULL};

	if (argc < 5 || argc > 6)
	{
		argc = 5;
		argv = av;
		// ft_error("Invalid number of arguments.");
	}
	if (argc == 5)
	{
		parse_input(&table, argv);
		data_init(&table);
		dinner_start(&table);
	}
	return (0);
}
