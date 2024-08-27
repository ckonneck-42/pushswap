/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:52:24 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 15:46:59 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortmidfree(t_Datastruct *sdata, t_Chunk **chunks, t_Chunk **chonks,
		int magicnumber)
{
	sorthalf(sdata->tops, chunks, chonks, magicnumber);
	midpointsort(sdata->tops);
	free_all2(chunks, sdata->tops, chonks, sdata->numbers);
}

static int	find_min(t_Node **tops)
{
	int		i;
	int		min_val;
	int		index;
	t_Node	*temp;

	temp = *tops;
	i = 0;
	index = 0;
	min_val = temp->data;
	while (temp != NULL)
	{
		if (min_val > temp->data)
		{
			min_val = temp->data;
			index = i;
		}
		i++;
		temp = temp->next;
	}
	return (index);
}

void	four_arg_sort(t_Node **tops)
{
	if (find_min(tops) == 1)
		swapa(&tops[0]);
	else if (find_min(tops) == 2)
	{
		reverserotatea(&tops[0]);
		reverserotatea(&tops[0]);
	}
	else if (find_min(tops) == 3)
		reverserotatea(&tops[0]);
	pushtob(&tops[0], &tops[1]);
	argc3(tops);
	pushtoa(&tops[1], &tops[0]);
}

void	five_arg_sort(t_Node **tops)
{
	if (find_min(tops) == 1)
		swapa(&tops[0]);
	else if (find_min(&tops[0]) == 2)
	{
		rotatea(&tops[0]);
		rotatea(&tops[0]);
	}
	else if (find_min(tops) == 3)
	{
		reverserotatea(&tops[0]);
		reverserotatea(&tops[0]);
	}
	else if (find_min(tops) == 4)
		reverserotatea(&tops[0]);
	pushtob(&tops[0], &tops[1]);
	four_arg_sort(tops);
	pushtoa(&tops[1], &tops[0]);
}

void	twotofiveargs(t_Datastruct *sdata, int argc, int old_argc, char **argv)
{
	if (old_argc == 2)
		argc3(sdata->tops);
	if (argc == 3)
		swapa(sdata->tops);
	if (argc == 4)
		argc3op(sdata, old_argc, argv);
	if (argc == 5)
		four_arg_sort(sdata->tops);
	if (argc == 6)
		five_arg_sort(sdata->tops);
	argc3op(sdata, old_argc, argv);
}
