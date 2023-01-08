/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/08 14:07:33 by eunson           ###   ########.fr       */
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

/* main.c */
int			init_philos(t_philos *philos, int argc, char **argv);
int			main(int argc, char **argv);

/* print.c */
int			print_error(char *msg);
void		print_philo(long long time, int philo_num, char *msg);


/* utils.c */
int			check_arguments(int argc, char **argv);
int			philo_atoi(char *argv);

#endif