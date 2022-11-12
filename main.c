/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:29:58 by bkhatib           #+#    #+#             */
/*   Updated: 2022/11/09 15:34:56 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo		*philo;

	if (ft_parse(argc, argv, &info) == 1)
	{
		printf("Please verify the arguments.\n");
		return (0);
	}
	info.argc = argc;
	if (pthread_mutex_init(&info.printf_mutex, NULL) != 0)
		return (0);
	info.dead = false;
	philo = malloc(sizeof(t_philo) * info.number_of_philo);
	if (!philo)
		return (0);
	info.philo = philo;
	info.start_timer = real_time();
	info.forks = malloc(sizeof(pthread_mutex_t) * info.number_of_philo);
	if (!info.forks)
		return (0);
	ft_init_all(philo, &info);
	return (0);
}