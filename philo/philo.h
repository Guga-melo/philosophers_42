/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:15:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/11/09 10:22:10 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
	int		id;
	int		l_fork;
	int		r_fork;
	int		meals_had;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				n_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				n_meals;
	pthread_mutex_t	*fork;
	pthread_mutex_t *meal;
	t_philo			*philo;
}				t_data;

void	ft_init_data(t_data *data, char **argv);
void	ft_init_mutex(t_data *data);
void	ft_init_philo(t_data *data);
int		ft_check_argv(char **str);
int		ft_atoi(const char *str);
void	philo(t_data *data);
void	ft_free_and_destroy(t_data *data);

#endif
