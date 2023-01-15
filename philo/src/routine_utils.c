/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:14:40 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 17:02:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// usleep 줄때, usleep 500이라는게, 프로세스가 실행되려면, 저기 뭐지. 그때설명잘했는데.
// 아무튼 실행되려면 대기 큐에서 기다려야하는데, 사실 500 + a. 500쉴거면, 30씩 끊어쉬어.
// usleep (500 * 0.95)
// 쉬기 시작한 시간을 현재시간으로 10시 50분 기록하고.
// 내가 1분 쉴거면, 10초 씩 끊어쉬는거.
// 10초쉬고, 51분되었나 확인하고

//1) 시간보내는거
//2) 모
int	check_finish(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&(philo->inform->routine_mutex));
	res = (philo->inform->finish || philo->done);
	pthread_mutex_unlock(&(philo->inform->routine_mutex));
	return (res);
}

// void	philo_do(t_philo *philo, int action)
// {
// 	if (action == EAT)
// 	{
// 		set_time_after_eat(philo);
// 		usleep_timer(philo->inform->time_to_eat);
// 	}
// 	else if (action == SLEEP)
// 		usleep_timer(philo->inform->time_to_sleep);
// 	if (action == EAT)
// 	{
// 		philo->eat_cnt++;
// 		if (philo->eat_cnt == philo->inform->must_eat_cnt)
// 			philo->done = 1;
// 	}
// }
