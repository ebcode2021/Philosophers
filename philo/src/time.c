/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:13:43 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 21:30:29 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	init_philos_time(t_philo *philos, t_inform *inform)
{
	int	idx;

	inform->start_time = get_time();
	idx = 0;
	while (idx < inform->philo_cnt)
		philos[idx++].time_after_eat = inform->start_time;
}
