/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:09:30 by gussoare          #+#    #+#             */
/*   Updated: 2022/12/01 13:24:43 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating(t_philo *p)
{
	t_data *data;

	data = p->data;
	pthread_mutex_lock(&(data->fork[p->l_fork]));	
	print_message(data, p->id, time_spent(data), "has taken a fork");
	pthread_mutex_lock(&(data->fork[p->r_fork]));
	print_message(data, p->id, time_spent(data), "has taken a fork");
	print_message(data, p->id, time_spent(data), "is eating");
	usleep(data->tte * 1000);
	p->last_meal = timestamp();
	p->meals_had++;
	if (p->meals_had == data->n_meals)
		data->total_ate++;
	pthread_mutex_unlock(&(data->fork[p->l_fork]));
	pthread_mutex_unlock(&(data->fork[p->r_fork]));
	print_message(data, p->id, time_spent(data), "is sleeping");
	usleep(data->tts * 1000);
	print_message(data, p->id, time_spent(data), "is thinking");
}

void *pthread(void *p)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;

	if (philo->id % 2)
		usleep(10000);
	while (!(data->died))
	{
		if (data->total_ate == data->n_philo)
			break ;
		eating(philo);
	}
	return (NULL);
}

void check_welfare(t_philo *p, t_data *data)
{
	int i;

	i = 0;
	while (42)
	{
		if (data->total_ate == data->n_philo)
			break ;
		if (timestamp() - p[i].last_meal > (unsigned long)data->ttd)
		{
			data->died = 1;
			printf("%lums %d died\n", time_spent(data), p[i].id + 1);
			break ;
		}
		i = (i + 1) % data->n_philo;
		usleep(500);
	}
}

void philo(t_data *data)
{
	t_philo *p;
	int i;

	i = -1;
	p = data->philo;
	printf("number of philosophers--> %d\n", data->n_philo);
	printf("time to die--> %d\n", data->ttd);
	printf("time to eat--> %d\n", data->tte);
	printf("time to sleep--> %d\n", data->tts);
	if (data->n_meals)
		printf("number of meals to eat--> %d\n", data->n_meals);
	data->start_time = timestamp();
	while (++i < data->n_philo)
	{
		pthread_create(&(p[i].thread_id), NULL, pthread, &p[i]);
		p[i].last_meal = timestamp();
	}
	check_welfare(p, data);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(p[i].thread_id, NULL);
	destroy_mutex(p);
	free_all(p, p->data->fork);
}
