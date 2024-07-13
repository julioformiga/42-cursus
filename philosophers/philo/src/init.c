/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:19:49 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/09 00:19:49 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(t_table *table)
{
	int		i;

	i = -1;
	while (++i < table->philo_n)
	{
		table->philos[i].id = i + 1;
		table->philos[i].full = false;
		table->philos[i].meals_counter = 0;
		table->philos[i].table = table;
		safe_mutex_handle(&table->philos[i].philo_mutex, INIT);
		table->philos[i].last_meal_time = gettime(MILLISECOND);
		table->philos[i].first_fork = &table->forks[(i + 1) % table->philo_n];
		table->philos[i].second_fork = &table->forks[i];
		if (table->philos[i].id % 2 == 0)
		{
			table->philos[i].first_fork = &table->forks[i];
			table->philos[i].second_fork = &table->forks[(i + 1)
				% table->philo_n];
		}
	}
}

void	data_init(t_table *table)
{
	int	i;

	table->simulation_end = false;
	table->threads_ready = false;
	table->threads_running = 0;
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_n);
	safe_mutex_handle(&table->table_mutex, INIT);
	safe_mutex_handle(&table->write_mutex, INIT);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_n);
	i = -1;
	while (++i < table->philo_n)
	{
		safe_mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}
