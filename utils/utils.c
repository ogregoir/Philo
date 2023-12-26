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

unsigned long	ft_time_today(void)
{
	struct timeval	time;
	unsigned long	i;

	i = 0;
	if (gettimeofday(&time, NULL) == 0)
		i = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (i);
}

unsigned long	ft_time_today2(t_philo *philo)
{
	return (ft_time_today() - philo->data->time_to_start);
}

void	print_status(t_philo *philo, int philosopher, char *str)
{
	printf("%lu philo n°%d %s", ft_time_today2(philo), philosopher, str);
}

void	ft_usleep(unsigned long time_wait)
{
	unsigned long	waiting;

	waiting = ft_time_today();
	while (ft_time_today() - waiting <= time_wait)
		usleep(500);
}
