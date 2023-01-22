/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_proc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:04:46 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 19:12:44 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	all_close(t_proc *proc)
{
	sem_close(proc->fork);
	sem_close(proc->print);
	sem_close(proc->routine);
}

void	wait_all_proc(t_proc *proc)
{
	int	idx;

	idx = 0;
	while (idx < proc->philo_cnt)
	{
		waitpid(-1, &(proc->status), 0);
		if (WEXITSTATUS(proc->status) == EXIT_FAILURE)
			kill(0, SIGINT);
		idx++;
	}
	all_close(proc);
}