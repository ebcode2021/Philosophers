/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:13 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 17:08:43 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo, int take)
{
	if (check_finish(philo))
		return ;
	if (take)
	{
		pthread_mutex_lock(&(philo->inform->routine_mutex));
		pthread_mutex_lock(&(philo->right_fork));
		pthread_mutex_lock(&(philo->left_fork));
		print_action(philo, FORK_MSG);
		pthread_mutex_unlock(&(philo->inform->routine_mutex));
	}
	else
	{
		pthread_mutex_unlock(&(philo->right_fork));
		pthread_mutex_unlock(&(philo->left_fork));
	}
}

void	philo_eat(t_philo *philo)
{
	if (check_finish(philo))
		return ;
	print_action(philo, EAT_MSG);
	set_time_after_eat(philo);
	usleep_timer(philo->inform->time_to_eat);
	if (++philo->eat_cnt == philo->inform->must_eat_cnt)
		philo->done = 1;
}

void	philo_sleep(t_philo *philo)
{
	if (check_finish(philo))
		return ;
	print_action(philo, SLEEP_MSG);
	usleep_timer(philo->inform->time_to_sleep);
}

void	philo_action(t_philo *philo)
{
	philo_fork(philo, TAKE);
	philo_eat(philo);
	philo_fork(philo, PUT);
	if (check_finish(philo))
		return ;
	philo_sleep(philo);
	print_action(philo, THINK_MSG);
}

void	*routine(void *void_philos)
{
	t_philo *philos;
	
	philos = (t_philo *)void_philos;
	pthread_mutex_lock(&(philos->inform->routine_mutex));
	pthread_mutex_unlock(&(philos->inform->routine_mutex));
	if (philos->idx % 2) // 짝수먼저 먹어.
		usleep(DEFAULT_USLEEP);
	while (1)
	{
		philo_action(philos);
		if (check_finish(philos))
			break ;
	}
	return (0);
}
