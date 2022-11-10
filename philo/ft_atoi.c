/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:23:03 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/24 10:41:51 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	found;
	int		val;

	val = 1;
	found = 0;
	while (ft_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			val = -1;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
		found = (found * 10) + *str++ - 48;
	return (val * found);
}
