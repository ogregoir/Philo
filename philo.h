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
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					philo_n;
	pthread_mutex_t		*fork;
	pthread_t			thd;
	int					eat;
	int					must_eat;
	unsigned long		last_meal;
	pthread_mutex_t		*mutex_data;
	pthread_mutex_t		mutex_print;
	struct s_global		*data;
}	t_philo;

typedef struct s_global
{
	int					status;
	pthread_mutex_t		mutex_die;
	int					philo_nbr;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	int					nbr_must_eat;
	unsigned long		time_today;
	unsigned long		time_to_start;

}	t_global;

/* UTILS */
int				ft_verif_num(char **argv);
unsigned long	ft_time_today(void);
unsigned long	ft_time_today2(t_philo *philo);
void			ft_usleep(unsigned long time_wait);
void			ft_error(char *str);

int				ft_atoi(char *str);
int				ft_isdigit(int i);
void			ft_free_all(t_philo *philo, t_global *data);
void			ft_if(t_philo *philo);

/* PARSE */
t_philo			*ft_parse(t_global *data, t_philo *philo);
void			create_philo(t_global *data, t_philo *philo);
void			take_fork(t_philo *philo);
void			return_fork(t_philo *philo);

/* ROUTINE */
void			*start_routine(void *arg);

void			print_status(t_philo *philo, int philosopher, char *str);
int				philo_die(t_philo *philo);
void			ft_dead(t_philo *philo);
int				philo_must_eat(t_philo *philo);

#endif
