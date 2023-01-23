/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:25:52 by eunson            #+#    #+#             */
/*   Updated: 2023/01/23 11:58:41 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_inform		info;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (is_manual(argc, argv))
		return (0);
	if (init_inform(&info, argc, argv) && init_forks(&forks, info.philo_cnt))
	{
		if (init_philos(&philos, &forks, &info))
		{
			start_to_simulation(philos, &info);
			monitoring(philos, &info);
			destory_mutex(philos, &info);
			free(philos);
			free(forks);
		}
	}
	return (0);
}
