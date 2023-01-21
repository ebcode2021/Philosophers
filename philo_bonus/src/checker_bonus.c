/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:33:20 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 22:34:38 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_finish(t_proc *proc)
{
	int	res;

	sem_wait(proc->routine);
	res = (proc->finish);
	sem_post(proc->routine);
	return (res);
}

int	check_one_philo(t_proc *proc)
{
	if (proc->philo_cnt != 1)
		return (0);
	print_action(proc->philo, FORK_MSG);
	usleep(proc->time_to_die);
	return (1);
}

// 누가 체크하지? (시간 오버되는거를..?)
int	check_over_time(t_proc *proc)
{
	long long	die_time;

	die_time = proc->philo->last_eat + proc->time_to_die;
	if (get_time() > die_time)
	{
		sem_wait(proc->routine);
		proc->finish = 1;
		sem_post(proc->routine);
		print_action(proc->philo, proc->start_time, DIE_MSG);
	}
	return (proc->finish);
}