/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:53:20 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:53:22 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_forks(t_table *table, long i)
{
	while (i < (table->philos_count - 1))
	{
		if (i % 2)
		{
			table->philos[i].fork[LEFT] = &table->forks[i - 1];
			table->philos[i].fork[RIGHT] = &table->forks[i];
		}
		else
		{
			table->philos[i].fork[LEFT] = &table->forks[i];
			table->philos[i].fork[RIGHT] = &table->forks[i + 1];
		}
		i++;
	}
	if (i % 2)
	{
		table->philos[i].fork[LEFT] = &table->forks[i - 1];
		table->philos[i].fork[RIGHT] = &table->forks[i];
	}
	else
	{
		table->philos[i].fork[LEFT] = &table->forks[i];
		table->philos[i].fork[RIGHT] = &table->forks[0];
	}
}

static void	init_philos(t_table *table)
{
	long	i;

	i = -1;
	while (++i < table->philos_count)
	{
		table->philos[i].table = table;
		table->philos[i].id = i + 1;
		table->philos[i].meals = 0;
		table->philos[i].status = -1;
		table->philos[i].full = false;
		table->philos[i].die_time = table->die_time;
		pthread_mutex_init(&table->philos[i].lock, NULL);
	}
	init_forks(table, 0);
}

static t_table	*init_threads(t_table *table)
{
	long	i;

	table->ended = false;
	table->philos_full = 0;
	table->threads = malloc(table->philos_count * sizeof(pthread_t));
	table->forks = malloc(table->philos_count * sizeof(pthread_mutex_t));
	if (!table->threads || !table->forks)
		return (NULL);
	pthread_mutex_init(&table->lock, NULL);
	pthread_mutex_init(&table->log, NULL);
	pthread_mutex_init(&table->ended_lock, NULL);
	i = 0;
	while (i < table->philos_count)
		pthread_mutex_init(&table->forks[i++], NULL);
	return (table);
}

static int	check_init(t_table *table)
{
	if (!table->philos_count || !table->die_time
		|| !table->eat_time || !table->sleep_time)
		return (0);
	return (1);
}

t_table	*init_table(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philos_count = ft_atol(av[1]);
	table->die_time = ft_atol(av[2]);
	table->eat_time = ft_atol(av[3]);
	table->sleep_time = ft_atol(av[4]);
	if (ac == 6)
		table->meals = ft_atol(av[5]);
	else
		table->meals = 0;
	if (!check_init(table))
	{
		free(table);
		return (NULL);
	}
	table->start = 0;
	table->philos = malloc(table->philos_count * sizeof(t_philo));
	if (!table->philos)
		return (NULL);
	table = init_threads(table);
	init_philos(table);
	return (table);
}
