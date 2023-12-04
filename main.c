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
/*
void	ft_printf_struct(t_global *data, t_philo *philo)
{
	printf("DATA philo nbr %d\n", data->philo_nbr);
	printf("DATA time_to_die %d\n", data->time_to_die);
	printf("DATA time_to_eat %d\n", data->time_to_eat);
	printf("DATA time_to_sleep %d\n", data->time_to_sleep);
	printf("PHILO n %d\n", philo[0].philo_n);
	printf("PHILO n %d\n", philo[1].philo_n);
	printf("PHILO n %d\n", philo[2].philo_n);
	printf("PHILO n %d\n", philo[3].philo_n);
	printf("PHILO n %d\n", philo[4].philo_n);
}*/

int	ft_init(t_global *data, char **argv)
{
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		data->nbr_must_eat = ft_atoi(argv[5]);
	if (ft_verif_num(argv) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_global	*data;
	t_philo		*philo;
	int			i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("not enough arguments\n");
		return (1);
	}
	data = malloc(sizeof(t_global));
	data->time_today = ft_time_today();
	if (ft_init(data, argv) == 1)
	{
		printf("an argument is not numeric\n");
		return (1);
	}
	philo = malloc(sizeof(t_philo) * (data->philo_nbr + 1));
	philo = ft_parse(data, philo);
	create_philo(data, philo);
	while (i < data->philo_nbr)
	{
		pthread_join(philo[i].thd, NULL);
		i++;
	}
	//ft_printf_struct(data, philo);
	return (0);
}
