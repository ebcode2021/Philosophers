/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_proc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:10:31 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 22:29:12 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	all_unlink()
{
	sem_unlink("routine");
	sem_unlink("fork");
	sem_unlink("print");
}

static void	init_proc_sem(t_proc *proc, int total_proc)
{
	all_unlink();
	proc->routine = sem_open("routine", O_CREAT, 0666, 1);
	proc->print = sem_open("print", O_CREAT, 0666, 1);
	proc->fork = sem_open("fork", O_CREAT, 0666, total_proc);
}


void	init_proc(t_proc *proc, int argc, char *argv[])
{
	proc->philo_cnt = philo_atoi(argv[1]);
	proc->time_to_die = philo_atoi(argv[2]);
	proc->time_to_eat = philo_atoi(argv[3]);
	proc->time_to_sleep = philo_atoi(argv[4]);
	proc->finish = 0;
	proc->must_eat_cnt = 0;
	if (argc == 6)
		proc->must_eat_cnt = philo_atoi(argv[5]);
	init_proc_sem(proc, proc->philo);
}
