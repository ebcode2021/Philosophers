/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/19 18:55:46 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	print_action(t_philo *philo, char *msg)
{
	if (ft_strncmp(msg, DIE_MSG, 5) && check_finish(philo))
		return ;
	pthread_mutex_lock(&philo->inform->print_mutex);
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

void	print_philos(t_philo *philos)
{
	int	idx;

	idx = 0;
	//while (idx < philos->inform->philo_cnt)
	//{
		printf("philos[%d] 의 왼쪽 fork : %p\n", philos[idx].idx, philos[idx].left_fork);
		printf("philos[%d] 의 오른쪽 fork : %p\n", philos[idx].idx, philos[idx].right_fork);
		//printf("each_mutex : %p\n", philos[idx].each_mutex);
	//	idx++;
	//}
}
