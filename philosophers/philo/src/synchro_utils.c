/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:22:54 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/10 17:22:54 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->threads_ready))
		usleep(1);
}

void	desync_all_threads(t_philo *philo)
{
	if (philo->table->philo_n % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(philo->table->time_to_eat, philo->table);
	}
	else
	{
		if (philo->id % 2 == 1)
			thinking(philo, true);
	}
}

bool	all_threads_running(t_mutex *mutex, long *threads, long philo_n)
{
	bool	ret;

	ret = false;
	safe_mutex_handle(mutex, LOCK);
	if (*threads == philo_n)
		ret = true;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}

void	increase_long(t_mutex *mutex, long *value)
{
	safe_mutex_handle(mutex, LOCK);
	(*value)++;
	safe_mutex_handle(mutex, UNLOCK);
}
