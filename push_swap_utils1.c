/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:22:54 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int costcalc(Node *tops[], int middle)
{	
	Chunk *listbcopy3[1] = {NULL};
	Chunk *listbcopy4[1] = {NULL};
	
	listbcopy3[0] = copyNodeToChunk(tops[0]);
	listbcopy4[0] = copyNodeToChunk(tops[0]);
	Node *head = tops[0];
	int tempdata;
	int rrc = 0;
	int rc = 0;
	
	
	tempdata = head->data;
	if (tempdata <= middle)
	{
		free_listchunk(listbcopy3[0]);
		free_listchunk(listbcopy4[0]);
		return(2);
	}
		
	while (tempdata > middle)
	{
		reverserotatebchunk(&listbcopy3[0]);
		rrc++;
		tempdata = listbcopy3[0]->value;
	}
	tempdata = head->data;
	while (tempdata > middle)
	{
		rotatebchunk(&listbcopy4[0]);
		rc++;
		tempdata = listbcopy4[0]->value;
	}
	free_listchunk(listbcopy3[0]);
	free_listchunk(listbcopy4[0]);
	if (rc <= rrc)
		return (1);
	else
		return (0);
}


void sortintochunks(Chunk *chunks[], Chunk *chonks[], int i, int magicnumber)
{
	int count = 0;
	Chunk* current = chonks[0];
	Chunk* last = NULL;
	while (current != NULL && count < magicnumber)
	{
		Chunk* new_node = copy_current_chunk(current);
		if (chunks[i] == NULL) 
			chunks[i] = new_node;
		else
			last->next = new_node;
		last = new_node;
		Chunk* temp = chonks[0];
		chonks[0] = chonks[0]->next;
		free(temp);
		current = chonks[0];
		count++;
	}
}

int sorthalf(Node *tops[],Chunk *chunks[], Chunk *chonks[], int magicnumber)
{
	int i = 1;
	sortintochunks(chunks, chonks, i, magicnumber);
	int middle;
	middle = find_medianchunk(chunks[i]);
	while(tops[0])
	{
		if(!chunks[i])
		{
			i++;
			sortintochunks(chunks, chonks, i, magicnumber);
		}
		middle = find_medianchunk(chunks[i]);
		int flag = costcalc(tops, middle);
		if(flag == 2)
		{
			freethespecificdata(chunks, i, tops);
			pushtob(&tops[0], &tops[1]);
		}
		else if(flag == 1)
			rotatea(&tops[0]);
		else if(flag == 0)
			reverserotatea(&tops[0]);
	}
	return (i);
}

void threepointalgo(Node *tops[])
{
	Node *head = tops[0];
	int first;
	int second;
	int third;
	first = head->data;
	second = head->next->data;
	if (countnodes(tops[0]) != 2)
	{
		third = head->next->next->data;
		if (first > second && second > third)
		{
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first < third)
			swapa(&tops[0]);
		else if (first < second && second > third && first > third)
		{
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first > third)
		{
			pushtob(&tops[0], &tops[1]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first < second && second > third && first < third)
		{
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
		}
	}
	else if (first > second)
		swapa(&tops[0]);
}



void midpointsort(Node *tops[])
{
	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};

	int tempdata;
	int highest;
	int rc;
	int rrc;
	while(tops[1])
	{
		rc = 0;
		rrc = 0;
		if(issorted(tops[0]) == 0)
			threepointalgo(tops);
		listbcopy1[0] = copyNodeToChunk(tops[1]);
		listbcopy2[0] = copyNodeToChunk(tops[1]);
		highest = find_highest_integer(listbcopy1[0]);
		Chunk *head = listbcopy1[0];
		tempdata = head->value;
		while(tempdata != highest)
		{
			rotatebchunk(&listbcopy1[0]);
			rc++;
			tempdata = listbcopy1[0]->value;
		}
		tempdata = head->value;
		while(tempdata != highest)
		{
			reverserotatebchunk(&listbcopy2[0]);
			rrc++;
		tempdata = listbcopy2[0]->value;
		}
		operationrc(tops, rc, rrc);
		free_listchunk(listbcopy1[0]);
		free_listchunk(listbcopy2[0]);
	}
}

