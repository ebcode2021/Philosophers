/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/08 14:02:28 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(long long time, int philo_num, char *msg)
{
	printf("%lldms : %d %s\n", time, philo_num, msg);
}

int	print_error(char *msg)
{
	printf("Error :: %s\n", msg);
	return (FALSE);
}