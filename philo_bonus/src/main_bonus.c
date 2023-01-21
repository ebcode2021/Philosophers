/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:10:19 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 22:13:42 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_all_proc(t_info info)
{
	int	idx;

	idx = 0;
	while (idx < info.proc_cnt)
		waitpid(info.pid[idx++], 0, 0);
}

int main(int argc, char *argv[])
{
	t_info	info;
	t_proc	proc;
	t_philo	*philos;

	if (is_manual(argc, argv))
		return (0);
	check_arguments(argc, argv);
	init_info(&info, argc, argv);
	init_proc(&info, argc, argv);
	fork_proc(&proc, &info);
	wait_all_proc(info);
	free_data();
	return (0);
}