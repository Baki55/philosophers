/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:59:28 by bkhatib           #+#    #+#             */
/*   Updated: 2022/11/13 14:05:36 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <sys/time.h>
# include <inttypes.h>
# include <limits.h>

typedef struct s_info
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				argc;
	int				number_eat;
	atomic_bool		dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printf_mutex;
	int64_t			start_timer;
	struct s_philo	*philo;
}	t_info;

typedef struct s_philo
{
	atomic_int				id;
	int						left_fork;
	int						right_fork;
	atomic_int_fast64_t		counter_meal;
	atomic_int_fast64_t		last_meal;
	pthread_t				thread_id;
	t_info					*info;
}	t_philo;

/* UTILS FUNCTIONS */

long	real_time(void);
void	ft_sleep(t_info *info, int time);
int		msg_exit(char *message);
int		ft_parse(int argc, char **argv, t_info *info);

/* INIT FUNCTIONS */

void	ft_init_all(t_philo *philo, t_info *info);
int		init_mutex(t_info *info);
void	create_thread(t_philo *philo, t_info *info);

/* PHILO FUNCTIONS */

void	*routine_thread(t_philo *philo);
void	ft_fork(t_philo *philo);
void	routine_printf(t_philo *philo, char *message);
void	ft_death(t_philo *philo, t_info *info);
void	end_checker(t_philo *philo, t_info *info);
void	ft_join_destroy(t_philo *philo, t_info *info);

#endif
