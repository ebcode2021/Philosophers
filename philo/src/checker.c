/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:19:58 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 21:15:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_done(t_philo *philos, t_inform *inform)
{
	int	idx;
	int	res;

	idx = 0;
	res = 0;
	while (idx < inform->philo_cnt)
	{
		pthread_mutex_lock(&philos[idx].each_mutex);
		res += philos[idx].done;
		pthread_mutex_unlock(&philos[idx].each_mutex);
		idx++;
	}
	if (res == inform->philo_cnt)
		return (1);
	return (0);
}

int	check_finish(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->inform->routine_mutex);
	res = (philo->inform->finish);
	pthread_mutex_unlock(&philo->inform->routine_mutex);
	return (res);
}

int	check_one_philo(t_philo *philo)
{
	if (philo->inform->philo_cnt != 1)
		return (0);
	print_action(philo, FORK_MSG);
	usleep(philo->inform->time_to_die);
	return (1);
}

int	check_over_time(t_philo *philo)
{
	long long	die_time;

	pthread_mutex_lock(&(philo->each_mutex));
	if (philo->done)
	{
		pthread_mutex_unlock(&(philo->each_mutex));
		return (0);
	}
	die_time = philo->time_after_eat + philo->inform->time_to_die;
	pthread_mutex_unlock(&(philo->each_mutex));
	if (get_time() > die_time)
	{
		pthread_mutex_lock(&philo->inform->routine_mutex);
		philo->inform->finish = 1;
		pthread_mutex_unlock(&philo->inform->routine_mutex);
		print_action(philo, DIE_MSG);
	}
	return (philo->inform->finish);
}

int	check_stop_monitoring(t_philo *philos, t_inform *inform)
{
	if (inform->finish)
		return (0);
	if (check_all_done(philos, inform))
		return (0);
	return (1);
}
