/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:24:51 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/28 23:36:17 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_len(char *str)
{
	int		i;
	int		start;
	int		end;
	bool	sig;

	i = 0;
	sig = false;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		sig = true;
		i++;
	}
	while (is_zero(str[i]))
		i++;
	start = i;
	while (is_digit(str[i]))
		i++;
	end = i;
	if ((end - start > 10 && !sig) || (end - start > 11 && sig))
		return (0);
	return (1);
}

static int	check_chars(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	if (!is_digit(str[i]))
		return (0);
	while (is_digit(str[i]))
		i++;
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

void	parsing(char **av, int ac)
{
	int	i;

	i = 0;
	while (++i && i < ac)
	{
		if (!check_chars(av[i]) || !check_len(av[i]))
			ft_exit(1, INVALID);
	}
}
