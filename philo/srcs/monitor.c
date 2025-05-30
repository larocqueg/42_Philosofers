/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:44:34 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:35 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	kill_philo(t_table *table, int i)
{
	pthread_mutex_lock(&table->write_mtx);
	set_arg(&table->table_mtx, &table->sim_end, 1);
	printf("%lld ", get_time() - table->start_time);
	printf("%s%d died\n%s", R, i + 1, RT);
	pthread_mutex_unlock(&table->write_mtx);
	pthread_mutex_unlock(&table->philos[i].philo_mtx);
}

int	philo_timeout(t_table *table, int i)
{
	return (get_time() - table->philos[i].last_meal >= table->time_to_die);
}

void	*monitor(void *arg)
{
	int		i;
	t_table	*table;

	table = arg;
	while (!get_arg(&table->table_mtx, &table->sim_start))
		usleep(500);
	while (!get_arg(&table->table_mtx, &table->sim_end))
	{
		i = 0;
		while (i < table->members)
		{
			pthread_mutex_lock(&table->philos[i].philo_mtx);
			if (table->philos[i].last_meal == -1 || table->philos[i].full)
				;
			else if (philo_timeout(table, i))
			{
				kill_philo(table, i);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philos[i].philo_mtx);
			i++;
		}
		usleep(10);
	}
	return (NULL);
}

int	start_monitor(t_table *table)
{
	int	return_value;

	return_value = pthread_create(&table->monitor, NULL, monitor, table);
	if (return_value == EINVAL || return_value == EAGAIN
		|| return_value == EPERM)
	{
		printf("%sError while creating thread monitor!\n%s", R, RT);
		return (0);
	}
	return (1);
}
