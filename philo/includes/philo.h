/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/18 22:15:30 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "const.h"
# include "error.h"
# include "struct.h"

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

/* checker.c */
int			check_all_done(t_philo *philos, t_inform *inform);
int			check_finish(t_philo *philo);
int			check_over_time(t_philo *philo);

/* init_inform.c */
int			init_inform(t_inform *inform, int argc, char **argv);

/* init_philos.c */
int			init_philos(t_philo **philos, t_inform *inform);

/* main.c */
int			main(int argc, char **argv);

/* print.c */
void		print_action(t_philo *philo, char *msg);
int			print_error(char *msg);
int			print_manual(void);
void		print_philos(t_philo *philos);

/* routine.c */
void		*routine(void *philos_a);

/* utils.c */
int			is_manual(int argc, char **argv);
void	wait_all_thread(t_philo *philos, int total_cnt);

/* time.c */
void		init_start_time(t_philo *philos, t_inform *inform);
long long	get_time(void);
long long	get_elapsed_time(long long start_time);
void		set_time_after_eat(t_philo *philo);
void		usleep_timer(long long usleep_time);


void	print_philos(t_philo *philos);
#endif