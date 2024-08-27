/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:23:59 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 14:30:37 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_or_spaces(const char *argv)
{
	if (argv == NULL || *argv == '\0')
	{
		return (1);
	}
	return (0);
}

int	nb_is_zero(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	else
		return (1);
}

int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i + 1] != '\0' && is_sign(av[i]))
		i++;
	while (av[i] != '\0' && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

int	is_sign(char c)
{
	return ((c == '+') || (c == '-'));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
