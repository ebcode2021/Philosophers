/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_to_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:18:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 14:19:11 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_to_simulation(t_philo *philos, t_inform *inform)
{
	int	idx;

	pthread_mutex_lock(&inform->routine_mutex);
	idx = 0;
	while (idx < inform->philo_cnt)
	{
		pthread_create(&philos[idx].thread_id, 0, action, &(philos[idx]));
		idx++;
	}
	set_start_time(philos, inform);
	pthread_mutex_unlock(&inform->routine_mutex);
}
