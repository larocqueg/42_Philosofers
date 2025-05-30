/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:44:43 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:44 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(t_table *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	table -> forks = (t_fork *)malloc(sizeof(t_fork) * table->members);
	if (!table -> forks)
		return (0);
	while (i < table -> members)
	{
		if (!ft_mutex_init(&table->forks[i].fork))
		{
			while (j < i)
			{
				pthread_mutex_destroy(&table->forks[j++].fork);
				printf("%sError initing fork mutexes!\n%s", R, RT);
			}
			return (0);
		}
		table->forks[i].fork_id = i;
		i++;
	}
	return (1);
}

void	assign_forks(t_table *table, t_philo *philo, t_fork *forks)
{
	if ((philo->index + 1) % 2 == 0)
	{
		philo->first_fork = &forks[philo->index];
		philo->second_fork = &forks[(philo->index + 1) % table->members];
	}
	else
	{
		philo->first_fork = &forks[(philo->index + 1) % table->members];
		philo->second_fork = &forks[philo->index];
	}
}

void	get_first_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	logs(philo, GET_FORK);
}

void	get_second_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->second_fork->fork);
	logs(philo, GET_FORK);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}
