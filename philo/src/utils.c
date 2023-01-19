/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:22:38 by eunson            #+#    #+#             */
/*   Updated: 2023/01/19 18:56:40 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 다 먹었는지 체크하는 부분
// 어디선가 탈출함 ( finish == 1이 되는 부분 )
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while ((*u_s1 || *u_s2) && n)
	{
		if (*u_s1 != *u_s2)
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
		n--;
	}
	return (0);
}

int	is_manual(int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "--help", 7))
		return (print_manual());
	return (0);
}

void	wait_all_thread(t_philo **philos, int total_cnt)
{
	int	idx;

	idx = 0;

	while (idx < total_cnt)
	{
		pthread_join((*philos)[idx].thread_id, 0);
		idx++;
	}
}
