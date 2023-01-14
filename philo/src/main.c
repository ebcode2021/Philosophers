/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 21:18:10 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	main_process(t_philo *philos, t_inform *inform)
{
	init_philos_time(philos, inform);
	pthread_mutex_unlock(&inform->routine_mutex);
	while (inform->finish == 0)
		;
}

// static void	free_philos(t_philo *philos)
// {

// }

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_inform		inform;

	if (init_inform(&inform, argc, argv) && init_philos(&philos, &inform))
	{
		main_process(philos, &inform);
		//free_philos(philos);
	}
	return (0);
}
