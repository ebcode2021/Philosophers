/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:13:02 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 19:53:41 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_start_time(t_philo *philos, t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->philo_cnt)
	{
		philos[idx].time_after_eat = info->start_time;
		idx++;
	}
}

long long	get_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	get_elapsed_time(long long start_time)
{
	return (get_time() - start_time);
}

void	set_time_after_eat(t_philo *philo, t_info *info)
{
	sem_wait(philo->each);
	philo->time_after_eat = get_time();
	sem_post(philo->each);
}

void	usleep_timer(long long time)
{
	long long	end_times;

	end_times = get_time() + time;
	while (get_time() < end_times)
		usleep(DEFAULT_USLEEP_TIMER);
}