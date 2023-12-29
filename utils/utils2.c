/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:31:11 by marvin            #+#    #+#             */
/*   Updated: 2023/12/29 15:31:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *str)
{
	int		i;
	int		n;
	int		sign;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -sign;
			i++;
		}
		while (str[i] > 47 && str[i] < 58)
		{
			n = 10 * n + str[i] - 48;
			i++;
		}
		return (n * sign);
	}
	return (0);
}

int	ft_isdigit(int i)
{
	if (i > 47 && i < 58)
		return (1);
	else
		return (0);
}

void	ft_free_all(t_philo *philo, t_global *data)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nbr)
	{
		pthread_mutex_destroy(philo[i].fork);
		pthread_mutex_destroy(philo[i].mutex_data);
		i++;
	}
	free(philo->fork);
	free(philo->mutex_data);
	pthread_mutex_destroy(&philo->data->mutex_die);
	pthread_mutex_destroy(&philo->mutex_print);
	free(data);
	free(philo);
}

void	ft_if(t_philo *philo)
{
	print_status(philo, philo->philo_n, "is died\n");
	pthread_mutex_lock(&philo->data->mutex_die);
	philo->data->status = 1;
	pthread_mutex_unlock(&philo->data->mutex_die);
	pthread_mutex_unlock(philo->mutex_data);
}
