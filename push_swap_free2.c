/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:11:15 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 08:55:54 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freechunk(t_Chunk **head)
{
	t_Chunk	*temp;

	if (*head == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

void	freethespecificdata(t_Chunk *chunks[], int i, t_Node *tops[])
{
	t_Chunk	*headchunk;
	t_Chunk	*prevchunk;

	headchunk = chunks[i];
	prevchunk = NULL;
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

void	freethespecificdatabg(t_Chunk *chunksbg[], int i, t_Node *topsbg[])
{
	t_Chunk	*headchunk;
	t_Chunk	*prevchunk;

	headchunk = chunksbg[i];
	prevchunk = NULL;
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

void	argvfree(char **argv, int magicnumber, int old_argc)
{
	if (old_argc == 2)
	{
		magicnumber = 1;
		while (argv[magicnumber])
		{
			free(argv[magicnumber]);
			magicnumber++;
		}
		free(argv);
	}
}
