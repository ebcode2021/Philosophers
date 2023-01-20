/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:37:41 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 15:27:07 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(pthread_mutex_t **forks, int total)
{
	int	idx;

	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * total);
	if (!*forks)
		return (print_error(MALLOC_FAIL));
	idx = 0;
	while (idx < total)
		pthread_mutex_init((*forks) + (idx++), 0);
	return (1);
}
