/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:22:39 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 14:24:23 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_input(char **av)
{
	int			i;
	int			zero_count;
	long long	n;

	i = 1;
	zero_count = 0;
	while (av[i])
	{
		n = pushft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (!arg_is_number(av[i]))
			return (0);
		zero_count += nb_is_zero(av[i]);
		i++;
	}
	if (zero_count > 1)
		return (0);
	if (has_doubles(av))
		return (0);
	return (1);
}

int	has_doubles(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_compare(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_compare(const char *s1, const char *s2)
{
	int	x;
	int	y;

	x = ft_atoi(s1);
	y = ft_atoi(s2);
	return (x - y);
}

long long	pushft_atoi(const char *str)
{
	int			count;
	long long	res;
	int			sign;

	count = 0;
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		count++;
		str++;
	}
	if (count > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
