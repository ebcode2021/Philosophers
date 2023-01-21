/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:45:30 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 20:45:45 by eunson           ###   ########.fr       */
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

int	check_arguments(int argc, char **argv)
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