/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:52:42 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:52:43 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table		*table;

	if ((ac != 5 && ac != 6))
	{
		printf("Error: Invalid arguments\n");
		return (0);
	}
	parsing(av, ac);
	table = init_table(ac, av);
	if (!table)
	{
		free_table(table);
		return (1);
	}
	meeting(table);
	free_table(table);
}
