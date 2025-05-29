/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <gde-la-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:22:37 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/05/29 12:59:15 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
