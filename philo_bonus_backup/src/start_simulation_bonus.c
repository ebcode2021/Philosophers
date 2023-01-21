/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:34:56 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 15:36:49 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_to_simulation(t_philo *philos, t_info *info)
{
	int	idx;

	idx = 0;
	sem_wait(info->ready);
	while (idx < info->philo_cnt)
	{
		
		pthread_create(&philos[idx].thread_id, 0, action, &(philos[idx]));
		idx++;
	}
	set_start_time(philos, info);
	set_post(info->ready);
	pthread_mutex_unlock(&info->routine_mutex);
}