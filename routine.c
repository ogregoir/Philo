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

int	philo_eat(t_philo *philo)
{
	take_fork(philo);
	philo->eat = 1;
	philo->data->time_today = ft_time_today();
	print_status(philo->data->time_today, philo->philo_n, "is eating\n");
	usleep(philo->data->time_to_eat * 1000);
	philo->data->time_today = ft_time_today();
	return_fork(philo);
	return (0);
}

void	sleeping(t_philo *philo)
{
	philo->data->time_today = ft_time_today();
	print_status(philo->data->time_today, philo->philo_n, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
	philo->data->time_today = ft_time_today();
}

void	thinking(t_philo *philo)
{
	philo->data->time_today = ft_time_today();
	print_status(philo->data->time_today, philo->philo_n, "is thinking\n");
}

void	*start_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo_eat(philo);
	if (philo->eat == 0 && philo->data->time_today >= philo->data->time_to_eat)
		printf("DEAD\n");
	sleeping(philo);
	thinking(philo);
	return (NULL);
}
