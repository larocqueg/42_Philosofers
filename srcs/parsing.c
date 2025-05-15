/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:55 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/15 14:59:23 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_len(char *str)
{
	int		i;
	int		j;
	bool	neg;

	i = 0;
	neg = false;
	while (is_space(str[i]))
		i++;
	j = i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = true;
		i++;
	}
	while (is_digit(str[j]))
		j++;
	if ((j - i > 20 && neg == true) || (j - i > 19 && neg == false))
	{
		printf("j - i = %d && str = %s\n", (j - i), str);
		printf(RED"Invalid arg: Use only positive integers!\n"RST);
		exit(EXIT_FAILURE);
	}
	return ;
}

static void	check_chars(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (is_digit(str[i]))
		i++;
	while (is_space(str[i]))
		i++;
	if (str[i])
	{
		printf(RED"Invalid arg: Use only positive integers!\n"RST);
		exit(EXIT_FAILURE);
	}
	return ;
}

static void	check_args(char **av, int ac)
{
	int	i;

	i = 0;
	while (++i && i < ac)
	{
		check_chars(av[i]);
		check_len(av[i]);
	}
}

void	parsing(char **av, int ac)
{
	check_args(av, ac);
}
