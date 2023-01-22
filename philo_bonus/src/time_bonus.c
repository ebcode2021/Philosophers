/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:13:02 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:03:41 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	set_start_time(t_proc *proc)
{
	long long	current_time;

	current_time = get_time();
	proc->start_time = current_time;
	proc->philo->last_eat = current_time;
}

void	set_time_after_eat(t_philo *philo)
{
	sem_wait(philo->each);
	philo->last_eat = get_time();
	sem_post(philo->each);
}

void	usleep_timer(long long time)
{
	long long	end_time;

	end_time = get_time() + time;
	while (get_time() < end_time)
		usleep(DEFAULT_USLEEP_TIMER);
}
