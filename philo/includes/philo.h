/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:16 by eunson            #+#    #+#             */
/*   Updated: 2023/01/14 18:14:15 by eunson           ###   ########.fr       */
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
int			init_philos(t_philo **philos, t_inform inform);

/* main.c */
int			main(int argc, char **argv);

/* print.c */
int			print_error(char *msg);
void		print_philo(long long time, int philo_num, char *msg);

/* routine.c */
void		*routine(void *philos_a);

/* utils.c */


#endif