/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:46:26 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:46:36 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>
# include <limits.h>

# define RT  "\033[0m"
# define R    "\033[1;31m"
# define G  "\033[1;32m"
# define Y  "\033[1;33m"

struct					s_table;
typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	GET_FORK,
}	t_state;

typedef struct s_fork
{
	t_mtx		fork;
	int			fork_id;
}	t_fork;

typedef struct s_philo
{
	pthread_t		philo_thread;
	int				index;
	long long		last_meal;
	int				meals_counter;
	int				full;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_table			*table;
	t_mtx			philo_mtx;
}	t_philo;

typedef struct s_table
{
	int				philo_count;
	int				philo_started;
	int				start_simulation;
	int				end_simulation;
	long long		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	t_fork			*forks;
	t_philo			*philos;
	t_mtx			write_mtx;
	t_mtx			table_mtx;
	pthread_t		monitor;
}	t_table;

int			valid_input(int ac, char **av, t_table *table);
int			parsing(int ac, char **av, t_table *table);
int			get_input(char **av, t_table *table);
int			ft_is_numeric(char *num_str);
int			ft_mutex_init(t_mtx *mutex);
int			init_forks(t_table *table);
int			start_monitor(t_table *table);
int			ft_init_thread(pthread_t *thread, t_philo *arg);
int			sleeping(t_philo *philo);
int			think(t_philo *philo);
int			eating(t_philo *philo);
int			get_arg(t_mtx *mutex, int *variable);
void		assign_forks(t_table *table, t_philo *philo, t_fork *forks);
void		write_state(t_philo *philo, t_state state);
void		ft_usleep(int time, t_philo *philo);
void		*routine(void *data);
void		set_arg(t_mtx *mutex, int *variable, int newvalue);
void		free_table_mutex(t_table *table);
void		free_forks(t_table *table);
void		free_all(t_table *table);
void		get_first_fork(t_philo *philo);
void		get_second_fork(t_philo *philo);
void		release_forks(t_philo *philo);
long long	get_time(void);
long long	ft_atoll(char *str);

#endif
