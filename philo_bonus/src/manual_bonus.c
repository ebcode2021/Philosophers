/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:38:36 by eunson            #+#    #+#             */
/*   Updated: 2023/01/22 17:15:20 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while ((*u_s1 || *u_s2) && n)
	{
		if (*u_s1 != *u_s2)
			return (*u_s1 - *u_s2);
		u_s1++;
		u_s2++;
		n--;
	}
	return (0);
}

int	is_manual(int argc, char *argv[])
{
	if (argc == 2 && !ft_strncmp(argv[1], "--help", 7))
	{
		print_manual();
		return (1);
	}
	return (0);
}