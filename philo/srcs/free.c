/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:44:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:47 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_table_mutex(t_table *table)
{
	pthread_mutex_destroy(&table->table_mtx);
	pthread_mutex_destroy(&table->write_mtx);
}

void	free_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	free(table->forks);
}

void	free_all(t_table *table)
{
	int	i;

	i = 0;
	free_table_mutex(table);
	while (i < table->philo_count)
	{
		pthread_mutex_destroy(&table->philos[i].philo_mtx);
		i++;
	}
	free_forks(table);
	free(table->philos);
}
