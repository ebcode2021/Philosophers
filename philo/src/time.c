/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:13:43 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 13:56:18 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start_time(t_philo *philos, t_inform *inform)
{
	int	idx;

	inform->start_time = get_time();
	idx = 0;
	while (idx < inform->philo_cnt)
	{
		philos[idx].time_after_eat = inform->start_time;
		idx++;
	}
}

long long	get_elapsed_time(long long start_time)
{
	return (get_time() - start_time);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	set_time_after_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->each_mutex);
	philo->time_after_eat = get_time();
	pthread_mutex_unlock(&philo->each_mutex);
}

void	usleep_timer(long long time)
{
	long long	one_fifth;
	long long	end_times;

	end_times = get_time() + time;
	one_fifth = time / 5;
	while (get_time() < end_times)
		usleep(one_fifth);
}
