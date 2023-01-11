/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:14 by eunson            #+#    #+#             */
/*   Updated: 2023/01/11 15:40:38 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum e_bool
{ 
	TRUE = 1,
	FALSE = 0,
};

typedef struct s_inform
{
	int	philo_cnt;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_cnt;
	int	finish; 
	pthread_t	routine_mutex;
	pthread_t	print_mutex;
	//start_mutex도 넣어주고. print_mutex
}				t_inform;

typedef struct s_philo
{
	int			idx;
	int			eat_cnt;
	int			time_after_eat;
	int			left_fork;
	int			right_fork;
	t_inform	inform;
	pthread_t	thread_id;
}				t_philo;

#endif