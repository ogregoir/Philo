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

void	philo_eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(philo->mutex_data);
	philo->eat = 1;
	philo->must_eat += 1;
	pthread_mutex_unlock(philo->mutex_data);
	print_status(philo, philo->philo_n, "is eating\n");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(philo->mutex_data);
	philo->last_meal = ft_time_today2(philo);
	philo->eat = 0;
	pthread_mutex_unlock(philo->mutex_data);
	return_fork(philo);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, philo->philo_n, "is sleeping\n");
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo, philo->philo_n, "is thinking\n");
}

void	*start_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->philo_n % 2 == 1)
		ft_usleep(10);
	pthread_mutex_lock(&philo->data->mutex_die);
	while (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->mutex_die);
		philo_eat(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&philo->data->mutex_die);
	}
	pthread_mutex_unlock(&philo->data->mutex_die);
	return (NULL);
}
