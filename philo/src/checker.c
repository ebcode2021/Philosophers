/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:19:58 by eunson            #+#    #+#             */
/*   Updated: 2023/01/19 20:40:29 by eunson           ###   ########.fr       */
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
		pthread_mutex_lock(philos[idx].each_mutex);
		if (philos[idx].done)
			res++;
		pthread_mutex_unlock(philos[idx].each_mutex);
		idx++;
	}
	res = (res == inform->philo_cnt);
	return (res);
}

int	check_finish(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->inform->routine_mutex);
	res = (philo->inform->finish);
	pthread_mutex_unlock(&philo->inform->routine_mutex);
	return (res);
}

int	check_over_time(t_philo *philo)
{
	long long	die_time;

	die_time = philo->time_after_eat + philo->inform->time_to_die;
	if (get_time() > die_time)
	{
		print_action(philo, DIE_MSG);
		pthread_mutex_lock(&philo->inform->routine_mutex);
		philo->inform->finish = 1;
		pthread_mutex_unlock(&philo->inform->routine_mutex);
	}
	return (philo->inform->finish);
}
