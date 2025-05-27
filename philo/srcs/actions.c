/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:52:56 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:52:57 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleeping(t_philo *philo)
{
	if (!is_dead(philo) && philo->status != SLEEPING)
	{
		philo->status = SLEEPING;
		logs(philo, philo->status);
		wait_time(philo, philo->table->sleep_time);
	}
}

void	thinking(t_philo *philo)
{
	long	time_left;

	if (!is_dead(philo) && philo->status != THINKING)
	{
		philo->status = THINKING;
		logs(philo, philo->status);
		pthread_mutex_lock(&philo->lock);
		time_left = philo->die_time - get_time();
		pthread_mutex_unlock(&philo->lock);
		if (time_left > philo->table->eat_time)
			wait_time(philo, philo->table->eat_time / 2);
		else
			wait_time(philo, 10);
	}
}

static bool	get_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(philo->fork[fork]);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(philo->fork[fork]);
		return (false);
	}
	logs(philo, FORK);
	return (true);
}

static bool	get_forks(t_philo *philo)
{
	if (!get_fork(philo, LEFT))
		return (false);
	if (!get_fork(philo, RIGHT))
	{
		pthread_mutex_unlock(philo->fork[LEFT]);
		return (false);
	}
	return (true);
}

void	eating(t_philo *philo)
{
	if (!get_forks(philo))
		return ;
	pthread_mutex_lock(&philo->lock);
	philo->die_time = get_time() + philo->table->die_time;
	pthread_mutex_unlock(&philo->lock);
	philo->status = EATING;
	logs(philo, philo->status);
	philo->meals++;
	wait_time(philo, philo->table->eat_time);
	pthread_mutex_unlock(philo->fork[LEFT]);
	pthread_mutex_unlock(philo->fork[RIGHT]);
}
