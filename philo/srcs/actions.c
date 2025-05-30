/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:12:25 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:12:39 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	sleeping(t_philo *philo)
{
	if (ft_get_int(&philo->table->table_mtx, &philo->table->end_simulation))
		return (0);
	write_state(philo, SLEEPING);
	ft_usleep(philo->table->time_to_sleep, philo);
	if (ft_get_int(&philo->table->table_mtx, &philo->table->end_simulation))
		return (0);
	return (1);
}

int	think(t_philo *philo)
{
	int	time;

	if (ft_get_int(&philo->table->table_mtx, &philo->table->end_simulation))
		return (0);
	write_state(philo, THINKING);
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
	if (ft_get_int(&philo->table->table_mtx, &philo->table->end_simulation))
		return (0);
	get_first_fork(philo);
	get_second_fork(philo);
	pthread_mutex_lock(&philo->philo_mutex);
	write_state(philo, EATING);
	philo->last_eaten = get_time();
	philo->eaten++;
	if (philo->eaten == philo->table->must_eat)
		philo->full = 1;
	pthread_mutex_unlock(&philo->philo_mutex);
	ft_usleep(philo->table->time_to_eat, philo);
	release_forks(philo);
	if (ft_get_int(&philo->table->table_mtx, &philo->table->end_simulation))
		return (0);
	return (1);
}
