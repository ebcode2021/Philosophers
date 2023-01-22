/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:32:29 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:54:23 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_fork(t_proc *proc, int take)
{
	if (take)
	{
		sem_wait(proc->fork);
		print_action(proc, proc->start_time, FORK_MSG);
		sem_wait(proc->fork);
		print_action(proc, proc->start_time, FORK_MSG);
	}
	else
	{
		sem_post(proc->fork);
		sem_post(proc->fork);
	}
}

static void	philo_eat(t_philo *philo, t_proc *proc)
{
	print_action(proc, proc->start_time, EAT_MSG);
	set_time_after_eat(philo);
	usleep_timer(proc->time_to_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == proc->must_eat_cnt)
	{
		sem_wait(philo->each);
		philo->done = 1;
		sem_post(philo->each);
	}
}

static void	philo_sleep(t_proc *proc)
{
	print_action(proc, proc->start_time, SLEEP_MSG);
	usleep_timer(proc->time_to_sleep);
}

static void	routine(t_proc *proc)
{
	t_philo	*philo;

	proc->start_time = get_time();
	proc->philo->last_eat = get_time();
	if (check_one_philo(proc))
		return ;
	philo = proc->philo;
	sem_post(proc->routine);
	if ((philo->idx) % 2)
		usleep(DEFAULT_USLEEP);
	pthread_create(&(proc->die_check), 0, die_checker, proc);
	while (check_die(proc) == 0 && philo->done == 0)
	{
		philo_fork(proc, TAKE);
		philo_eat(philo, proc);
		philo_fork(proc, PUT);
		philo_sleep(proc);
		print_action(proc, proc->start_time, THINK_MSG);
	}
	pthread_detach(proc->die_check);
	sem_close(proc->philo->each);
}

void	action(t_proc *proc)
{
	sem_wait(proc->routine);
	routine(proc);
}
