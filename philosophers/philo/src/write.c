/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:30:41 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/11 01:30:41 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo,
		long elapsed)
{
	if (status == TAKE_FIRST_FORK && !simulation_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken a 1st fork 🍽️\n", elapsed, philo->id);
	else if (status == TAKE_SECOND_FORK && !simulation_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken a 2nd fork 🍽️\n", elapsed, philo->id);
	else if (status == EATING && !simulation_finished(philo->table))
		printf(W"%-6ld"C" %d is eating\t\t (%ld times)\n", elapsed, philo->id,
			philo->meals_counter);
	else if (status == SLEEPING && !simulation_finished(philo->table))
		printf(W"%-6ld"RST" %d is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(philo->table))
		printf(W"%-6ld"RST" %d is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf(W"%-6ld"RST" %d died\n", elapsed, philo->id);
	else
		printf(W"%-6ld"RST" %d has finished\n", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = gettime(MILLISECOND) - philo->table->simulation_start;
	if (philo->full)
		return ;
	safe_mutex_handle(&philo->table->write_mutex, LOCK);
	if (DEBUG)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			&& !simulation_finished(philo->table))
			printf("%ld %d has taken a fork\n", elapsed, philo->id);
		else if (status == EATING && !simulation_finished(philo->table))
			printf("%ld %d is eating\n", elapsed, philo->id);
		else if (status == SLEEPING && !simulation_finished(philo->table))
			printf("%ld %d is sleeping\n", elapsed, philo->id);
		else if (status == THINKING && !simulation_finished(philo->table))
			printf("%ld %d is thinking\n", elapsed, philo->id);
		else if (status == DIED)
			printf("%ld %d - died\n", elapsed, philo->id);
		else
			printf("%ld %d - finished\n", elapsed, philo->id);
	}
	safe_mutex_handle(&philo->table->write_mutex, UNLOCK);
}
