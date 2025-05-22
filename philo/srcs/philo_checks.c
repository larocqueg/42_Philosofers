/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:48:25 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:48:57 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	is_full(t_philo	*philo)
{
	if (philo->meals >= philo->table->meals
		&& philo->table->meals != 0 && !philo->full)
	{
		philo->table->philos_full++;
		philo->full = true;
	}
}

bool	is_dead(t_philo *philo)
{
	bool	dead;

	dead = false;
	pthread_mutex_lock(&philo->lock);
	pthread_mutex_lock(&philo->table->ended_lock);
	if (get_time() >= philo->die_time || philo->table->ended)
	{
		if (!philo->table->ended)
			logs(philo, DEATH);
		philo->table->ended = true;
	}
	pthread_mutex_lock(&philo->table->lock);
	is_full(philo);
	if (philo->table->philos_full == philo->table->philos_count)
		philo->table->ended = true;
	dead = philo->table->ended;
	pthread_mutex_unlock(&philo->table->lock);
	pthread_mutex_unlock(&philo->table->ended_lock);
	pthread_mutex_unlock(&philo->lock);
	return (dead);
}

bool	is_solo(t_philo *philo)
{
	if (philo->table->philos_count == 1)
	{
		pthread_mutex_lock(philo->fork[RIGHT]);
		logs(philo, FORK);
		pthread_mutex_unlock(philo->fork[RIGHT]);
		logs(philo, THINKING);
		while (!is_dead(philo))
			;
		return (true);
	}
	return (false);
}
