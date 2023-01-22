/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:10:31 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:52:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	all_sem_unlink(void)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("routine");
}

static void	all_sem_open(t_proc *proc)
{
	proc->fork = sem_open("fork", O_CREAT, 0666, proc->philo_cnt);
	proc->print = sem_open("print", O_CREAT, 0666, 1);
	proc->routine = sem_open("routine", O_CREAT, 0666, 1);
}

static void	init_proc_sem(t_proc *proc)
{
	all_sem_unlink();
	all_sem_open(proc);
}

void	init_proc(t_proc *proc, int argc, char *argv[])
{
	proc->philo_cnt = philo_atoi(argv[1]);
	proc->time_to_die = philo_atoi(argv[2]);
	proc->time_to_eat = philo_atoi(argv[3]);
	proc->time_to_sleep = philo_atoi(argv[4]);
	proc->finish = 0;
	proc->status = 0;
	proc->must_eat_cnt = 0;
	if (argc == 6)
		proc->must_eat_cnt = philo_atoi(argv[5]);
	init_proc_sem(proc);
}
