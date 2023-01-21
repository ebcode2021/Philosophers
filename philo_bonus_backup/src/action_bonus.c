/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:32:29 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 19:57:26 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_fork(t_philo *philo, t_info *info, int take)
{
	if (take)
	{
		sem_wait(info->fork);
		print_action(philo, FORK_MSG);
		sem_wait(info->fork);
		print_action(philo, FORK_MSG);
	}
	else
	{
		sem_post(info->fork);
		sem_post(info->fork);
	}
}

static void	philo_eat(t_philo *philo, t_info *info)
{
	print_action(philo, EAT_MSG);
	set_time_after_eat(philo, info);
	usleep_timer(info->time_to_die);
	philo->eat_cnt++;
	if (philo->eat_cnt == info->must_eat_cnt)
	{
		sem_wait(philo->each);
		philo->done = 1;
		sem_post(philo->each);
	}
} 

static void	philo_sleep(t_philo *philo, t_info *info)
{
	print_action(philo, SLEEP_MSG);
	usleep_timer(info->time_to_sleep);
}

static void	routine(t_philo *philo, t_info *info)
{
	while (check_finish(philo) == 0 && philo->done == 0)
	{
		philo_fork(philo, info, TAKE);
		phiilo_eat(philo, info);
		philo_fork(philo, info, PUT);
		philo_sleep(philo, info);
		phiilo_action(philo, info, THINK_MSG);
	}
}

void	action(t_philo *philo, t_info *info)
{
	sem_wait(info->routine);
	sem_post(info->routine);
	philo->time_after_eat = get_time();
	routine(philo, info);
}
