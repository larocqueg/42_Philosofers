/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:08:47 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 13:24:00 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_mutex(t_mtx *mtx)
{
	int	status;

	status = pthread_mutex_init(mtx, NULL);
	if (status == ENOMEM)
	{
		printf("%s%s%s", R, ENOMEM_ERR, RT);
		return (0);
	}
	else if (status == EINVAL)
	{
		printf("%s%s%s", R, EINVAL_ERR, RT);
		return (0);
	}
	if (status == 0)
		return (1);
	printf("%s%s%d%s", R, MUTEX_ERR, status, RT);
	return (0);
}

void	init_table(t_table **table, char **av, int ac)
{
	int	i;

	i = 1;
	*table = malloc(sizeof(t_table));
	if (!*table)
		ft_exit(1, RESOURCES);
	(*table)->philo_count = ft_atol(av[i++]);
	(*table)->time_to_die = ft_atol(av[i++]);
	(*table)->time_to_eat = ft_atol(av[i++]);
	(*table)->time_to_sleep = ft_atol(av[i++]);
	if (ac == 6)
		(*table)->meals = ft_atol(av[i]);
	else
		(*table)->meals = -1;
	(*table)->start_sim = 0;
	(*table)->philos = NULL;
	(*table)->end_sim = 0;
	(*table)->philo_started = 0;
	if (!check_table(*table) || !ft_init_mutex(&(*table)->write_mtx))
	{
		free(*table);
		exit (1);
	}
}
