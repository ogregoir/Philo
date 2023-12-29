/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:35:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 15:35:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->mutex_print, NULL) != 0)
		ft_error("MUTEX DATA NOT INIT");
}

t_philo	*ft_parse(t_global *data, t_philo *philo)
{
	int				i;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*temp;

	i = 0;
	fork = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	temp = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	while (i < data->philo_nbr)
	{
		philo[i].data = data;
		philo[i].status = 0;
		philo[i].fork = fork;
		philo[i].mutex_data = temp;
		pthread_mutex_init(&fork[i], NULL);
		pthread_mutex_init(&temp[i], NULL);
		philo[i].philo_n = i + 1;
		philo[i].eat = 0;
		philo[i].last_meal = 0;
		philo[i].must_eat = 0;
		i++;
	}
	init_mutex(philo);
	return (philo);
}

void	create_philo(t_global *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_create(&philo[i].thd, NULL, start_routine, philo + i);
		i++;
	}
}

void	take_fork(t_philo *philo)
{
	if (philo->philo_n == philo->data->philo_nbr)
		pthread_mutex_lock(&philo->fork[0]);
	else
		pthread_mutex_lock(&philo->fork[philo->philo_n]);
	print_status(philo, philo->philo_n, "has taken a fork\n");
	if (philo->status == 1)
		return ;
	if (philo->data->philo_nbr == 1)
	{
		print_status(philo, philo->philo_n, "is died\n");
		exit(EXIT_SUCCESS);
	}
	pthread_mutex_lock(&philo->fork[philo->philo_n - 1]);
	print_status(philo, philo->philo_n, "has taken a fork\n");
}

void	return_fork(t_philo *philo)
{
	if (philo->philo_n == philo->data->philo_nbr)
		pthread_mutex_unlock(&philo->fork[0]);
	else
		pthread_mutex_unlock(&philo->fork[philo->philo_n]);
	pthread_mutex_unlock(&philo->fork[philo->philo_n - 1]);
}
