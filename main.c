/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:27:33 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 18:27:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_must_eat(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (philo->data->nbr_must_eat != 0)
	{
		while (philo->data->philo_nbr > i)
		{
			if (philo->data->nbr_must_eat == philo->must_eat)
				count++;
			i++;
		}
		if (philo->data->philo_nbr == count)
			return (0);
	}
	return (1);
}

void	ft_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		if (philo_must_eat(philo) == 0)
			break ;
		while (i < philo->data->philo_nbr)
		{
			if (philo->eat == 0)
			{
				if (ft_time_today2(philo) - philo[i].last_meal > philo->data->time_to_die)
				{
					print_status(philo, philo->philo_n, "is died\n");
					philo->status = 1;
					return ;
				}
			}
			i++;
		}
	}
	return ;
}

int	ft_init(t_global *data, char **argv)
{
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->nbr_must_eat = ft_atoi(argv[5]);
	else
		data->nbr_must_eat = 0;
	if (ft_verif_num(argv) == 1)
		return (1);
	return (0);
}


int	main(int argc, char **argv)
{
	t_global	*data;
	t_philo		*philo;

	if (argc < 5 || argc > 6)
	{
		printf("not enough arguments\n");
		return (1);
	}
	data = malloc(sizeof(t_global));
	data->time_to_start = ft_time_today();
	if (ft_init(data, argv) == 1)
	{
		printf("an argument is not numeric\n");
		return (1);
	}
	philo = malloc(sizeof(t_philo) * (data->philo_nbr + 1));
	philo = ft_parse(data, philo);
	create_philo(data, philo);
	ft_dead(philo);	
	return (0);
}
