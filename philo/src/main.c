/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 20:44:55 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_to_eat(t_philo *philos, t_inform *inform)
{
	int	idx;

	pthread_mutex_lock(&inform->routine_mutex);
	idx = 0;
	while (idx < inform->philo_cnt)
	{
		if (pthread_create(&philos[idx].thread_id, 0, routine, &philos[idx]) != 0)
			return (print_error(THREAD_ERROR));
		idx++;
	}
	return (1);
}

static void	monitoring_thread(t_philo *philos, t_inform *inform)
{
	int	idx;

	// 초기화 + 작동 시작
	init_philos_start_time(philos, inform);
	pthread_mutex_unlock(&inform->routine_mutex);
	// 감시
	while (1)
	{
		idx = 0;
		while (idx < inform->philo_cnt)
		{
			
			idx++;
		}
		// 뭘 감시하지....?
		// 죽은애가 있나?
		// 현재시간 - 마지막으로 먹은시간 이 견딜 수 있는 시간을 오버하면 (함수로 빼) -> is_finish
		// 다 먹었나..? while(philo->done) : (idx  == inform->philo_cnt)
		// 오버됬나?
	}
	wait_all_thread(philos, inform->philo_cnt);
}

static void	destory_mutex(t_philo **philos, t_inform *inform)
{
	int	idx;

	idx = 0;
	while (idx < inform->philo_cnt)
	{
		pthread_mutex_destroy(&(philos[idx]->right_fork));
		pthread_mutex_destroy(&(philos[idx]->each_mutex));
		idx++;
	}
	pthread_mutex_destroy(&(inform->routine_mutex));
	pthread_mutex_destroy(&(inform->print_mutex));
}

static void	free_philos(t_philo **philos, int total_cnt)
{
	int	idx;

	idx = 0;
	while (idx < total_cnt)
	{
		free(&(philos[idx]->right_fork));
		free(&(philos[idx]->each_mutex));
		idx++;
	}
	free(*philos);
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_inform		inform;

	if (init_inform(&inform, argc, argv) && init_philos(&philos, &inform))
	{
		if (start_to_eat(philos, &inform))
		{
			monitoring_thread(philos, &inform);
			destory_mutex(&philos, &inform);
			free_philos(&philos, inform.philo_cnt);
		}
	}
	return (0);
}
