/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:15:22 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:15:40 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	get_first_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_state(philo, GET_FORK);
}

void	get_second_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->second_fork->fork);
	write_state(philo, GET_FORK);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}
