/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:13 by eunson            #+#    #+#             */
/*   Updated: 2023/01/23 11:50:11 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_fork(t_philo *philo, int take)
{
	if (take)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, FORK_MSG);
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, FORK_MSG);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

static void	philo_eat(t_philo *philo)
{
	print_action(philo, EAT_MSG);
	set_time_after_eat(philo);
	usleep_timer(philo->inform->time_to_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->inform->must_eat_cnt)
	{
		pthread_mutex_lock(&(philo->each_mutex));
		philo->done = 1;
		pthread_mutex_unlock(&(philo->each_mutex));
	}
}

static void	philo_sleep(t_philo *philo)
{
	print_action(philo, SLEEP_MSG);
	usleep_timer(philo->inform->time_to_sleep);
}

static void	routine(t_philo *philo)
{
	while (check_finish(philo) == 0 && philo->done == 0)
	{
		philo_fork(philo, TAKE);
		philo_eat(philo);
		philo_fork(philo, PUT);
		philo_sleep(philo);
		print_action(philo, THINK_MSG);
	}
}

void	*action(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	if (check_one_philo(philo))
		return (0);
	if (philo->idx % 2)
		usleep(DEFAULT_USLEEP);
	routine(philo);
	return (0);
}
