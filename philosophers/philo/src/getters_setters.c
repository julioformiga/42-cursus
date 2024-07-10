/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:13:50 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/10 17:13:50 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(t_mutex *mutex, bool *dest, bool value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}

bool	get_bool(t_mutex *mutex, bool *src)
{
	bool	value;

	safe_mutex_handle(mutex, LOCK);
	value = *src;
	safe_mutex_handle(mutex, UNLOCK);
	return (value);
}

void	set_long(t_mutex *mutex, long *dest, long value)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = value;
	safe_mutex_handle(mutex, UNLOCK);
}

long	get_long(t_mutex *mutex, long *src)
{
	long	value;

	safe_mutex_handle(mutex, LOCK);
	value = *src;
	safe_mutex_handle(mutex, UNLOCK);
	return (value);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->simulation_end));
}
