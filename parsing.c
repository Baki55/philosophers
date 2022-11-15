/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:12 by bkhatib           #+#    #+#             */
/*   Updated: 2022/11/13 14:05:36 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_myatoi(const char *str, int *nb)
{
	unsigned int	result;

	result = 0;
	if (!*str)
		return (true);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result > INT_MAX)
			return (true);
	}
	if (*str)
		return (true);
	if (nb)
		*nb = result;
	return (false);
}

int	ft_parse(int argc, char **argv, t_info *info)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (ft_myatoi(argv[1], &info->number_of_philo))
		return (1);
	if (info->number_of_philo == 0 || info->number_of_philo > 200)
		msg_exit("Incorrect number of philosophers.");
	if (ft_myatoi(argv[2], (int *) &info->time_to_die))
		return (1);
	if (ft_myatoi(argv[3], &info->time_to_eat))
		return (1);
	if (ft_myatoi(argv[4], &info->time_to_sleep))
		return (1);
	if (argc == 6 && (ft_myatoi(argv[5], &info->number_eat)))
		return (1);
	if (info->time_to_die < 60 || info->time_to_eat < 60
		|| info->time_to_sleep < 60)
		return (msg_exit("time argument is invalid"));
	if (argc == 6 && info->number_eat <= 0)
		return (msg_exit("number of eat is invalid"));
	return (0);
}
