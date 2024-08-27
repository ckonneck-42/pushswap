/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:24:29 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 08:55:20 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**stringhandling(int *argc, char **argv)
{
	int		total_words;
	char	**new_argv;
	int		new_index;

	total_words = 0;
	new_argv = NULL;
	total_words = countwords(argv, argc, total_words);
	new_argv = argvalloc(new_argv, total_words);
	new_index = 0;
	new_argv[new_index++] = argv[0];
	new_argv = actualsplit(argv, &new_index, argc, new_argv);
	new_argv[new_index] = NULL;
	*argc = new_index;
	return (new_argv);
}

char	**argvalloc(char **new_argv, int total_words)
{
	new_argv = malloc((total_words + 2) * sizeof(char *));
	if (!new_argv)
	{
		ft_printf("malloc");
		exit(1);
	}
	return (new_argv);
}

int	countwords(char **argv, int *argc, int total_words)
{
	int	j;

	j = 0;
	while (j < (*argc))
	{
		total_words += count_words(argv[j], ' ');
		j++;
	}
	return (total_words);
}

char	**actualsplit(char **argv, int *new_index, int *argc, char **new_argv)
{
	int		j;
	int		i;
	char	**temp;

	i = 1;
	temp = NULL;
	while (i < (*argc))
	{
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			new_argv[(*new_index)++] = temp[j];
			j++;
		}
		free(temp);
		i++;
	}
	return (new_argv);
}

void	initsortapp(t_Datastruct *sdata, t_Chunk *chunks[], t_Chunk *chonks[],
		int argc)
{
	initchunks(chunks, chonks);
	bubblesortarr(sdata->numbers, argc - 1);
	appendchunks(chonks, sdata->chonksbg, sdata->numbers, argc);
}
