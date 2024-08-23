/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:23 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 16:01:51 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minifunc(t_Chunk *chunks[], t_Chunk *chonks[], int magicnumber, int i)
{
	if (!chunks[i])
	{
		i++;
		sortintochunks(chunks, chonks, i, magicnumber);
	}
	return (i);
}

t_Chunk	*process_nodes(t_Node *t_nodecurrent, t_Chunk *chunkcurrent)
{
	t_Chunk	*newchunk;
	t_Chunk	*temp;

	while (t_nodecurrent != NULL)
	{
		newchunk = create_t_nodechunk(t_nodecurrent->data);
		if (newchunk == NULL)
		{
			while (chunkcurrent != NULL)
			{
				temp = chunkcurrent;
				chunkcurrent = chunkcurrent->next;
				free(temp);
			}
			return (NULL);
		}
		chunkcurrent->next = newchunk;
		chunkcurrent = newchunk;
		t_nodecurrent = t_nodecurrent->next;
	}
	return (chunkcurrent);
}

void	argc3(t_Node *tops[])
{
	t_Node	*head;
	int		first;
	int		second;
	int		third;

	head = tops[0];
	first = head->data;
	second = head->next->data;
	third = head->next->next->data;
	if (first > second && second > third)
	{
		rotatea(&tops[0]);
		swapa(&tops[0]);
	}
	else if (first > second && second < third && first < third)
		swapa(&tops[0]);
	else if (first < second && second > third && first > third)
		reverserotatea(&tops[0]);
	else if (first > second && second < third && first > third)
		rotatea(&tops[0]);
	else if (first < second && second > third && first < third)
	{
		reverserotatea(&tops[0]);
		swapa(&tops[0]);
	}
}

void	argc3op(t_Datastruct *sdata, int old_argc, char **argv)
{
	argc3(sdata->tops);
	free(sdata->numbers);
	free_listt_node(sdata->tops[0]);
	free_listt_node(sdata->topsbg[0]);
	if (old_argc == 2)
	{
		int i = 1;
	while(argv[i]){
		free(argv[i]);
		i++;
	}
	free(argv);
	}
	
	exit(0);
}

void	initchunks(t_Chunk *chunks[], t_Chunk *chonks[])
{
	int i;

	i = 0;
	while (i < 100)
	{
		chunks[i] = NULL;
		chonks[i] = NULL;
		i++;
	}
}