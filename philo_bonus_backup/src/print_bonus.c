/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:11:01 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 13:45:17 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_error_with_exit(char *msg)
{
	printf("Error :: %s\n", msg);
	exit (EXIT_FAILURE);
}

void	print_manual(void)
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
}