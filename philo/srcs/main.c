/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:04:49 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 13:18:32 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac != 5 && ac != 6)
		ft_exit(1, ARG_ERR);
	parsing(av, ac);
	init_table(&table, av, ac);
	//meeting(table);
	//free_table(table);
	return (0);
}
