/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:27 by eunson            #+#    #+#             */
/*   Updated: 2023/01/11 15:20:20 by eunson           ###   ########.fr       */
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
	return (0);
}

//eat
//mutex_lock
// 모든 철학자가 다 앉고. 
// 상(상호배제) 점(점유와 대기) 환(원형모양) 비(비선점)
// 원형을 부시던가, 규칙적으로 내려놓고 먹고를 한다거나2.(규칙적으로)
// 홀짝 -> 규칙  1 << 2 , 3
// 모든 필로소퍼가 테이블에 앉고나서 시작.
// time = gettimeofday()
// pthread_mutex_lock()
// print_philo(time, asdads);