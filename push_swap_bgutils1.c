/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bgutils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:03 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:54:10 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	costcalcbg(t_Node *topsbg[], int middle)
{
	t_Ccop	op;
	int		rrc;
	int		rc;
	int		result;

	op = (t_Ccop){NULL, 0, NULL, NULL};
	op.listbcopy3 = copyt_nodetochunk(topsbg[0]);
	op.listbcopy4 = copyt_nodetochunk(topsbg[0]);
	op.head = topsbg[0];
	op.middle = middle;
	rrc = 0;
	rc = 0;
	result = costcalcopbg(&op, &rc, &rrc);
	if (result == 2)
		return (2);
	free_listchunk(op.listbcopy3);
	free_listchunk(op.listbcopy4);
	if (rc <= rrc)
		return (1);
	else
		return (0);
}

int	backgroundoperations(t_Datastruct *sdata, int argc, char **argv)
{
	t_Chunk	*calcs[100];
	int		best;
	int		calcc;
	int		x;

	best = 0;
	calcc = 1;
	x = 0;
	bgopcalc(calcs);
	while (calcc < 100)
	{
		x = sorthalfbg(sdata, x, calcc);
		x = midpointsortbg(sdata->topsbg, x);
		x = threepointalgobg(sdata->topsbg, x);
		update_calcs(calcs, &calcc, &x);
		free_all(sdata->chunksbg, sdata->topsbg, sdata->chonksbg);
		reformbg(argc, argv, sdata);
	}
	best = bubblesortchunkbg(calcs, calcc - 1);
	free_allbg(sdata->chunksbg, sdata->topsbg, sdata->chonksbg, calcs);
	return (best);
}

void	sortintochunksbg(t_Chunk *chunksbg[], t_Chunk *chonksbg[], int i,
		int calcc)
{
	int		count;
	t_Chunk	*current;
	t_Chunk	*last;
	t_Chunk	*new_t_node;
	t_Chunk	*temp;

	count = 0;
	current = chonksbg[0];
	last = NULL;
	while (current != NULL && count < calcc)
	{
		new_t_node = copy_current_chunk(current);
		if (chunksbg[i] == NULL)
			chunksbg[i] = new_t_node;
		else
			last->next = new_t_node;
		last = new_t_node;
		temp = chonksbg[0];
		chonksbg[0] = chonksbg[0]->next;
		free(temp);
		current = chonksbg[0];
		count++;
	}
}

void	reformbg(int argc, char **argv, t_Datastruct *sdata)
{
	int	i;

	sdata->topsbg[0] = NULL;
	sdata->topsbg[1] = NULL;
	reformos(argc, argv, sdata->topsbg);
	i = 0;
	while (i < 500)
	{
		sdata->chunksbg[i] = NULL;
		sdata->chonksbg[i] = NULL;
		i++;
	}
	i = -1;
	while (i++ < argc - 2)
		actuallyappendchunk(&sdata->chonksbg[0], sdata->numbers[i]);
}

int	sorthalfbg(t_Datastruct *sdata, int x, int calcc)
{
	int	i;
	int	middle;
	int	flag;

	i = 1;
	sortintochunksbg(sdata->chunksbg, sdata->chonksbg, i, calcc);
	middle = find_medianchunk(sdata->chunksbg[i]);
	while (sdata->topsbg[0])
	{
		if (!sdata->chunksbg[i])
		{
			i++;
			sortintochunksbg(sdata->chunksbg, sdata->chonksbg, i, calcc);
		}
		middle = find_medianchunk(sdata->chunksbg[i]);
		flag = costcalcbg(sdata->topsbg, middle);
		x = flagop(sdata, i, x, flag);
	}
	return (x);
}
