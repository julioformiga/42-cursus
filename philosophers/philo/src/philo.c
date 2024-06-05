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

int	main(int argc, char *argv[])
{
	printf("Hello, World!\n");
	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	if (argc == 5)
	{
		printf("Number of philosophers: %d\n", atoi(argv[1]));
		printf("Time to die: %d\n", atoi(argv[2]));
		printf("Time to eat: %d\n", atoi(argv[3]));
		printf("Time to sleep: %d\n", atoi(argv[4]));
	}
	return (0);
}
