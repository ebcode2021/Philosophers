/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:21:48 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 20:23:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_mutex(pthread_mutex_t *fork, pthread_mutex_t *each, int total)
{
	int	idx;

	idx = 0;
	while (idx < total)
	{
		pthread_mutex_init(&fork[idx], 0);
		pthread_mutex_init(&each[idx], 0);
		idx++;
	}
}

static void	insert_datas(t_philo *philos, pthread_mutex_t *fork_mutex, \
								pthread_mutex_t *each_mutex, t_inform *info)
{
	int	idx;

	idx = 0;
	set_mutex(fork_mutex, each_mutex, info->philo_cnt);
	while (idx < info->philo_cnt)
	{
		philos[idx].idx = idx + 1;
		philos[idx].time_after_eat = 0;
		philos[idx].done = 0;
		philos[idx].eat_cnt = 0;
		philos[idx].inform = info;
		philos[idx].each_mutex = each_mutex[idx];
		if (idx == 0)
			philos[idx].left_fork = fork_mutex[info->philo_cnt - 1];
		else
			philos[idx].left_fork = fork_mutex[idx - 1];
		if (idx == info->philo_cnt - 1)
			philos[idx].right_fork = fork_mutex[0];
		else
			philos[idx].right_fork = fork_mutex[idx + 1];
		idx++;
	}
}

int	init_philos(t_philo **philos, t_inform *inform)
{
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*each_mutex;

	*philos = (t_philo *)malloc(sizeof(t_philo) * inform->philo_cnt);
	fork_mutex = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * inform->philo_cnt);
	each_mutex = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * inform->philo_cnt);
	if (!philos || !fork_mutex || !each_mutex)
		return (print_error(MALLOC_FAIL));
	insert_datas(*philos, fork_mutex, each_mutex, inform);
	return (1);
}
