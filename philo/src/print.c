/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 17:03:33 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	long long	time;
	
	pthread_mutex_lock(&(philo->inform->print_mutex));
	time = get_elapsed_time(philo->inform->start_time);
	printf("%lldms : %d %s\n", time, philo->idx, msg);
	pthread_mutex_unlock(&(philo->inform->print_mutex));
}

int	print_error(char *msg)
{
	printf("Error :: %s\n", msg);
	return (0);
}
