/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 20:29:12 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->inform->print_mutex));
	printf("%lldms : ", get_elapsed_time(philo->inform->start_time));
	printf("%d %s\n", philo->idx, msg);
	pthread_mutex_unlock(&(philo->inform->print_mutex));
}

int	print_error(char *msg)
{
	printf("Error :: %s\n", msg);
	return (0);
}
