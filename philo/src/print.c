/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 22:22:05 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo, char *msg)
{
	long long	time;
	
	time = (get_time() - philo->inform->start_time) / 1000;
	pthread_mutex_lock(&(philo->inform->print_mutex));
	printf("%lldms : %d %s\n", time, philo->idx, msg);
	pthread_mutex_unlock(&(philo->inform->print_mutex));
}

int	print_error(char *msg)
{
	printf("Error :: %s\n", msg);
	return (0);
}
