/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:17:56 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 17:42:51 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_all_thread(t_philo *philos, int total_cnt)
{
	int	idx;

	idx = 0;
	while (idx < total_cnt)
	{
		pthread_join(philos[idx].thread_id, 0);
		idx++;
	}
}

void	monitoring(t_philo *philos, t_inform *inform)
{
	int	idx;

	while (1)
	{
		idx = 0;
		while (idx < inform->philo_cnt && check_finish(philos) == 0)
		{
			if (check_over_time(&philos[idx]))
				break ;
			idx++;
		}
		if (check_all_done(philos, inform) || check_finish(philos))
			break ;
	}
	wait_all_thread(philos, inform->philo_cnt);
}
