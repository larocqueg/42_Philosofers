/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:44:38 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:44:39 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_get_fork(t_philo *philo)
{
	printf("%lld ", get_time() - philo->table->start_time);
	printf("%s%d has taken a fork\n%s", G, philo->index + 1, RT);
}

void	print_eating(t_philo *philo)
{
	printf("%lld ", get_time() - philo->table->start_time);
	printf("%s%d is eating\n%s", G, philo->index + 1, RT);
}

void	print_sleeping(t_philo *philo)
{
	printf("%lld ", get_time() - philo->table->start_time);
	printf("%s%d is sleeping\n%s", G, philo->index + 1, RT);
}

void	print_thinking(t_philo *philo)
{
	printf("%lld ", get_time() - philo->table->start_time);
	printf("%s%d is thinking\n%s", G, philo->index + 1, RT);
}

void	logs(t_philo *philo, t_state state)
{
	pthread_mutex_lock(&philo->table->write_mtx);
	if (get_arg(&philo->table->table_mtx, &philo->table->sim_end))
	{
		pthread_mutex_unlock(&philo->table->write_mtx);
		return ;
	}
	if (state == GET_FORK)
		print_get_fork(philo);
	else if (state == EATING)
		print_eating(philo);
	else if (state == SLEEPING)
		print_sleeping(philo);
	else if (state == THINKING)
		print_thinking(philo);
	pthread_mutex_unlock(&philo->table->write_mtx);
}
