/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunson <eunson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:20:04 by eunson            #+#    #+#             */
/*   Updated: 2023/01/21 15:22:23 by eunson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	cnt_digit(long long long_n, int n)
{
	int	cnt;

	cnt = 1;
	while (long_n >= 10)
	{
		long_n /= 10;
		cnt++;
	}
	if (n < 0)
		cnt++;
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*tmp;
	int			cnt;
	long long	long_n;

	long_n = (long long)n;
	if (long_n < 0)
		long_n *= -1;
	cnt = cnt_digit(long_n, n);
	tmp = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!tmp)
		return (0);
	if (n < 0)
		tmp[0] = '-';
	if (n == 0)
		tmp[0] = '0';
	tmp[cnt] = 0;
	while (long_n)
	{
		cnt--;
		tmp[cnt] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s++)
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		prefix_len;
	int		suffix_len;
	int		index;
	char	*return_char;

	if (!s1 || !s2)
		return (0);
	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	return_char = (char *)malloc(sizeof(char) * (prefix_len + suffix_len + 1));
	if (!return_char)
		return (0);
	index = -1;
	while (s1[++index])
		return_char[index] = s1[index];
	index = -1;
	while (s2[++index])
		return_char[prefix_len + index] = s2[index];
	return_char[prefix_len + index] = 0;
	return (return_char);
}