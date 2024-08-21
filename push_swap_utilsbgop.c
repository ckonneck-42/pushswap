/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilsbgop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:03 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:26:24 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int costcalcbg(Node *topsbg[], int middle)
{	
	Chunk *listbcopy3[1] = {NULL};
	Chunk *listbcopy4[1] = {NULL};
	
	listbcopy3[0] = copyNodeToChunk(topsbg[0]);
	listbcopy4[0] = copyNodeToChunk(topsbg[0]);
	Node *head = topsbg[0];
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

 int backgroundoperations(Node *topsbg[], Chunk *chunksbg[], Chunk *chonksbg[],
 int argc, char **argv, int *numbers)
{	
	Chunk *calcs[100] = {NULL};
	int best = 0;
	int calcc = 1;
	int x = 0;
	int i = 0;
    while(i < 100)
	{
        calcs[i] = malloc(sizeof(Chunk));// can outsource this for sure
        if (calcs[i] == NULL)
		{
			 free(calcs[i]);
            return -1;
		}
		calcs[i]->calcc = 0;
        calcs[i]->chunksize = 0;
		calcs[i]->next = NULL;
		i++;
    }
	while (calcc < 100)
	{
		x = sorthalfbg(topsbg, chunksbg,chonksbg, x, calcc); 
    	x = midpointsortbg(topsbg, x);
		x = threepointalgobg(topsbg, x);
		calcs[calcc]->calcc = calcc;
		calcs[calcc]->chunksize = x;
		calcc++;
		x = 0;
		free_all( chunksbg, topsbg, chonksbg);
		reformbg(argc, argv, topsbg, chunksbg, chonksbg, numbers);
	}
	best = bubblesortchunkbg(calcs, calcc-1);
	free_allbg( chunksbg, topsbg, chonksbg, calcs);
	return (best);
}

void sortintochunksbg(Chunk *chunksbg[], Chunk *chonksbg[], int i, int calcc)
{
	int count = 0;
	Chunk* current = chonksbg[0];
	Chunk* last = NULL;
	while (current != NULL && count < calcc)
	{
		Chunk* new_node = copy_current_chunk(current);
		if (chunksbg[i] == NULL) 
			chunksbg[i] = new_node;
		else
			last->next = new_node;
		last = new_node;
		Chunk* temp = chonksbg[0];
		chonksbg[0] = chonksbg[0]->next;
		free(temp);
		current = chonksbg[0];
		count++;
	}
}

void reformbg(int argc, char **argv, Node *topsbg[], Chunk *chunksbg[], Chunk *chonksbg[], int *numbers)
{
	topsbg[0] = NULL;
	topsbg[1] = NULL;
    for (int i = 1; i < argc; i++) {
        if(ft_isnumeric(argv[i]) != 1)
        {
            ft_printf("can't parse non numeric data");
            exit (-1);
        }
		int arg = ft_atoi(argv[i]);
       append(&topsbg[0], arg);
    }
	for(int i = 0; i < 500; i++)
	{
		chunksbg[i] = NULL;
		chonksbg[i] = NULL;
	}
	for (int i = 0; i < argc-1; i++) {
    actuallyappendchunk(&chonksbg[0], numbers[i]); ///uncomment
    }
}


int sorthalfbg(Node *topsbg[],Chunk *chunksbg[], Chunk *chonksbg[], int x, int calcc)
{
	int i = 1;
	sortintochunksbg(chunksbg, chonksbg, i, calcc);
	int middle;
	middle = find_medianchunk(chunksbg[i]);
	// ft_printf("medianchunk %d\n", middle);
	while(topsbg[0])
	{
		if(!chunksbg[i])
		{
			i++;
			sortintochunksbg(chunksbg, chonksbg, i, calcc);
		}
		middle = find_medianchunk(chunksbg[i]);//check this more
		int flag = costcalcbg(topsbg, middle);
		if(flag == 2)
		{
			freethespecificdatabg(chunksbg, i, topsbg);
			x = pushtobbg(&topsbg[0], &topsbg[1], x);
		}
		else if(flag == 1)
			x = rotateabg(&topsbg[0], x);
		else if(flag == 0)
			x = reverserotateabg(&topsbg[0], x);
	}
	return (x);
}

int threepointalgobg(Node *topsbg[], int x)
{
	Node *head = topsbg[0];
	int first;
	int second;
	int third;
	first = head->data;
	second = head->next->data;
	if (countnodes(topsbg[0]) != 2)
	{
		third = head->next->next->data;
		if (first > second && second > third)
		{
			x = pushtobbg(&topsbg[0], &topsbg[1], x);// might need to do 
			x = swapabg(&topsbg[0], x);// x = function for every function that
			x = rotateabg(&topsbg[0], x);// might increment x
			x = rotateabg(&topsbg[0], x);
			x = pushtoabg(&topsbg[0], &topsbg[0], x);
			x = reverserotateabg(&topsbg[0], x);
			x = reverserotateabg(&topsbg[0], x);
		}
		else if (first > second && second < third && first < third)
			x = swapabg(&topsbg[0], x);
		else if (first < second && second > third && first > third)
		{
			x = pushtobbg(&topsbg[0], &topsbg[1], x);
			x = swapabg(&topsbg[0], x);
			x = rotateabg(&topsbg[0], x);
			x = pushtoabg(&topsbg[0], &topsbg[0], x);
			x = reverserotateabg(&topsbg[0], x);
		}
		else if (first > second && second < third && first > third)
		{
			x = pushtobbg(&topsbg[0], &topsbg[1], x);
			x = rotateabg(&topsbg[0], x);
			x = rotateabg(&topsbg[0], x);
			x = pushtoabg(&topsbg[1], &topsbg[0], x);
			x = reverserotateabg(&topsbg[0], x);
			x = reverserotateabg(&topsbg[0], x);
		}
		else if (first < second && second > third && first < third)
		{
			x = pushtobbg(&topsbg[0], &topsbg[1], x);
			x = swapabg(&topsbg[0], x);
			x = pushtoabg(&topsbg[1], &topsbg[0], x);
		}
	}
	else if (first > second)
		x = swapabg(&topsbg[0], x);
return (x);
}



int midpointsortbg(Node *topsbg[], int x)
{
	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};

	int tempdata;
	int highest;
	int rc;
	int rrc;
		while(topsbg[1])
		{
			rc = 0;
			rrc = 0;
			if(issorted(topsbg[0]) == 0)
				x = threepointalgobg(topsbg, x);
			listbcopy1[0] = copyNodeToChunk(topsbg[1]);
			listbcopy2[0] = copyNodeToChunk(topsbg[1]);
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
			x = operationrcbg(topsbg, rc, rrc, x);
			free_listchunk(listbcopy1[0]);
			free_listchunk(listbcopy2[0]);
		}
	return (x);
}
