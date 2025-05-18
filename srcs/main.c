/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:52:42 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:52:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	meeting(t_table *table);

int	main(int ac, char **av)
{
	t_table		*table;

	if ((ac != 5 && ac != 6))
	{
		printf("Error: Invalid arguments\n");
		return (0);
	}
	parsing(av, ac);
	table = init_table(ac, av);
	if (!table)
	{
		free_table(table);
		return (1);
	}
	meeting(table);
	free_table(table);
}

static int	meeting(t_table *table)
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
