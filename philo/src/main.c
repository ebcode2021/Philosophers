/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/19 21:22:58 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_to_eat(t_philo *philos, t_inform *inform)
{
	int	idx;

	pthread_mutex_lock(&inform->routine_mutex);
	idx = 0;
	while (idx < inform->philo_cnt)
	{
		if (pthread_create(&philos[idx].thread_id, 0, action, &(philos[idx])))
			print_error(THREAD_ERROR);
		idx++;
	}
	init_start_time(philos, inform);
	pthread_mutex_unlock(&inform->routine_mutex);
}

static void	monitoring(t_philo **philos, t_inform *inform)
{
	int			idx;

	while (inform->finish == 0)
	{
		idx = 0;
		while (idx < inform->philo_cnt && inform->finish == 0)
		{
			pthread_mutex_lock((*philos)[idx].each_mutex);
			if ((*philos)[idx].done == 0)
			{
				if (check_over_time(&(*philos)[idx]))
				{
					pthread_mutex_unlock((*philos)[idx].each_mutex);
					break ;
				}
			}
			pthread_mutex_unlock((*philos)[idx].each_mutex);
			idx++;
		}
		if (check_all_done(*philos, inform))
			break ;
	}
	wait_all_thread(philos, inform->philo_cnt);
}

static void	destory_mutex(t_philo *philos, t_inform *inform)
{
	int	idx;

	idx = 0;
	while (idx < inform->philo_cnt)
	{
		pthread_mutex_destroy(philos[idx].right_fork);
		pthread_mutex_destroy(philos[idx].each_mutex);
		idx++;
	}
	pthread_mutex_destroy(&inform->routine_mutex);
	pthread_mutex_destroy(&inform->print_mutex);
}

static void	free_philos(t_philo *philos, t_inform *inform)
{
	int	idx;

	idx = 0;
	(void)inform;
	free(philos[0].right_fork);
	free(philos[0].each_mutex);
	free(philos);
}

void	leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_inform		inform;

	atexit(leaks);
	if (is_manual(argc, argv))
		return (0);
	if (init_inform(&inform, argc, argv) && init_philos(&philos, &inform))
	{
		start_to_eat(philos, &inform);
		monitoring(&philos, &inform);
		destory_mutex(philos, &inform);
		free_philos(philos, &inform);
	}
	return (0);
}
