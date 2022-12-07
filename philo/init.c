/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:38:07 by gussoare          #+#    #+#             */
/*   Updated: 2022/12/07 14:00:57 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data)
{
	int	i;

	i = data->n_philo;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].l_fork = i;
		data->philo[i].r_fork = (i + 1) % data->n_philo;
		data->philo[i].meals_had = 0;
		data->philo[i].data = data;
	}
}

void	ft_init_mutex(t_data *data)
{
	int	i;

	i = data->n_philo;
	while (--i >= 0)
		pthread_mutex_init(&(data->fork[i]), NULL);
	pthread_mutex_init(&(data->meal), NULL);
	pthread_mutex_init(&(data->log), NULL);
}

void	ft_init_data(t_data *data, char **argv)
{
	if (!ft_check_argv(argv))
	{
		printf("Error\nInvalid arguments");
		exit(EXIT_FAILURE);
	}
	data->n_philo = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argv[5])
		data->n_meals = ft_atoi(argv[5]);
	else
		data->n_meals = -1;
	data->died = 0;
	data->total_ate = 0;
	data->fork = malloc(data->n_philo * sizeof(pthread_mutex_t));
	data->philo = malloc(data->n_philo * sizeof(t_philo));
	ft_init_mutex(data);
	ft_init_philo(data);
}
