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
	if (philo->status == 1)
		return ;
	philo->eat = 1;
	philo->must_eat += 1;
	print_status(philo, philo->philo_n, "is eating\n");
	ft_usleep(philo->data->time_to_eat);
	philo->last_meal = ft_time_today2(philo);
	philo->eat = 0;
	return_fork(philo);
}

void	sleeping(t_philo *philo)
{
	if (philo->status != 1)
	{
		print_status(philo, philo->philo_n, "is sleeping\n");
		ft_usleep(philo->data->time_to_sleep);
	}
}

void	thinking(t_philo *philo)
{
	if (philo->status != 1)
		print_status(philo, philo->philo_n, "is thinking\n");
}

void	*start_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->philo_n % 2 == 1)
		ft_usleep(20);
	while (philo->status != 1)
	{
		philo_eat(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void ft_free_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nbr)
	{
		pthread_mutex_destroy(philo[i].fork);
		free(philo[i].fork);
		i++;
	}
//	pthread_mutex_destroy(philo->data.mutex_data);
	free(philo->data);
	free(philo);
}