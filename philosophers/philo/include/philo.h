/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio.formiga <julio.formiga@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:18:28 by julio.formiga     #+#    #+#             */
/*   Updated: 2024/06/04 00:18:28 by julio.formiga    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_fork
{
	int		fork_id;
	t_mutex	fork;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	long		philo_n;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		meals_limit;
	long		simulation_start;
	bool		simulation_end;
	t_fork		*forks;
	t_philo		*philos;
}	t_table;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

void	ft_error(char *msg);
long	ft_atol(const char *str);
void	*safe_malloc(size_t size);
void	safe_mutex_handle(t_mutex *mutex, t_opcode opcode);
void	data_init(t_table *table);

#endif
