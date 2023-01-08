/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:25:14 by eunson            #+#    #+#             */
/*   Updated: 2023/01/08 14:02:21 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum e_bool
{ 
	TRUE = 1,
	FALSE = -1,
};

typedef struct s_philos
{
	int	cnt;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_cnt;
}				t_philos;

#endif