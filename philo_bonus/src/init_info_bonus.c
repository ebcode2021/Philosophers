/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:28:23 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 20:52:28 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_info(t_info *info, char *argv[])
{
	info->proc_cnt = philo_atoi(argv[1]);
	info->pid = (pid_t *)malloc(sizeof(pid_t) * info->proc_cnt);
	if (!info->pid)
		print_error_with_exit(MALLOC_FAIL);
}
