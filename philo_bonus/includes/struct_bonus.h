/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:06:22 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:55:35 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>

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

typedef struct s_philo
{
	int			idx;
	int			done;
	int			eat_cnt;
	char		*file_name;
	long long	last_eat;
	sem_t		*each;
}				t_philo;

typedef struct s_proc
{
	int			philo_cnt;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_cnt;
	int			finish;
	int			status;
	long long	start_time;
	sem_t		*fork;
	sem_t		*print;
	sem_t		*routine;
	t_philo		*philo;
	pthread_t	die_check;
}				t_proc;

#endif