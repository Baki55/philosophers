/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:37:41 by bkhatib           #+#    #+#             */
/*   Updated: 2022/11/13 14:05:36 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	end_checker(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	if (info->number_eat < philo->counter_meal)
		info->dead = true;
	i++;
}

void	ft_death(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (info->dead != true)
	{
		if ((int)(real_time() - philo[i].last_meal)
			> info->time_to_die)
		{
			pthread_mutex_lock(&info->printf_mutex);
			info->dead = true;
			printf("%"PRId64 " %d died\n", real_time()
				- info->start_timer, info->philo[i].id + 1);
			pthread_mutex_unlock(&info->printf_mutex);
		}
		i++;
		if (i == info->number_of_philo)
			i = 0;
		if (info->argc == 6)
			end_checker(philo, info);
	}
}

void	ft_join_destroy(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		philo[i].id = i;
		pthread_join(philo[i].thread_id, NULL);
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
}

void	ft_init_all(t_philo *philo, t_info *info)
{
	init_mutex(info);
	create_thread(philo, info);
	ft_death(philo, info);
	ft_join_destroy(philo, info);
}
