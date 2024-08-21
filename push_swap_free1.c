/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:10:15 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:10:30 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_listnode(Node *head)
{
	Node *temp;
	while(head)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
}

void free_listchunk(Chunk *head)
{
	Chunk *temp;
	while(head)
	{
		temp = head;
		head = head->next;
		free (temp);
	}
}

void free_all(Chunk *chunksbg[], Node *topsbg[], Chunk *chonksbg[])
{
		free_listnode(topsbg[1]);
		free_listnode(topsbg[0]);
	for(int i = 1; i < 500; i++)
	{
		free_listchunk(chunksbg[i]);
		free_listchunk(chonksbg[i]);
	}
}

void free_all2(Chunk *chunks[], Node *tops[], Chunk *chonks[])
{
		free_listnode(tops[1]);
		free_listnode(tops[0]);
	for(int i = 1; i < 200; i++)
	{
		free_listchunk(chunks[i]);
		free_listchunk(chonks[i]);
	}
}

void free_allbg(Chunk *chunksbg[], Node *topsbg[], Chunk *chonksbg[], Chunk *calcs[])
{
	free_listchunk(chonksbg[0]);
	if(topsbg[1] != NULL)
		free_listnode(topsbg[1]);
	if(topsbg[0] != NULL)
		free_listnode(topsbg[0]);
	for(int i = 1; i < 500; i++)
	{
		if(chunksbg[i] != NULL)
			free_listchunk(chunksbg[i]);
		if(chonksbg[i] != NULL)
			free_listchunk(chonksbg[i]);
	}
	for(int i = 0; i < 100; i++)
	{
		if(calcs[i] != NULL)
			free_listchunk(calcs[i]);
	}
}