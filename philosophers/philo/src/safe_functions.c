/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 00:22:25 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/07/09 00:22:25 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error("Malloc failed.");
	return (ptr);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK
			|| opcode == DESTROY))
		ft_error("Invalid mutex.");
	else if (status == EINVAL && opcode == INIT)
		ft_error("Invalid mutex attributes.");
	else if (status == EDEADLK)
		ft_error("A deadlock condition was detected.");
	else if (status == EPERM)
		ft_error("The current thread does not hold the mutex.");
	else if (status == ENOMEM)
		ft_error("The process does not have enough memory \
			to initialize the mutex.");
	else if (status == EBUSY)
		ft_error("Mutex is locked.");
}

void	safe_mutex_handle(t_mutex *mutex, t_opcode opcode)
{
	if (opcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		ft_error("Invalid mutex opcode.");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK
			|| opcode == DESTROY))
		ft_error("Invalid mutex.");
	else if (status == EINVAL && opcode == INIT)
		ft_error("Invalid mutex attributes.");
	else if (status == EDEADLK)
		ft_error("A deadlock condition was detected.");
	else if (status == EPERM)
		ft_error("The current thread does not hold the mutex.");
	else if (status == EBUSY || status == EAGAIN)
		ft_error("Mutex is locked.");
	else
		ft_error("Unknown mutex error.");
}

void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
						t_opcode opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		ft_error("Wrong opcode for thread_handle");
}
