/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:14 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 16:13:47 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

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

typedef struct s_inform
{
	int				philo_cnt;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_cnt;
	int				finish;
	long long		start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	routine_mutex;
}				t_inform;

typedef struct s_philo
{
	int				idx;
	int				eat_cnt;
	int				done;
	long long		time_after_eat;
	t_inform		*inform;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	each_mutex;
}				t_philo;

#endif