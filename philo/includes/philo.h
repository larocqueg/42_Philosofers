/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 00:03:17 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 00:04:41 by gde-la-r         ###   ########.fr       */
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
	long			id;
	long			last_meal;
	int				meals_count;
	bool			full;
	t_fork			*first_fork;
	t_fork			*second_fork;
	t_table			*table;
	t_mtx			philo_mtx;
}	t_philo;

typedef struct s_table
{
	bool			philo_started;
	bool			start_simulation;
	bool			end_simulation;
	long			philo_count;
	long			start_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals;
	t_fork			*forks;
	t_philo			*philos;
	t_mtx			write_mtx;
	t_mtx			table_mtx;
	pthread_t		monitor;
}	t_table;

//parsing.c
void	parsing(char **av, int ac);

//chars.c
int		is_space(char c);
int		is_digit(char c);
int		is_zero(char c);

//init.c
void	init_table(t_table **table, char **av, int ac);

//utils.c
long	ft_atol(char *str);
bool	check_table(t_table *table);

//exit.c
void	ft_exit(int value, char *str);

# define ARG_ERR     "Error: Missing command line argument!\n"
# define INVALID     "Error: Only positive integers are allowed!\n"
# define RESOURCES "Error: Not enough resources!\n"

#endif
