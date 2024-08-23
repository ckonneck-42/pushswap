/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bgutils4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:53:15 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:53:32 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	threepointalgobg(t_Node *topsbg[], int x)
{
	t_Node	*head;
	int		first;
	int		second;
	int		third;

	head = topsbg[0];
	first = head->data;
	second = head->next->data;
	if (countt_nodes(topsbg[0]) != 2)
	{
		third = head->next->next->data;
		if (first > second && second > third)
			x = bgop3p1(topsbg, x);
		else if (first > second && second < third && first < third)
			x = swapabg(&topsbg[0], x);
		else if (first < second && second > third && first > third)
			x = bgop3p2(topsbg, x);
		else if (first > second && second < third && first > third)
			x = bgop3p3(topsbg, x);
		else if (first < second && second > third && first < third)
			x = bgop3p4(topsbg, x);
	}
	else if (first > second)
		x = swapabg(&topsbg[0], x);
	return (x);
}

int	midpointsortbg(t_Node *topsbg[], int x)
{
	t_Chunk	*listbcopy1[1];
	t_Chunk	*listbcopy2[1];
	int		rc;
	int		rrc;

	listbcopy1[0] = NULL;
	listbcopy1[0] = NULL;
	while (topsbg[1])
	{
		rc = 0;
		rrc = 0;
		if (issorted(topsbg[0]) == 0)
			x = threepointalgobg(topsbg, x);
		listbcopy1[0] = copyt_nodetochunk(topsbg[1]);
		listbcopy2[0] = copyt_nodetochunk(topsbg[1]);
		midpointopbg(listbcopy1, listbcopy2, &rc, &rrc);
		x = operationrcbg(topsbg, rc, rrc, x);
		free_listchunk(listbcopy1[0]);
		free_listchunk(listbcopy2[0]);
	}
	return (x);
}
