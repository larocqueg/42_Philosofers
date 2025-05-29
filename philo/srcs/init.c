/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:08:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 15:42:52 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_mutex(t_mtx *mtx)
{
	int	status;

	status = pthread_mutex_init(mtx, NULL);
	if (status == ENOMEM)
	{
		printf("%s%s%s", R, ENOMEM_ERR, RT);
		return (0);
	}
	else if (status == EINVAL)
	{
		printf("%s%s%s", R, EINVAL_ERR, RT);
		return (0);
	}
	if (status == 0)
		return (1);
	printf("%s%s%d%s", R, MUTEX_ERR, status, RT);
	return (0);
}

void	init_table(t_table **table, char **av, int ac)
{
	int	i;

	i = 1;
	*table = malloc(sizeof(t_table));
	if (!*table)
		ft_exit(1, RESOURCES);
	(*table)->philo_count = ft_atol(av[i++]);
	(*table)->time_to_die = ft_atol(av[i++]);
	(*table)->time_to_eat = ft_atol(av[i++]);
	(*table)->time_to_sleep = ft_atol(av[i++]);
	if (ac == 6)
		(*table)->meals = ft_atol(av[i]);
	else
		(*table)->meals = 0;
	(*table)->start_sim = 0;
	(*table)->philos = NULL;
	(*table)->philo_started = 0;
	if (!check_table(*table))
	{
		free(*table);
		exit(1);
	}
	check_mutex(*table);
}

void	init_forks(t_table *table)
{
	int	i;
	int	j;

	table->forks = (t_fork *)malloc(sizeof(t_fork) * table->philo_count);
	if (!table->forks)
		free_before_philos(table, RESOURCES);
	i = 0;
	while (i < table->philo_count)
	{
		if (!ft_init_mutex(&table->forks[i].fork))
		{
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&table->forks[j++].fork);
			}
			free_before_philos(table, FORK_MTX_ERR);
		}
		table->forks[i].fork_id = i;
		i++;
	}
}
