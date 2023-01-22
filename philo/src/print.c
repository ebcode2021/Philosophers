/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 19:43:22 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->inform->print_mutex);
	if (check_finish(philo) && ft_strncmp(msg, DIE_MSG, 5))
	{
		pthread_mutex_unlock(&philo->inform->print_mutex);
		return ;
	}
	printf("%lld ", get_elapsed_time(philo->inform->start_time));
	printf("%d %s\n", philo->idx, msg);
	pthread_mutex_unlock(&philo->inform->print_mutex);
}

int	print_error(char *msg)
{
	printf("Error :: %s\n", msg);
	return (0);
}

int	print_manual(void)
{
	printf("-------------------------------------------------------------\n\n");
	printf("║▌│█║▌│ █║▌│█│║▌█║▌│ █│█║▌│ ██│║▌║\n");
	printf("\t This is Manual for you...∧,,,∧\n");
	printf("\t\t\t       (  ̳• · • ̳) \n");
	printf("\t\t\t         /    /r 🎁\n\n");
	printf("| First             : number_of_philosophers\n");
	printf("| Second            : time_to_die\n");
	printf("| Third             : time_to_eat\n");
	printf("| Fourth            : time_to_sleep\n");
	printf("| Fifth(optional)   : number_of_times_each_philosopher_must_eat\n\n");
	printf("-------------------------------------------------------------\n\n");
	return (1);
}
