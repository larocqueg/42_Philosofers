/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:53:34 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:53:35 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_time(t_philo *philo, long time)
{
	long	start;

	start = get_time();
	while (!is_dead(philo) && (get_time() - start) < time)
		usleep(100);
}

long	get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
	{
		printf("ERROR: gettimeofday()");
		return (0);
	}
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long	ft_atol(const char *nptr)
{
	long	sign;
	long	result;
	int		i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	free_table(t_table *table)
{
	long	i;

	if (!table)
		return ;
	i = -1;
	while (++i < table->philos_count)
	{
		if (i + 1 == table->philos_count
			&& table->philos_full >= table->philos_count)
			printf(Y"All philos are full!\n"RT);
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].lock);
	}
	pthread_mutex_destroy(&table->lock);
	pthread_mutex_destroy(&table->log);
	pthread_mutex_destroy(&table->ended_lock);
	if (table->threads)
		free(table->threads);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
}
