/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:22:37 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 13:05:35 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_table(t_table *table)
{
	if (table->philo_count < 1 || table->philo_count > INT_MAX)
		return (printf("%s%s%s", R, INVALID, RT), 0);
	if (table->time_to_die < 1 || table->time_to_die > INT_MAX)
		return (printf("%s%s%s", R, INVALID, RT), 0);
	if (table->time_to_eat < 1 || table->time_to_eat > INT_MAX)
		return (printf("%s%s%s", R, INVALID, RT), 0);
	if (table->time_to_sleep < 1 || table->time_to_sleep > INT_MAX)
		return (printf("%s%s%s", R, INVALID, RT), 0);
	if (table->meals < 0 || table->meals > INT_MAX)
		return (printf("%s%s%s", R, INVALID, RT), 0);
	return (1);
}

void	check_mutex(t_table *table)
{
	if (!ft_init_mutex(&(*table)->table_mtx))
	{
		free(*table);
		exit(1);
	}
	if (!ft_init_mutex(&(*table)->write_mtx))
	{
		pthread_mutex_destroy(&(*table)->table_mtx);
		free(*table);
		exit (1);
	}
}

long	ft_atol(char *str)
{
	long	n;

	while (is_space(*str))
		str++;
	if (*str == '-')
		ft_exit(1, INVALID);
	else if (*str == '+')
		str++;
	n = 0;
	while (is_digit(*str))
		n = n * 10 + (*(str++) - '0');
	return (n);
}
