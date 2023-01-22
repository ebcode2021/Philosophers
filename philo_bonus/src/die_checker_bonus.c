/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 07:00:15 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:53:51 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_die(t_proc *proc)
{
	int	res;

	sem_wait(proc->routine);
	res = (proc->finish);
	sem_post(proc->routine);
	return (res);
}

int	check_done(t_proc *proc)
{
	int	res;

	sem_wait(proc->philo->each);
	res = (proc->philo->done);
	sem_post(proc->philo->each);
	return (res);
}

int	check_over_time(t_proc *proc)
{
	long long	die_time;

	sem_wait(proc->philo->each);
	if (proc->philo->done == 1)
	{
		sem_post(proc->philo->each);
		return (0);
	}
	die_time = proc->philo->last_eat + proc->time_to_die;
	sem_post(proc->philo->each);
	if (get_time() > die_time)
	{
		sem_wait(proc->routine);
		proc->finish = 1;
		sem_post(proc->routine);
		print_action(proc, proc->start_time, DIE_MSG);
	}
	return (proc->finish);
}

void	*die_checker(void *void_proc)
{
	t_proc	*proc;

	proc = (t_proc *)void_proc;
	while (1)
	{
		if (check_die(proc) == 0 && check_over_time(proc))
		{
			proc->status = 1;
			exit(1);
		}
		if (check_done(proc))
			break ;
	}
	return (0);
}
