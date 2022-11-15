/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:47:46 by bkhatib           #+#    #+#             */
/*   Updated: 2022/11/12 12:11:01 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_printf(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->info->printf_mutex);
	if (philo->info->dead != true)
		printf("%"PRId64 " %d %s\n", real_time()
			-philo->info->start_timer, philo->id + 1, message);
	pthread_mutex_unlock(&philo->info->printf_mutex);
}

void	ft_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		routine_printf(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		routine_printf(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[philo->right_fork]);
		routine_printf(philo, "has taken a fork");
		pthread_mutex_lock(&philo->info->forks[philo->left_fork]);
		routine_printf(philo, "has taken a fork");
	}
}

void	*routine_thread(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_sleep(philo->info, philo->info->time_to_eat / 2);
	while (philo->info->dead != true)
	{
		if (philo->info->number_of_philo == 1)
			continue ;
		ft_fork(philo);
		routine_printf(philo, "is eating");
		philo->last_meal = real_time();
		ft_sleep(philo->info, philo->info->time_to_eat);
		pthread_mutex_unlock(&philo->info->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->info->forks[philo->left_fork]);
		philo->counter_meal++;
		routine_printf(philo, "is sleeping");
		ft_sleep(philo->info, philo->info->time_to_sleep);
		routine_printf(philo, "is thinking");
	}
	return (NULL);
}

void	create_thread(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		philo[i].counter_meal = 0;
		philo[i].id = i;
		philo[i].info = info;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % info->number_of_philo;
		philo[i].last_meal = real_time();
		pthread_create(&philo[i].thread_id, NULL,
			(void *)routine_thread, &philo[i]);
		i++;
	}
}
