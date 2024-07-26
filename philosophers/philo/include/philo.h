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

# define DEBUG	0

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

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
	t_mutex		philo_mutex;
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
	bool		threads_ready;
	long		threads_running;
	pthread_t	monitor;
	t_mutex		table_mutex;
	t_mutex		write_mutex;
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

typedef enum e_timecode
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_timecode;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}	t_philo_status;

void	ft_error(char *msg);
long	ft_atol(const char *str);
void	*safe_malloc(size_t size);
void	safe_mutex_handle(t_mutex *mutex, t_opcode opcode);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
			t_opcode opcode);
void	parse_input(t_table *table, char **argv);
void	data_init(t_table *table);
void	dinner_start(t_table *table);
void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
void	set_long(t_mutex *mutex, long *dest, long value);
long	get_long(t_mutex *mutex, long *value);
bool	simulation_finished(t_table *table);
void	desync_all_threads(t_philo *philo);

void	thinking(t_philo *philo, bool pre_simulation);
void	wait_all_threads(t_table *table);
void	*dinner_simulation(void *data);
long	gettime(t_timecode timecode);
void	write_status(t_philo_status status, t_philo *philo);
bool	all_threads_running(t_mutex *mutex, long *threads, long philo_n);
void	*monitor_dinner(void *data);
void	increase_long(t_mutex *mutex, long *value);
void	precise_usleep(long usec, t_table *table);
void	clean(t_table *table);
void	print_data_table(t_table *table);
#endif
