/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:09:30 by gussoare          #+#    #+#             */
/*   Updated: 2022/12/12 09:24:45 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *p)
{
	t_data	*data;

	data = p->data;
	pthread_mutex_lock(&(data->fork[p->l_fork]));
	print_message(data, p->id, "has taken a fork");
	pthread_mutex_lock(&(data->fork[p->r_fork]));
	print_message(data, p->id, "has taken a fork");
	pthread_mutex_lock(&(data->meal));
	print_message(data, p->id, "is eating");
	p->last_meal = timestamp();
	pthread_mutex_unlock(&(data->meal));
	time_spent(data, data->tte);
	p->meals_had++;
	if (p->meals_had == data->n_meals)
		data->total_ate++;
	pthread_mutex_unlock(&(data->fork[p->l_fork]));
	pthread_mutex_unlock(&(data->fork[p->r_fork]));
	print_message(data, p->id, "is sleeping");
	usleep(data->tts);
	//pthread_mutex_lock(&(data->meal));
	//time_spent(data, data->tts);
	//pthread_mutex_unlock(&(data->meal));
	print_message(data, p->id, "is thinking");
}

void	*pthread(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2)
		usleep(100);
	while (42)
	{
		pthread_mutex_lock(&(data->meal));
		pthread_mutex_lock(&(data->log));
		if (data->total_ate == data->n_philo || data->died == 1)
		{
			pthread_mutex_unlock(&(data->meal));
			pthread_mutex_unlock(&(data->log));
			break ;
		}
		pthread_mutex_unlock(&(data->meal));
		pthread_mutex_unlock(&(data->log));
		eating(philo);
	}
	return (NULL);
}

void	check_welfare(t_philo *p, t_data *data)
{
	int	i;

	i = 0;
	while (42)
	{
		pthread_mutex_lock(&(data->meal));
		if (data->total_ate == data->n_philo)
		{
			pthread_mutex_unlock(&(data->meal));
			break ;
		}
		if (timestamp() - p[i].last_meal >= (unsigned long)data->ttd)
		{
			pthread_mutex_lock(&(data->log));
			data->died = 1;
			printf("%lums %d died\n", timestamp() - data->start_time, \
				   	p[i].id + 1);
			pthread_mutex_unlock(&(data->meal));
			pthread_mutex_unlock(&(data->log));
			break ;
		}
		pthread_mutex_unlock(&(data->meal));
		i = (i + 1) % data->n_philo;
		usleep(500);
	}
}

void	philo(t_data *data)
{
	t_philo	*p;
	int		i;

	i = -1;
	p = data->philo;
	data->start_time = timestamp();
	while (++i < data->n_philo)
	{
		pthread_create(&(p[i].thread_id), NULL, pthread, &p[i]);	
		pthread_mutex_lock(&(data->meal));
		p[i].last_meal = timestamp();
		pthread_mutex_unlock(&(data->meal));
	}
	check_welfare(p, data);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(p[i].thread_id, NULL);
	destroy_mutex(p);
	free_all(p, p->data->fork);
}
