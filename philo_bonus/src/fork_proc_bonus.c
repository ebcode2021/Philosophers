/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_proc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:47:03 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:10:43 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	init_philo(t_philo *philo, int idx)
{
	philo->idx = idx + 1;
	philo->eat_cnt = 0;
	philo->done = 0;
	philo->file_name = ft_strjoin("file_", ft_itoa(philo->idx));
	sem_unlink(philo->file_name);
	philo->each = sem_open(philo->file_name, O_CREAT, 0666, 1);
}

void	child_proc(t_proc *proc, int idx)
{
	t_philo philo;
	
	proc->philo = &philo;
	init_philo(proc->philo, idx);
	action(proc);
}

void	fork_proc(t_proc *proc)
{
	int		idx;
	pid_t	pid;

	idx = 0;
	sem_wait(proc->routine);
	while (idx < proc->philo_cnt)
	{
		pid = fork();
		if (pid == CHILD)
		{
			child_proc(proc, idx);
			break ;
		}
		idx++;
	}
	sem_post(proc->routine);
}
