/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 03:23:55 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 03:23:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
char    *ft_philo_eat(t_philo *philo, t_global *data)
{
	
}*/

void	*start_routine(void *arg)
{
	int	philo_id;

	philo_id = *((int *)arg);
	(void)philo_id;
	pthread_exit(EXIT_SUCCESS);
}
