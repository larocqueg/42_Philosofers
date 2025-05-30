/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:44:27 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:29 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	sleeping(t_philo *philo)
{
	if (get_arg(&philo->table->table_mtx, &philo->table->sim_end))
		return (0);
	logs(philo, SLEEPING);
	ft_usleep(philo->table->time_to_sleep, philo);
	if (get_arg(&philo->table->table_mtx, &philo->table->sim_end))
		return (0);
	return (1);
}

int	think(t_philo *philo)
{
	int	time;

	if (get_arg(&philo->table->table_mtx, &philo->table->sim_end))
		return (0);
	logs(philo, THINKING);
	time = philo->table->time_to_die - philo->table->time_to_eat
		- philo->table->time_to_sleep;
	if (time > 100)
	{
		ft_usleep(10, philo);
	}
	return (1);
}

int	eating(t_philo *philo)
{
	if ((philo->full))
		return (0);
	if (get_arg(&philo->table->table_mtx, &philo->table->sim_end))
		return (0);
	get_first_fork(philo);
	get_second_fork(philo);
	pthread_mutex_lock(&philo->philo_mtx);
	logs(philo, EATING);
	philo->last_meal = get_time();
	philo->meals_counter++;
	if (philo->meals_counter == philo->table->must_eat)
		philo->full = 1;
	pthread_mutex_unlock(&philo->philo_mtx);
	ft_usleep(philo->table->time_to_eat, philo);
	release_forks(philo);
	if (get_arg(&philo->table->table_mtx, &philo->table->sim_end))
		return (0);
	return (1);
}
