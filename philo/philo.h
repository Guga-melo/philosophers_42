/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:15:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/12/12 08:08:33 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				meals_had;
	unsigned long	last_meal;
	struct s_data	*data;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_data
{
	int					n_philo;
	int					ttd;
	int					tte;
	int					tts;
	int					n_meals;
	int					total_ate;
	int					died;
	unsigned long		start_time;
	int					*fork_id;
	pthread_mutex_t		meal;
	pthread_mutex_t		log;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}						t_data;

void			ft_init_data(t_data *data, char **argv);
void			ft_init_mutex(t_data *data);
void			ft_init_philo(t_data *data);
int				ft_check_argv(char **str);
int				ft_atoi(const char *str);
void			philo(t_data *data);
void			destroy_mutex(t_philo *philo);
unsigned long	timestamp(void);
void			time_spent(t_data *data, int action);
void			eating(t_philo *philo);
void			print_message(t_data *data, int id, char *action);
void			check_welfare(t_philo *p, t_data *data);
void			free_all(t_philo *p, pthread_mutex_t *f);

#endif
