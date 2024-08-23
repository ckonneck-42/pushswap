/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:00:46 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	costcalc(t_Node *tops[], int middle)
{
	t_Ccop	op;
	int		rrc;
	int		rc;
	int		result;

	op = (t_Ccop){NULL, 0, NULL, NULL};
	op.listbcopy3 = copyt_nodetochunk(tops[0]);
	op.listbcopy4 = copyt_nodetochunk(tops[0]);
	op.head = tops[0];
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

void	sortintochunks(t_Chunk *chunks[], t_Chunk *chonks[], int i,
		int magicnumber)
{
	int		count;
	t_Chunk	*current;
	t_Chunk	*last;
	t_Chunk	*new_t_node;
	t_Chunk	*temp;

	count = 0;
	current = chonks[0];
	last = NULL;
	while (current != NULL && count < magicnumber)
	{
		new_t_node = copy_current_chunk(current);
		if (chunks[i] == NULL)
			chunks[i] = new_t_node;
		else
			last->next = new_t_node;
		last = new_t_node;
		temp = chonks[0];
		chonks[0] = chonks[0]->next;
		free(temp);
		current = chonks[0];
		count++;
	}
}

int	sorthalf(t_Node *tops[], t_Chunk *chunks[], t_Chunk *chonks[],
		int magicnumber)
{
	int	i;
	int	middle;
	int	flag;

	i = 1;
	sortintochunks(chunks, chonks, i, magicnumber);
	middle = find_medianchunk(chunks[i]);
	while (tops[0])
	{
		i = minifunc(chunks, chonks, magicnumber, i);
		middle = find_medianchunk(chunks[i]);
		flag = costcalc(tops, middle);
		if (flag == 2)
		{
			freethespecificdata(chunks, i, tops);
			pushtob(&tops[0], &tops[1]);
		}
		else if (flag == 1)
			rotatea(&tops[0]);
		else if (flag == 0)
			reverserotatea(&tops[0]);
	}
	return (i);
}

void	threepointalgo(t_Node *tops[])
{
	t_Node	*head;
	int		first;
	int		second;
	int		third;

	head = tops[0];
	first = head->data;
	second = head->next->data;
	if (countt_nodes(tops[0]) != 2)
	{
		third = head->next->next->data;
		if (first > second && second > third)
			op3p1(tops);
		else if (first > second && second < third && first < third)
			swapa(&tops[0]);
		else if (first < second && second > third && first > third)
			op3p2(tops);
		else if (first > second && second < third && first > third)
			op3p3(tops);
		else if (first < second && second > third && first < third)
			op3p4(tops);
	}
	else if (first > second)
		swapa(&tops[0]);
}

void	midpointsort(t_Node *tops[])
{
	t_Chunk	*listbcopy1[1];
	t_Chunk	*listbcopy2[1];
	int		rc;
	int		rrc;

	listbcopy1[0] = NULL;
	listbcopy1[0] = NULL;
	while (tops[1])
	{
		rc = 0;
		rrc = 0;
		if (issorted(tops[0]) == 0)
			threepointalgo(tops);
		listbcopy1[0] = copyt_nodetochunk(tops[1]);
		listbcopy2[0] = copyt_nodetochunk(tops[1]);
		midpointopbg(listbcopy1, listbcopy2, &rc, &rrc);
		operationrc(tops, rc, rrc);
		free_listchunk(listbcopy1[0]);
		free_listchunk(listbcopy2[0]);
	}
}
