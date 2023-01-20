/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:21:48 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 17:43:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	insert_datas(t_philo *philos, pthread_mutex_t *fork, t_inform *info)
{
	int	idx;

	idx = 0;
	while (idx < info->philo_cnt)
	{
		philos[idx].idx = idx + 1;
		philos[idx].time_after_eat = 0;
		philos[idx].done = 0;
		philos[idx].eat_cnt = 0;
		philos[idx].inform = info;
		pthread_mutex_init(&philos[idx].each_mutex, 0);
		if (idx == 0)
			philos[idx].left_fork = &fork[info->philo_cnt - 1];
		else
			philos[idx].left_fork = &fork[idx - 1];
		philos[idx].right_fork = &fork[idx];
		idx++;
	}
}

int	init_philos(t_philo **philos, pthread_mutex_t **forks, t_inform *info)
{
	*philos = (t_philo *)malloc(sizeof(t_philo) * info->philo_cnt);
	if (!*philos)
		return (print_error(MALLOC_FAIL));
	insert_datas(*philos, *forks, info);
	return (1);
}
