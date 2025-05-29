/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:53:21 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 17:55:40 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_simulation(t_mtx *mtx, int *i)
{
	int	status;

	pthread_mutex_lock(mtx);
	status = *i;
	pthread_mutex_unlock(mtx);
	return (status);
}

void	*routine(void *arg)
{

}
