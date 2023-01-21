/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:10:19 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 19:50:54 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philos;

	if (is_manual(argc, argv))
		return (0);
	init_info(&info, argc, argv);
	init_philos(&philos, &info);
	fork_philos(&philos, &info);
	// start_simulation(philos, &info);
	free_info();
	free(philos);
	return (0);
}