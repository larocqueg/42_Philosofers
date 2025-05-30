/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:44:51 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:52 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_arg(t_mtx *mutex, int *variable)
{
	int	get;

	pthread_mutex_lock(mutex);
	get = *variable;
	pthread_mutex_unlock(mutex);
	return (get);
}

void	set_arg(t_mtx *mutex, int *variable, int newvalue)
{
	pthread_mutex_lock(mutex);
	*variable = newvalue;
	pthread_mutex_unlock(mutex);
}