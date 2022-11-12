/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:02:07 by bkhatib           #+#    #+#             */
/*   Updated: 2022/11/09 16:23:08 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	real_time(void)
{
	struct timeval	time;
	long			res;

	gettimeofday(&time, NULL);
	res = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (res);
}

void	ft_sleep(t_info *info, int time)
{
	long	new_time;
	long	start;

	start = real_time();
	while (true)
	{
		new_time = real_time();
		if (new_time - start >= time)
			break ;
		if (info->dead == true)
			break ;
		usleep(100);
	}
}

int	msg_exit(char *message)
{
	printf("%s\n", message);
	exit (EXIT_FAILURE);
	return (0);
}