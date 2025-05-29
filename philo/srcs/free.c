/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:03:16 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 16:06:28 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_before_philos(t_table *table, char *str)
{
	pthread_mutex_destroy(&table->table_mtx);
	pthread_mutex_destroy(&table->write_mtx);
	free(table);
	if (str && *str)
		ft_exit(1, str);
	exit(1);
}
