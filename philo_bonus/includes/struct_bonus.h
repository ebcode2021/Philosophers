/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:06:22 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 22:28:47 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

#include <unistd.h>

enum	e_fork
{
	TAKE = 1,
	PUT = 0,
};

enum	e_do
{
	EAT = 1,
	SLEEP = 2,
	THINK = 3,
};

typedef struct	s_info
{
	pid_t	*pid;
	int		proc_cnt;
}				t_info;

typedef struct	s_proc
{
	int			philo_cnt;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_cnt;
	int			finish;
	long long	start_time;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*routine;
	t_philo		*philo;
}				t_proc;

// typedef struct s_info
// {
// 	pid_t		*pid;
// 	int			philo_cnt;
// 	int			time_to_die;
// 	int			time_to_eat;
// 	int			time_to_sleep;
// 	int			must_eat_cnt;
// 	int			finish;
// 	long long	start_time;
// 	sem_t		*fork;
// 	sem_t		*print;
// 	sem_t		*routine;
// 	t_philo		*philos;
// }				t_info;

typedef struct s_philo
{
	int			idx;
	int			done;
	int			eat_cnt;
	char		*file_name;
	long long	last_eat;
	sem_t		*each;
}				t_philo;

#endif