/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:19:58 by eunson            #+#    #+#             */
/*   Updated: 2023/01/18 22:10:49 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 아무튼 실행되려면 대기 큐에서 기다려야하는데, 사실 500 + a. 500쉴거면, 30씩 끊어쉬어.
// usleep (500 * 0.95)
// 쉬기 시작한 시간을 현재시간으로 10시 50분 기록하고.
// 내가 1분 쉴거면, 10초 씩 끊어쉬는거.
// 10초쉬고, 51분되었나 확인하고

int	check_finish(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&philo->inform->routine_mutex);
	res = (philo->inform->finish || philo->done);
	pthread_mutex_unlock(&philo->inform->routine_mutex);
	return (res);
}

int	check_over_time(t_philo *philo)
{
	if (get_time() > (philo->time_after_eat + philo->inform->time_to_die))
	{
		print_action(philo, DIE_MSG);
		philo->inform->finish = 1;
	}
	return (philo->inform->finish);
}

int	check_all_done(t_philo *philos, t_inform *inform)
{
	int	idx;
	int	res;

	pthread_mutex_lock(&inform->routine_mutex);
	idx = 0;
	res = 0;
	while (idx < inform->philo_cnt)
	{
		if (philos[idx].done)
			res++;
		idx++;
	}
	res = (res == inform->philo_cnt);
	pthread_mutex_unlock(&inform->routine_mutex);
	return (res);
}
