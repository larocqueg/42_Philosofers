/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meeting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:39:21 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/19 13:39:50 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	meeting(t_table *table)
{
	long	n;

	table->start = get_time();
	if (!table->start)
		return (1);
	pthread_mutex_lock(&table->lock);
	n = 0;
	while (n < table->philos_count)
	{
		if (pthread_create(&table->threads[n], NULL,
				&routine, &table->philos[n]))
			return (pthread_mutex_unlock(&table->lock), 1);
		n++;
	}
	pthread_mutex_unlock(&table->lock);
	n = 0;
	while (n < table->philos_count)
	{
		if (pthread_join(table->threads[n], NULL))
			return (1);
		n++;
	}
	return (0);
}
