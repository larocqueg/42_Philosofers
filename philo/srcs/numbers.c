/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:45:24 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/30 13:45:25 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	long long	get_num(const char *str, int i, long sign)
{
	long long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			if (sign == -1)
				return (LLONG_MIN);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

long long	ft_atoll(char *str)
{
	long long	num;
	size_t		i;
	long		sign;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = get_num(str, i, sign);
	if (num > LLONG_MAX)
		return (LLONG_MAX);
	else if (num < LLONG_MIN)
		return (LLONG_MIN);
	return (num);
}
