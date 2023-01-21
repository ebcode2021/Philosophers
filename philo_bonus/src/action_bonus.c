/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:32:29 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 22:35:39 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_fork(t_philo *philo, t_proc *proc, int take)
{
	if (take)
	{
		sem_wait(proc->fork);
		print_action(philo, proc->start_time, FORK_MSG);
		sem_wait(proc->fork);
		print_action(philo, proc->start_time, FORK_MSG);
	}
	else
	{
		sem_post(proc->fork);
		sem_post(proc->fork);
	}
}

static void	philo_eat(t_philo *philo, t_proc *proc)
{
	print_action(philo, proc->start_time, EAT_MSG);
	set_time_after_eat(philo, proc);
	usleep_timer(proc->time_to_die);
	philo->eat_cnt++;
	if (philo->eat_cnt == proc->must_eat_cnt)
	{
		sem_wait(philo->each);
		philo->done = 1;
		sem_post(philo->each);
	}
} 

static void	philo_sleep(t_philo *philo, t_proc *proc)
{
	print_action(philo, proc->start_time, SLEEP_MSG);
	usleep_timer(proc->time_to_sleep);
}

static void	routine(t_proc *proc)
{
	t_philo *philo;

	philo = proc->philo;
	if (check_one_philo(proc))
		return ;
	while (check_finish(proc) == 0 && philo->done == 0)
	{
		philo_fork(philo, proc, TAKE);
		philo_eat(philo, proc);
		philo_fork(philo, proc, PUT);
		philo_sleep(philo, proc);
		print_action(philo, proc->start_time, THINK_MSG);
	}
}

void	action(t_proc *proc)
{
	sem_wait(proc->routine);
	sem_post(proc->routine);
	routine(proc);
}
