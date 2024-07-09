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

int	pthread_create(pthread_t *restrict thread,
		const pthread_attr_t *restrict attr,
		void *(*start_routine)(void *),
		void *restrict arg);

int	pthread_join(pthread_t thread, void **retval);
int	pthread_detach(pthread_t thread);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		printf("Philosopher %d is thinking\n", philo->id);
		printf("Philosopher %d is eating\n", philo->id);
		printf("Philosopher %d is sleeping\n", philo->id);
	}
	return (NULL);
}

void	parse_input(t_table *table, char **argv)
{
	table->philo_n = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		ft_error("Timestamp must be greater than 60ms.");
	if (argv[5])
		table->meals_limit = ft_atol(argv[5]);
	else
		table->meals_limit = -1;
}

int	main(int argc, char **argv)
{
	t_table	table;

	printf("Hello, World!\n");
	if (argc < 5 || argc > 6)
		ft_error("Invalid number of arguments.");
	if (argc == 5)
	{
		parse_input(&table, argv);
		data_init(&table);
	}
	return (0);
}
