/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:13 by eunson            #+#    #+#             */
/*   Updated: 2023/01/18 22:09:49 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_fork(t_philo *philo, int take)
{
	if (take)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, FORK_MSG);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

static void	philo_eat(t_philo *philo)
{
	print_action(philo, EAT_MSG);
	set_time_after_eat(philo);
	usleep_timer(philo->inform->time_to_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->inform->must_eat_cnt)
		philo->done = 1;
}

static void	philo_sleep(t_philo *philo)
{
	print_action(philo, SLEEP_MSG);
	usleep_timer(philo->inform->time_to_sleep);
}

static void	philo_action(t_philo *philo)
{
	philo_fork(philo, TAKE);
	philo_eat(philo);
	philo_fork(philo, PUT);
	philo_sleep(philo);
	print_action(philo, THINK_MSG);
}

void	*routine(void *void_philos)
{
	t_philo	*philo;

	philo = (t_philo *)void_philos;
	pthread_mutex_lock(&philo->inform->routine_mutex);
	pthread_mutex_unlock(&philo->inform->routine_mutex);
	if (philo->idx % 2) // 짝수먼저 먹어.
		usleep(DEFAULT_USLEEP);
	while (check_finish(philo) == 0)
		philo_action(philo);
	return (0);
}
