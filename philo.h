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

typedef struct s_global
{
	int					philo_nbr;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	unsigned long		time_today;
}t_global;

typedef struct s_philo
{
	struct s_philo	*next;
	int				philo_n;
	int				fork;
	int				id;
	pthread_t		thd;
}t_philo;

	/*UTILS*/
int		ft_verif_num(char **argv);
int		ft_time_today(void);

	/*PARSE*/
void	create_philo(t_global *data, t_philo *philo);

	/*ROUTINE*/
void	*start_routine(void *arg);

#endif