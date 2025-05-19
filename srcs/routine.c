/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:53:27 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:53:28 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	logs(t_philo *p, int status)
{
	pthread_mutex_lock(&p->table->log);
	if (status == DEATH && !p->table->ended)
		printf(RED"%lu %lu died\n"RT, get_time() - p->table->start, p->id);
	else if (status == EATING && !p->table->ended)
		printf(G"%lu %lu is eating\n"RT, get_time() - p->table->start, p->id);
	else if (status == SLEEPING && !p->table->ended)
		printf(G"%lu %lu is sleeping\n"RT, get_time() - p->table->start, p->id);
	else if (status == THINKING && !p->table->ended)
		printf(G"%lu %lu is thinking\n"RT, get_time() - p->table->start, p->id);
	else if (status == FORK && !p->table->ended)
		printf(G"%lu %lu has taken a fork\n"RT,
			get_time() - p->table->start, p->id);
	pthread_mutex_unlock(&p->table->log);
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	pthread_mutex_lock(&philo->lock);
	philo->die_time = philo->table->start + philo->table->die_time;
	pthread_mutex_unlock(&philo->lock);
	if (philo->id % 2 == 0 || philo->id == philo->table->philos_count)
		thinking(philo);
	if (is_solo(philo))
		return (NULL);
	while (!is_dead(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
