/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:20:41 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/01 15:30:14 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define RT  "\033[0m"
# define RED    "\033[1;31m"
# define G  "\033[1;32m"
# define Y  "\033[1;33m"

enum e_forks
{
	LEFT,
	RIGHT,
};

enum e_actions
{
	DEATH,
	EATING,
	SLEEPING,
	THINKING,
	FORK,
	FULL
};

struct	s_table;

typedef struct s_philo
{
	struct s_table	*table;
	long			id;
	long			meals;
	long			die_time;
	int				status;
	bool			full;
	pthread_mutex_t	lock;
	pthread_mutex_t	*fork[2];
}					t_philo;

typedef struct s_table
{
	pthread_t		*threads;
	t_philo			*philos;
	long			philos_count;
	long			die_time;
	long			eat_time;
	long			sleep_time;
	long			meals;
	long			start;
	long			philos_full;
	bool			ended;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	log;
	pthread_mutex_t	ended_lock;
}					t_table;

//actions.c
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

//philo_checks.c
bool		is_solo(t_philo *philo);
bool		is_dead(t_philo *philo);

//parsing.c
void		parsing(char **av, int ac);

//pargins_utils.c
int			is_space(char c);
int			is_digit(char c);

//routine.c
void		*routine(void *philo_ptr);
void		logs(t_philo *p, int status);

//utils.c
long		get_time(void);
void		wait_time(t_philo *philo, long time);
long		ft_atol(const char *nptr);
void		free_table(t_table *table);

//init.c
t_table		*init_table(int ac, char **av);

//meeting.c
int			meeting(t_table *table);

#endif
