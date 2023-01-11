/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/11 15:43:48 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1. 강의 데드락 듣고
// 2. mutex_lock, mutex_unclock 쓰는법 알고 (금요일까지)
// 3. 주말에 실제로 돌리고. 월요일 평가받고?
int	init_inform(t_inform *inform, int argc, char **argv)
{
	if (!check_arguments(argc, argv))
		return (0);
	inform->philo_cnt = philo_atoi(argv[1]);
	inform->time_to_die = philo_atoi(argv[2]);
	inform->time_to_eat = philo_atoi(argv[3]);
	inform->time_to_sleep = philo_atoi(argv[4]);
	inform->must_eat_cnt = 0;
	inform->finish = 0;
	if (argc == 6)
		inform->must_eat_cnt = philo_atoi(argv[5]);
	return (1);
}

void	kill_philo()
{
	
}

void	*routine(t_philo *philos)
{
	pthread_mutex_t print_mutex;

	pthread_mutex_lock(philos->inform.routine_mutex);
	pthread_mutex_unlock(philos->inform.routine_mutex);
	while (1)
	{
		printf("안녕 필로 : %d\n", philos->idx);
		// eat -> sleep -> think(사실 상 아무것도 안하는거지)
	}
	printf("흠냐링...");
}

int	start_to_eat(t_philo *philos, t_inform *inform)
{
	int			idx;
	pthread_t	thread_id;
	
	// 각각의 thread(=philo)를 식탁에 앉히기 시작하고
	idx = 0;
	pthread_mutex_init(&inform->routine_mutex, 0); // 방을 만든다. 
	pthread_mutex_lock(&inform->routine_mutex);
	while (idx < inform->philo_cnt)
	{
		if (pthread_create(&philos[idx].thread_id, 0, routine, &philos[idx]) < 0)
			return (print_error(THREAD_ERROR)); 
		idx++;
	}
	pthread_mutex_unlock(&inform->routine_mutex);
	// while (1)
	// {
	// 	if (전부 다 밥을 먹거나 || 굶주린 사람이 있으면)
	// 	 	break ;
	// 	phtrad_
	// }
	return (1);
}

int	init_philos(t_philo *philos, t_inform inform)
{
	int	idx;
	
	idx = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * (inform.philo_cnt + 1));
	if (!philos)
		return (print_error(MALLOC_FAIL));
	while (idx < inform.philo_cnt)
	{
		printf("idx : %d\n", idx);
		philos[idx].idx = idx + 1;
		philos[idx].time_after_eat = 0; //현시간? 마지막 남은 시간.
		philos[idx].eat_cnt = 0;
		philos[idx].left_fork = idx - 1;
		philos[idx].right_fork = idx + 1;
		philos[idx].inform = inform;
		if (idx == 0)
			philos[idx].left_fork = inform.philo_cnt - 1;
		if (idx == inform.philo_cnt - 1)
		idx++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_inform	inform;
	t_philo		philos;

	//성공적으로 데이터가 들어왔을 경우
	if (init_inform(&inform, argc, argv) && init_philos(&philos, inform))
		start_to_eat(&philos, &inform);
	return (0);
}
