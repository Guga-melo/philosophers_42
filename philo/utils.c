/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:19:27 by gussoare          #+#    #+#             */
/*   Updated: 2022/12/12 08:34:07 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *p, pthread_mutex_t *f)
{
	if (p)
		free(p);
	if (f)
		free(f);
}

void	time_spent(t_data *data, int action)
{
	unsigned long	time;

	time = timestamp();
	while (!data->died)
	{
		if (timestamp() - time >= (unsigned long)action)
			break ;
		usleep(50);
	}
}

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->n_philo)
		pthread_mutex_destroy(&(philo->data->fork[i]));
	pthread_mutex_destroy(&(philo->data->meal));
	pthread_mutex_destroy(&(philo->data->log));
}

void	print_message(t_data *data, int id, char *action)
{
	unsigned long	time;

	//pthread_mutex_lock(&(data->log));
	time = timestamp() - data->start_time;
	if (!data->died)
		printf("%lums  %d %s\n", time, id + 1, action);
	//pthread_mutex_unlock(&(data->log));
}

unsigned long	timestamp(void)
{
	struct timeval	tv;
	unsigned long	s;
	unsigned long	u;
	unsigned long	t;

	gettimeofday(&tv, NULL);
	s = tv.tv_sec * 1000;
	u = tv.tv_usec / 1000;
	t = s + u;
	return (t);
}
