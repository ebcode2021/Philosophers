/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/08 14:08:10 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_philos *philos, int argc, char **argv)
{
	if (!check_arguments(argc, argv))
		return (0);
	philos->cnt = philo_atoi(argv[1]);
	philos->time_to_die = philo_atoi(argv[2]);
	philos->time_to_eat = philo_atoi(argv[3]);
	philos->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		philos->must_eat_cnt = philo_atoi(argv[5]);
	else
		philos->must_eat_cnt = 0;
	return (1);
}

int main(int argc, char **argv)
{
	t_philos	philos;

	if (init_philos(&philos, argc, argv)) //성공적으로 데이터가 들어왔을 경우
	{
		printf("성공\n");
		
	}
	return (0);
}
