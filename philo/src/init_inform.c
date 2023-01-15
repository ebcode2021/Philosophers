/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:08:07 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 16:41:03 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	pthread_mutex_init(&(inform->print_mutex), 0);
	pthread_mutex_init(&(inform->routine_mutex), 0);
	if (argc == 6)
		inform->must_eat_cnt = philo_atoi(argv[5]);
	return (1);
}
