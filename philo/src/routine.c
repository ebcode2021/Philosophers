/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:58:13 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 22:22:37 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->inform->routine_mutex));
	//
	print_philo(philo, TAKE_FORK);
	pthread_mutex_unlock(&(philo->inform->routine_mutex));
}

// static void	philo_eat(t_philo *philo)
// {
// 	long long	time;

// 	time = get_time();
// 	// 오른손 먼저 -> 왼손 먼저 ->
// 	// 홀짝.
// }

// static void	philo_sleep(t_philo *philo)
// {
	
// }

// static void	philo_think(t_philo *philo)
// {
	
// }

// 내일 와서 해야하는 것
// 1) 홀짝 어떻게 할지(오른손 -> 왼손 -> 식사 -> 왼손 -> 오른손 내려놓기)
// 2) uslee 얼마나 줄지는 돌려보면서.
void	*routine(void *void_philos)
{
	t_philo *philos = (t_philo *)void_philos;
	pthread_mutex_lock(&(philos->inform->routine_mutex));
	pthread_mutex_unlock(&(philos->inform->routine_mutex));
	while (philos->inform->finish == 0)
	{
		printf("time : %lld | watashi : %d\n", get_time()-philos->inform->start_time, philos->idx);
		if (philos->idx % 2) // 짝수먼저 먹어.
			usleep(1000);
		philo_take_fork(philos);
		// philo_take_fork(philos);
		// philo_eat(philos);
		// philo_sleep(philos);
		// philo_think(philos);
		sleep(1);
		// eat -> sleep -> think(사실 상 아무것도 안하는거지)
	}
	
	printf("흠냐링...");
	return (0);
}