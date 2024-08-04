/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:36:12 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/13 03:36:12 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_die;
	long	t_eat_sleep;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	t_die = philo->table->time_to_die;
	if (philo->table->philo_n % 2 && philo->table->philo_n > 1)
	{
		t_die = 3 * philo->table->time_to_eat;
		t_eat_sleep = philo->table->time_to_eat + philo->table->time_to_sleep;
		if (t_die < 2 * t_eat_sleep)
			t_die = 2 * t_eat_sleep;
	}
	t_die = t_die / 1e3;
	if (elapsed > t_die)
	{
		write_status(DIED, philo);
		set_bool(&philo->philo_mutex, &philo->full, true);
		return (true);
	}
	return (false);
}

void	*monitor_dinner(void *data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!all_threads_running(&table->table_mutex, &table->threads_running,
			table->philo_n))
		usleep(1);
	while (!simulation_finished(table))
	{
		usleep(1);
		i = -1;
		while (++i < table->philo_n && !simulation_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				write_status(DIED, &table->philos[i]);
				set_bool(&table->table_mutex, &table->simulation_end, true);
				break ;
			}
		}
	}
	return (NULL);
}
