/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:24:29 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 16:05:32 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**stringhandling(int *argc, char **argv)
{
	int		total_words;
	char	**new_argv;
	int		new_index;
	char	**temp;
	int		j;

	total_words = 0;
	for (int k = 1; k < (*argc); k++)
	{
		total_words += count_words(argv[k], ' ');
	}
	new_argv = malloc((total_words + 2) * sizeof(char *));
	if (!new_argv)
	{
		ft_printf("malloc");
		exit(1);
	}
	new_index = 0;
	new_argv[new_index++] = argv[0];
	for (int i = 1; i < (*argc); i++)
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			new_argv[new_index++] = temp[j];
			j++;
		}
		free(temp); // Free the temporary array
	}
	new_argv[new_index] = NULL;
	*argc = new_index;
	return (new_argv);
}
