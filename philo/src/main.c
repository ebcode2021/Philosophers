/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 18:15:50 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	simulation(t_philo *philos, t_inform inform)
{
	(void) philos;
	pthread_mutex_unlock(&inform.routine_mutex);
	while (1)
		;
}

int main(int argc, char **argv)
{
	t_philo			*philos;
	t_inform		inform;

	if (init_inform(&inform, argc, argv) && init_philos(&philos, inform))
	{
		simulation(philos, inform);
		//free_philos();
	}
	return (0);
}
