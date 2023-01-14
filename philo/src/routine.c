/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:13 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 17:46:29 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philos_a)
{
	t_philo *philos = (t_philo *)philos_a;
	pthread_mutex_lock(&(philos->inform.routine_mutex));
	pthread_mutex_unlock(&(philos->inform.routine_mutex));
	while (1)
	{
		printf("안녕 필로 : %d\n", philos->idx);
		sleep(1);
		// eat -> sleep -> think(사실 상 아무것도 안하는거지)
	}
	printf("흠냐링...");
}