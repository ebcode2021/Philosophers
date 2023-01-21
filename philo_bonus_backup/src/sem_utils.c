/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:14:19 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 18:32:02 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	all_unlink()
{
	sem_unlink("fork");
	sem_unlink("routine");
	sem_unlink("print");
	
}

void	init_sem(t_info *info)
{
	all_unlink();
	info->fork = sem_open("fork", O_CREAT, 0666, info->philo_cnt);
	info->routine = sem_open("ready", O_CREAT, 0666, 1);
	info->print = sem_open("print", O_CREAT, 0666, info->philo_cnt);
}
