/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:11:15 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:25:26 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void freechunk(Chunk **head)
{
	if (*head == NULL)
		return;
	Chunk *temp = *head;
	*head = (*head)->next;
	free(temp);
}

void freethespecificdata(Chunk *chunks[], int i, Node *tops[])
{
	Chunk *headchunk = chunks[i];
	Chunk *prevchunk = NULL;

	while (headchunk != NULL && headchunk->value != tops[0]->data)
	{
		prevchunk = headchunk;
		headchunk = headchunk->next;
	}

	if (headchunk != NULL && headchunk->value == tops[0]->data)
	{
		if (prevchunk == NULL)
			freechunk(&chunks[i]);
		else
		{
			prevchunk->next = headchunk->next;
			free(headchunk);
		}
	}
}

void freethespecificdatabg(Chunk *chunksbg[], int i, Node *topsbg[])
{
	Chunk *headchunk = chunksbg[i];
	Chunk *prevchunk = NULL;

	while (headchunk != NULL && headchunk->value != topsbg[0]->data)
	{
		prevchunk = headchunk;
		headchunk = headchunk->next;
	}

	if (headchunk != NULL && headchunk->value == topsbg[0]->data)
	{
		if (prevchunk == NULL)
			freechunk(&chunksbg[i]);
		else
		{
			prevchunk->next = headchunk->next;
			free(headchunk);
		}
	}
}
