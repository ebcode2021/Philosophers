/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:19:39 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 20:35:38 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destory_mutex(t_philo *philos, t_inform *inform)
{
	int	idx;

	idx = 0;
	while (idx < inform->philo_cnt)
	{
		pthread_mutex_destroy(philos[idx].right_fork);
		pthread_mutex_destroy(&(philos[idx].each_mutex));
		idx++;
	}
	pthread_mutex_destroy(&inform->routine_mutex);
	pthread_mutex_destroy(&inform->print_mutex);
}
