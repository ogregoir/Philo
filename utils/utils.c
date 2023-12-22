/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:38:29 by marvin            #+#    #+#             */
/*   Updated: 2023/11/27 23:38:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_verif_num(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_time_today(void)
{
	struct timeval	time;
	unsigned long	i;

	i = 0;
	if (gettimeofday(&time, NULL) == 0)
		i = (((time.tv_sec * 1000) + (time.tv_usec / 1000)) % (3600 * 1000));
	return (i);
}

void	print_status(unsigned long time, int philo, char *str)
{
	printf("%lu philo_n°%d %s", time, philo, str);
}

int	convert_time(t_philo *philo)
{
	int	time;

	time = (philo->data->time_today) - (philo->data->time_to_start);
	return (time);
}

void	ft_my_usleep(t_philo *philo, unsigned long time_wait)
{
	int waiting;

	waiting = philo->data->time_today - (philo->data->time_today - time_wait);
	while (waiting != 0)
	{
		usleep(500);
		waiting -= 5;
	}
}