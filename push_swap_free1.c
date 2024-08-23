/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:10:15 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 10:55:47 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_listt_node(t_Node *head)
{
	t_Node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_listchunk(t_Chunk *head)
{
	t_Chunk	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_all(t_Chunk *chunksbg[], t_Node *topsbg[], t_Chunk *chonksbg[])
{
	int	i;

	i = 1;
	free_listt_node(topsbg[1]);
	free_listt_node(topsbg[0]);
	while (i < 500)
	{
		free_listchunk(chunksbg[i]);
		free_listchunk(chonksbg[i]);
		i++;
	}
}

void	free_all2(t_Chunk *chunks[], t_Node *tops[], t_Chunk *chonks[])
{
	int	i;

	i = 0;
	if (tops[1] != NULL)
		free_listt_node(tops[1]);
	if (tops[0] != NULL)
		free_listt_node(tops[0]);
	while (i < 100)
	{
		if (chunks[i] != NULL)
			free_listchunk(chunks[i]);
		if (chonks[i] != NULL)
			free_listchunk(chonks[i]);
		i++;
	}
}

void	free_allbg(t_Chunk *chunksbg[], t_Node *topsbg[], t_Chunk *chonksbg[],
		t_Chunk *calcs[])
{
	int	i;

	i = 1;
	free_listchunk(chonksbg[0]);
	if (topsbg[1] != NULL)
		free_listt_node(topsbg[1]);
	if (topsbg[0] != NULL)
		free_listt_node(topsbg[0]);
	while (i < 100)
	{
		if (chunksbg[i] != NULL)
			free_listchunk(chunksbg[i]);
		if (chonksbg[i] != NULL)
			free_listchunk(chonksbg[i]);
		i++;
	}
	i = 0;
	while (i < 100)
	{
		if (calcs[i] != NULL)
			free_listchunk(calcs[i]);
		i++;
	}
}
