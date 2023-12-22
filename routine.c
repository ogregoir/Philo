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
	philo->must_eat += 1;
	philo->data->time_today = ft_time_today();	
	if (philo->status == 1)
		return ;
	philo->eat = 1;
	print_status(convert_time(philo), philo->philo_n, "is eating\n");
	ft_my_usleep(philo, philo->data->time_to_eat);
	philo->data->time_today = ft_time_today();
	philo->last_meal = ft_time_today();
	philo->eat = 0;
	return_fork(philo);
}

void	sleeping(t_philo *philo)
{
	philo->data->time_today = ft_time_today();
	if (philo->status == 1)
		return ;
	print_status(convert_time(philo), philo->philo_n, "is sleeping\n");
	ft_my_usleep(philo, philo->data->time_to_sleep);
	philo->data->time_today = ft_time_today();
}

void	thinking(t_philo *philo)
{
	if (philo->status == 1)
		return ;
	philo->data->time_today = ft_time_today();
	print_status(convert_time(philo), philo->philo_n, "is thinking\n");
}

void	*start_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->philo_n % 2 == 1 && philo->data->philo_nbr != 1)
		ft_my_usleep(philo, 20);
	while (philo->status != 1)
	{
		philo_eat(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
