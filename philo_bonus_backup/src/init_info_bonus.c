/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:41:20 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 18:45:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
			print_error_with_exit(NOT_A_VALID);
		idx++;
	}
	else if (argv[idx] == '-')
		print_error_with_exit(NOT_A_VALID);
	while (argv[idx])
	{
		if (argv[idx] < '0' || argv[idx] > '9')
			print_error_with_exit(NOT_A_VALID);
		num = num * 10 + (argv[idx] - '0');
		if (num < INT_MIN || num > INT_MAX)
			print_error_with_exit(NOT_A_VALID);
		idx++;
	}
	return ((int)num);
}

static int	check_arguments(int argc, char **argv)
{
	int	idx;

	idx = 1;
	if (argc < 5 || argc > 7)
		print_error_with_exit(ARGU_CNT);
	while (argv[idx])
	{
		if (philo_atoi(argv[idx]) == 0)
			print_error_with_exit(NOT_A_VALID);
		idx++;
	}
	return (1);
}

void	init_info(t_info *info, int argc, char *argv[])
{
	if (!check_arguments(argc, argv))
		exit(EXIT_FAILURE);
	info->philo_cnt = philo_atoi(argv[1]);
	info->time_to_die = philo_atoi(argv[2]);
	info->time_to_eat = philo_atoi(argv[3]);
	info->time_to_sleep = philo_atoi(argv[4]);
	info->must_eat_cnt = 0;
	info->finish = 0;
	if (argc == 6)
		info->must_eat_cnt = philo_atoi(argv[5]);
	info->pid = (pid_t *)malloc(sizeof(pid_t) * info->philo_cnt);
	if (!info->pid)
		print_error_with_exit(MALLOC_FAIL);
	init_sem(info);
}
