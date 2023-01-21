/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:06:38 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 19:32:57 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	fork_philos(t_philo *philos, t_info *info)
{
	int		idx;
	pid_t	pid;

	sem_wait(info->routine);
	while (idx < info->philo_cnt)
	{
		pid = fork();
		if (pid == CHILD)
		{
			action(&philos[idx], info);
			break;
		}
		info->pid[idx] = pid;
		idx++;
	}
}

void	init_philos(t_philo *philos, t_info *info)
{
	int	idx;
	
	philos = (t_philo *)malloc(sizeof(t_philo) * info->philo_cnt);
	if (!philos)
		print_error_with_exit(MALLOC_FAIL);
	idx = 0;
	while (idx < info->philo_cnt)
	{
		philos[idx].idx = idx + 1;
		philos[idx].eat_cnt = 0;
		philos[idx].done = 0;
		philos[idx].file_name = ft_strjoin("file_", ft_itoa(philos[idx].idx));
		sem_unlink(philos[idx].file_name);
		philos[idx].each = sem_open(philos[idx].file_name, O_CREAT, 0666, 1);
	}
	fork_philos(philos, info);
}
