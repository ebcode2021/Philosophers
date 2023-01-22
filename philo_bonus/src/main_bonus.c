/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:10:19 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 19:42:11 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char *argv[])
{
	t_proc	proc;
	if (is_manual(argc, argv))
		return (0);
	check_arguments(argc, argv);
	init_proc(&proc, argc, argv);
	fork_proc(&proc);
	wait_all_proc(&proc);
	return (0);
}