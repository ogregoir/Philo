/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:26:04 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 18:26:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
# include "utils/libft/libft.h"

typedef struct s_philo
{
	struct s_philo		*next;
	int					philo_n;
	pthread_mutex_t		*fork;
	pthread_t			thd;
	int					eat;
	int					must_eat;
	int					status;
	unsigned long		last_meal;
	struct s_global 	*data;
}t_philo;

typedef struct s_global
{
	int					philo_nbr;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	int					nbr_must_eat;
	unsigned long		time_today;
	unsigned long		time_to_start;
}t_global;



	/*UTILS*/
int				ft_verif_num(char **argv);
unsigned long	ft_time_today(void);
unsigned long	ft_time_today2(t_philo *philo);
void			ft_usleep(unsigned long time_wait);

	/*PARSE*/
t_philo			*ft_parse(t_global *data, t_philo *philo);
void			create_philo(t_global *data, t_philo *philo);
void			take_fork(t_philo *philo);
void			return_fork(t_philo *philo);

	/*ROUTINE*/
void			*start_routine(void *arg);

void			print_status(t_philo *philo, int philosopher, char *str);
int				philo_die(t_philo *philo);

int				philo_must_eat(t_philo *philo);

#endif