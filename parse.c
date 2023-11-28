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

void	create_philo(t_global *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		philo[i].id = i;
		pthread_create(&philo[i].thd, NULL, start_routine, &philo[i].id);
		pthread_detach(philo[i].thd);
		i++;
	}
}
