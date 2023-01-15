/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:13:43 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 20:44:14 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	get_elapsed_time(long long start_time)
{
	return ((get_time() - start_time) / 1000);
}

void	init_philos_start_time(t_philo *philos, t_inform *inform)
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

void	usleep_timer(long long usleep_time)
{
	long long	end_times;

	end_times = get_time() + usleep_time; // ms 단위
	while (usleep_time);
	usleep(usleep_time);
	//....//check_Die() <- monitoring................?
}

void	set_time_after_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->inform->routine_mutex));
	philo->time_after_eat = get_time();
	pthread_mutex_unlock(&(philo->inform->routine_mutex));
}
