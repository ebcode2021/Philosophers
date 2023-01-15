/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:22:38 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 20:15:09 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_atoi(char *argv)
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

int	check_arguments(int argc, char **argv)
{
	int	idx;

	idx = 1;
	if (argc < 5 || argc > 6)
	{
		print_error(ARGU_CNT);
		return (0);
	}
	while (argv[idx])
	{
		if (philo_atoi(argv[idx++]) == FALSE)
		{
			print_error(NOT_A_VALID);
			return (0);
		}
	}
	return (argc);
}

void	wait_all_thread(t_philo *philos, int total_cnt)
{
	int	idx;

	idx = 0;
	while (idx < total_cnt)
	{
		pthread_join(philos[idx].thread_id, 0);
		idx++;
	}
}
