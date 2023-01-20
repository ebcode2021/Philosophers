/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:08:07 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 14:11:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_atoi(char *argv)
{
	int			idx;
	long long	num;

	idx = 0;
	num = 0;
	while (argv[idx] == 32)
		idx++;
	if (argv[idx] == '+')
	{
		if (argv[idx + 1] < '0' || argv[idx + 1] > '9')
			return (print_error(NOT_A_VALID));
		idx++;
	}
	else if (argv[idx] == '-')
		return (print_error(NOT_A_VALID));
	while (argv[idx])
	{
		if (argv[idx] < '0' || argv[idx] > '9')
			return (print_error(NOT_A_VALID));
		num = num * 10 + (argv[idx] - '0');
		if (num < INT_MIN || num > INT_MAX)
			return (print_error(NOT_A_VALID));
		idx++;
	}
	return ((int)num);
}

static int	check_arguments(int argc, char **argv)
{
	int	idx;

	idx = 1;
	if (argc < 5 || argc > 7)
		return (print_error(ARGU_CNT));
	while (argv[idx])
	{
		if (philo_atoi(argv[idx++]) == 0)
			return (print_error(NOT_A_VALID));
	}
	return (1);
}

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
	pthread_mutex_init(&inform->print_mutex, 0);
	pthread_mutex_init(&inform->routine_mutex, 0);
	if (argc == 6)
		inform->must_eat_cnt = philo_atoi(argv[5]);
	return (1);
}
