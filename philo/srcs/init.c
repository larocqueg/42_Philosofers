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
	if (!check_table(*table))
	{
		free(*table);
		ft_exit(1, INVALID);
	}
}
