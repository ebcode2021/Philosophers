/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/15 20:13:16 by eunson           ###   ########.fr       */
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

/* init_inform.c */
int			init_inform(t_inform *inform, int argc, char **argv);

/* init_philos.c */
int			init_philos(t_philo **philos, t_inform *inform);

/* main.c */
int			main(int argc, char **argv);

/* print.c */
int			print_error(char *msg);
void		print_action(t_philo *philo, char *msg);

/* routine.c */
void		*routine(void *philos_a);

/* utils.c */
int			philo_atoi(char *argv);
int			check_arguments(int argc, char **argv);
void		wait_all_thread(t_philo *philos, int total_cnt);

/* time.c */
long long	get_time(void);
void		init_philos_start_time(t_philo *philos, t_inform *inform);

#endif