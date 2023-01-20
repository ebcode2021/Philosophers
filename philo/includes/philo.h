/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/20 20:35:55 by eunson           ###   ########.fr       */
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

/* action.c */
void		*action(void *void_philo);

/* checker.c */
int			check_all_done(t_philo *philos, t_inform *inform);
int			check_finish(t_philo *philo);
int			check_one_philo(t_philo *philo);
int			check_over_time(t_philo *philo);
int			check_stop_monitoring(t_philo *philos, t_inform *inform);

/* destroy_mutex.c */
void		destory_mutex(t_philo *philos, t_inform *inform);

/* init_forks.c */
int			init_forks(pthread_mutex_t **fork, int total);

/* init_inform.c */
int			init_inform(t_inform *inform, int argc, char **argv);

/* init_philos.c */
int			init_philos(t_philo **philos, \
						pthread_mutex_t **forks, t_inform *info);

/* main.c */
int			main(int argc, char **argv);

/* monitoring.c */
void		monitoring(t_philo *philos, t_inform *inform);

/* print.c */
void		print_action(t_philo *philo, char *msg);
int			print_error(char *msg);
int			print_manual(void);

/* start_to_simulation.c */
void		start_to_simulation(t_philo *philos, t_inform *inform);

/* time.c */
long long	get_time(void);
long long	get_elapsed_time(long long start_time);
void		set_start_time(t_philo *philos, t_inform *inform);
void		set_time_after_eat(t_philo *philo);
void		usleep_timer(long long usleep_time);

/* utils.c */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			is_manual(int argc, char **argv);

#endif