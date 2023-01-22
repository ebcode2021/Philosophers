/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:33:20 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:53:43 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_arguments(int argc, char *argv[])
{
	int	idx;

	idx = 1;
	if (argc < 5 || argc > 7)
		print_error_with_exit(ARGU_CNT);
	while (argv[idx])
	{
		if (philo_atoi(argv[idx]) == 0)
			print_error_with_exit(NOT_A_VALID);
		idx++;
	}
	return (1);
}

int	check_one_philo(t_proc *proc)
{
	if (proc->philo_cnt != 1)
		return (0);
	printf("%lld ", get_elapsed_time(proc->start_time));
	printf("%d %s\n", proc->philo->idx, FORK_MSG);
	usleep_timer(proc->time_to_die);
	printf("%lld ", get_elapsed_time(proc->start_time));
	printf("%d %s\n", proc->philo->idx, DIE_MSG);
	return (1);
}
