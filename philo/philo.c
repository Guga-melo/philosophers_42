/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:09:30 by gussoare          #+#    #+#             */
/*   Updated: 2022/11/10 08:55:42 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo(t_data *data)
{
	printf("number of philosophers--> %d\n", data->n_philo);
	printf("time to die--> %d\n", data->ttd);
	printf("time to eat--> %d\n", data->tte);
	printf("time to sleep--> %d\n", data->tts);
	if (data->n_meals)
		printf("number of meals to eat--> %d\n", data->n_meals);
	while (42)
	{
	}
	printf("number of philosophers--> %d\n", data->n_philo);
	printf("time to die--> %d\n", data->ttd);
	printf("time to eat--> %d\n", data->tte);
	printf("time to sleep--> %d\n", data->tts);
	if (data->n_meals )
		printf("number of meals to eat--> %d\n", data->n_meals);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		ft_init_data(&data, argv);
		philo(&data);
		ft_free_and_destroy(&data);
	}
	return (0);
}
