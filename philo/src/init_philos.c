/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:21:48 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 21:15:50 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks(pthread_mutex_t *fork_mutex, int total_cnt)
{
	int	idx;

	idx = 0;
	while (idx < total_cnt)
		pthread_mutex_init(&fork_mutex[idx++], 0);
}

static void	insert_datas(t_philo *philos, pthread_mutex_t *fork, t_inform *info)
{
	int				idx;

	idx = -1;
	set_forks(fork, info->philo_cnt);
	while (++idx < info->philo_cnt)
	{
		philos[idx].idx = idx + 1;
		philos[idx].time_after_eat = 0;
		philos[idx].eat_cnt = 0;
		philos[idx].inform = info;
		if (idx == 0)
			philos[idx].left_fork = fork[info->philo_cnt - 1];
		else
			philos[idx].left_fork = fork[idx - 1];
		if (idx == info->philo_cnt - 1)
			philos[idx].right_fork = fork[0];
		else
			philos[idx].right_fork = fork[idx + 1];
	}
}

static int	seat_philos(t_philo *philos, t_inform *inform)
{
	int	idx;

	pthread_mutex_lock(&inform->routine_mutex);
	idx = -1;
	while (++idx < inform->philo_cnt)
	{
		if (pthread_create(&philos[idx].thread_id, 0, routine, &philos[idx]) != 0)
			return (print_error(THREAD_ERROR));
	}
	return (1);
}

int	init_philos(t_philo **philos, t_inform *inform)
{
	pthread_mutex_t	*fork_mutex;
	
	*philos = (t_philo *)malloc(sizeof(t_philo) * inform->philo_cnt);
	fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * inform->philo_cnt);
	if (!philos || !fork_mutex)
		return (print_error(MALLOC_FAIL));
	insert_datas(*philos, fork_mutex, inform);
	seat_philos(*philos, inform);
	return (1);
}
