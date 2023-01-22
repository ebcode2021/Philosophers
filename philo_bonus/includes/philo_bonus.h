/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:06:14 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 20:52:37 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "const_bonus.h"
# include "error_bonus.h"
# include "struct_bonus.h"

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <semaphore.h>

/* action */
void		action(t_proc *proc);

/* checker */
int			check_arguments(int argc, char *argv[]);
int			check_one_philo(t_proc *proc);

/* die_checker */
int			check_die(t_proc *proc);
int			check_done(t_proc *proc);
int			check_over_time(t_proc *proc);
void		*die_checker(void *void_proc);

/* fork_proc */
void		child_proc(t_proc *proc, int idx);
void		fork_proc(t_proc *proc);

/* init_proc */
void		init_proc(t_proc *proc, int argc, char *argv[]);

/* manual */
int			is_manual(int argc, char *argv[]);

/* print */
void		print_action(t_proc *proc, long long start_time, char *msg);
void		print_error_with_exit(char *msg);
void		print_manual(void);

/* time */
long long	get_time(void);
long long	get_elapsed_time(long long start_time);
void		set_start_time(t_proc *proc);
void		set_time_after_eat(t_philo *philo);
void		usleep_timer(long long time);

/* utils */
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);
int			philo_atoi(char *argv);

/* wait_all_proc */
void		wait_all_proc(t_proc *proc);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif