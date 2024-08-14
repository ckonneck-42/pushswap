/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/14 16:16:13 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	bubblesort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }	
	
	

}


int countnodes(Node *head)
{
	int i = 0;
	Node *temp = head;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
int countnodeschunk(Chunk *head)
{
	int i = 0;
	Chunk *temp = head;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void cpra (Node **list)
{
	Node* head = *list;
	Node* temp = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list A is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int last;
	first = head->data;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->data;
	
	if (first>last)
	{
		rotatea(&list[0]);
	}
	ft_printf("cpra ");
}

void cprb (Node **list)
{
	Node* head = *list;
	Node* temp = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list B is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int last;
	first = head->data;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->data;
	
	if (first>last)
	{
		rotateb(&list[0]);
		ft_printf("cprb ");
	}
	
}

void cpsa (Node **list)
{
	Node *head = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list A is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int second;
	
	first = head->data;
	second = head->next->data;
	
	if (first>second)
	{
		swapa(&list[0]);
		ft_printf("cpsa");
	}
}

void cpsb (Node **list)
{
	Node *head = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list B is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int second;
	
	first = head->data;
	second = head->next->data;
	
	if (first>second)
	{
		swapb(&list[0]);
		ft_printf("cpsb");
	}
}


int isSorted(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return (2); //maybe change this to 2 so i can sort
    }

    Node *current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return (0); 
        }
        current = current->next;
    }

    return (1); 
}

int isSortedB(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return (1);
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->data < current->next->data) {
            return (0); 
        }
        current = current->next;
    }

    return (1); 
}

int comparesums(Node *head)
{
	int sum1;
	int sum2;
	int i;

	sum1 = 0;
	sum2 = 0;
	i = 0;
	while(i < 3)
	{
		sum1 += head->data;
		head = head->next;
		i++;
	}
	i = 0;
	while(i < 3)
	{
		sum2 += head->data;
		head = head->next;
		i++;
	}
	if (sum1 <= sum2)
		return (1);
	else
		return (0);
}

int comparelisttops(Node **lista, Node **listb)
{
	Node *listan = *lista;
	Node *listbn = *listb;
	int list1head;
	int list2head;
	
	list1head = 0;
	list2head = 0;
	list1head += listan->data;
	list2head += listbn->data;
	ft_printf("WE ARE COMPARING %d AND %d\n", list1head, list2head);
	if (list1head >= list2head)
	{
		pushtoa(listb, lista);
		swapa(lista);
		return(1);
	}
	else
		return (0);
}

// void firstsort (Node **lista, Node **listb, int median, int argc)
// {
// 	while(1)
// 	{
// 		Node *heada = *lista;
// 		if(*lista)
// 		{
// 			int countn = countnodes(*lista);
			
// 			if(countn <= argc/2)
// 			{	ft_printf("argc/2: %d \n", argc/2);
// 				ft_printf("countnodes: %d \n", countn);
// 				return;
// 			}
			
// 			if(heada->data <= median)
// 				pushtob(lista, listb);
// 			else
// 				reverserotatea(lista);
// 		}
// 	}
// }

void halfit (Node **lista, Node **listb, int argc)
{
	while(1)
	{
		if(*lista)
		{
			int countn = countnodes(*lista);
			
			if(countn <= argc/2)
			{	ft_printf("argc/2: %d \n", argc/2);
				ft_printf("countnodes: %d \n", countn);
				return;
			}
			pushtob(lista, listb);
		}
	}
}

void sendit (Node **lista, Node **listb)
{
	while(1)
	{
		if(*lista)
		{
			int countn = countnodes(*lista);
			
			if(countn <= 3)
			{
				ft_printf("countnodes: %d \n", countn);
				return;
			}
			pushtob(lista, listb);
		}
	}
}

int find_middle(Chunk* head) {
    Chunk* slow = head;
    Chunk* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (slow->value);
}

//OMG PLEASE DELETE THIS ASAP

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Chunk* create_nodechunk(int value) {
    Chunk* new_node = (Chunk*)malloc(sizeof(Chunk));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
// Function to copy the linked list
Node* copy_list(Node* head) {
    if (head == NULL) return NULL;

    Node* new_head = create_node(head->data);
    Node* current = new_head;
    Node* original = head->next;

    while (original != NULL) {
        current->next = create_node(original->data);
        current = current->next;
        original = original->next;
    }
    return new_head;
}
Chunk* copy_listchunk(Chunk* head) {
    if (head == NULL) return NULL;

    Chunk* new_head = create_nodechunk(head->value);
    Chunk* current = new_head;
    Chunk* original = head->next;

    while (original != NULL) {
        current->next = create_nodechunk(original->value);
        current = current->next;
        original = original->next;
    }
    return new_head;
}

Chunk* copy_current_chunk(Chunk* node) {
    if (node == NULL) return NULL;

    Chunk* new_node = create_nodechunk(node->value);
    return new_node;
}

Chunk* copyNodeToChunk(Node* head) {
    if (head == NULL) return NULL;

    Chunk* chunkHead = create_nodechunk(head->data);
    Chunk* chunkCurrent = chunkHead;
    Node* nodeCurrent = head->next;

    while (nodeCurrent != NULL) {
        Chunk* newChunk = create_nodechunk(nodeCurrent->data);
        chunkCurrent->next = newChunk;
        chunkCurrent = newChunk;
        nodeCurrent = nodeCurrent->next;
    }

    return chunkHead;
}

// Function to bubble sort the linked list
void bubble_sort(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node* current;
    Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Function to find the median value
int find_median(Node* head) {
    if (head == NULL) return -1; // Handle empty list

    // Copy and sort the list
    Node* sorted_copy = copy_list(head);
    bubble_sort(sorted_copy);

    // Traverse to find the median
    Node* slow = sorted_copy;
    Node* fast = sorted_copy;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    int median = slow->data;

    // Free the copied list
    while (sorted_copy != NULL) {
        Node* temp = sorted_copy;
        sorted_copy = sorted_copy->next;
        free(temp);
    }

    return median;
}

void swap(Chunk* a, Chunk* b) {
    int tempValue = a->value;
    int tempPosition = a->position;
    a->value = b->value;
    a->position = b->position;
    b->value = tempValue;
    b->position = tempPosition;
}

// Function to perform Bubble Sort on the linked list
void bubblesortchunk(Chunk* head) {
    int swapped;
    Chunk* ptr1;
    Chunk* lptr = NULL;

    // Checking for empty list
    if (head == NULL)
        return;

    swapped = 1;
    while (swapped) {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

int find_medianchunk(Chunk *head) {
    if (head == NULL) return -1; // Handle empty list

    // Copy and sort the list
    Chunk *sorted_copy = copy_listchunk(head);
    bubblesortchunk(sorted_copy);

    // Traverse to find the median
    Chunk *slow = sorted_copy;
    Chunk *fast = sorted_copy;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    int median = slow->value;

    // Free the copied list
    while (sorted_copy != NULL) {
        Chunk *temp = sorted_copy;
        sorted_copy = sorted_copy->next;
        free(temp);
    }

    return median;
}



//PLEASE DELETE THE ABOVE ASAP

#include <stdio.h>

// void printDataChunkArray(Chunk chunk, int size)
// {
//     printf("Chunk size: %d\n", chunk.size);
//     for (int i = 0; i < size; i++) {
//         printf("Element %d: value = %d, position = %d\n", i, chunk.arr[i].value, chunk.arr[i].position);
//     }
// }

int hasLowerThanMiddle(Chunk *chunk, int middle) {
    Chunk *current = chunk;
    while (current != NULL) {
        if (current->value < middle) {
            return 1; // Found a number lower than the middle point
        }
        current = current->next;
    }
    return 0; // No number lower than the middle point found
}

int hasHigherThanMiddle(Chunk *head, int middle) {
    Chunk *current = head;
    while (current != NULL) {
        if (current->value > middle) {
            return 1; // Found a number lower than the middle point
        }
        current = current->next;
    }
    return 0; // No number lower than the middle point found
}

void freechunk(Chunk **head)
{
    if (*head == NULL)
        return; // If the list is empty, do nothing
    Chunk *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// void addbottomchunk(Chunk **headRef, int value, int position) {
//     // 1. Allocate new node
//     Chunk *new1Node = newNodechunk(value, position);

//     // 4. If the Linked List is empty, then make the new node as head
//     if (*headRef == NULL) {
//         *headRef = new1Node;
//         return;
//     }

//     // 5. Else traverse till the last node
//     Chunk *last = *headRef;
//     while (last->next != NULL) {
//         last = last->next;
//     }

//     // 6. Change the next of last node
//     last->next = new1Node;
// }

int find_highest_integer(Chunk *head) {
    int highest = INT_MIN;
    Chunk *current = head;

    while (current != NULL) {
        if (current->value > highest) {
            highest = current->value;
        }
        current = current->next;
    }

    return highest;
}


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
		// ft_printf("tempdata: %d, middle : %d, in costcalc\n", tempdata, middle);
		// ft_printf("temp matches, returning 2\n");
		return(2);
	}
			// ft_printf("listbcopy3\n");
			// printchunk(listbcopy3[0]);
			// ft_printf("listbcopy4\n");
			// printchunk(listbcopy4[0]);
			// ft_printf("tempdata: %d\n", tempdata);
			// ft_printf("middle: %d\n", middle);
	while (tempdata > middle)
	{
		// ft_printf("somethings not right here");
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
	
	// ft_printf("rrc is: %d\n rc is: %d\n", rrc, rc);
	if (rc <= rrc)
	{
		// ft_printf("returning 1\n");
		return (1);
	}
	else
	{
		// ft_printf("returning 0\n");
		return (0);
	}
}

void sortintochunks(Chunk *chunks[], Chunk *chonks[], int i)
{
	int count = 0;
	Chunk* current = chonks[0];
	// Chunk *chunkshead = chonks[0];
	// ft_printf("chonk 0 before\n");
	// printchunk(chonks[0]);
	// ft_printf("chunk i before\n");
	// printchunk(chunks[i]);
	Chunk* last = NULL;

    while (current != NULL && count < 48) //48 for 500, 16 for 100
	{
        Chunk* new_node = copy_current_chunk(current);
        if (chunks[i] == NULL) 
		{
            chunks[i] = new_node;
        } 
		else 
		{
            last->next = new_node;
        }
        last = new_node;


		Chunk* temp = chonks[0];
        chonks[0] = chonks[0]->next;
        free(temp);
        current = chonks[0];
        count++;
    }
	// ft_printf("chunk 0 after\n");
	// printchunk(chonks[0]);
	// ft_printf("chunk i after\n");
	// printchunk(chunks[i]);
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


int sorthalf(Node *tops[],Chunk *chunks[], Chunk *chonks[], int i)
{
	sortintochunks(chunks, chonks, i);/////////////////123123123123
	int middle;
	middle = find_medianchunk(chunks[i]);
	int n = countnodes(tops[0]);

	while(tops[0])
	{
		
		n = countnodes(tops[0]);
		
		if(!chunks[i])//changed instead of tops[0]
		{
		
			i++;
			
			sortintochunks(chunks, chonks, i);
			
		}
			middle = find_medianchunk(chunks[i]);//changed instead of tops[0]
		Node *head = tops[0];
		int tempdata;// obsolete atm
		tempdata = head->data;

		// ft_printf("chunk %i\n", i);
		// printchunk(chunks[i]);
		// ft_printf("tops[0]\n");
		// printList(tops[0]);
		// ft_printf("tempdata: %d\n", tempdata);
		// ft_printf("middle: %d\n", middle);
		// ft_printf("RIGHT %d \n", i);//SEGFAULT SOMEWHERE, FIND IT
		int flag = costcalc(tops, middle);
		if(flag == 2)
		{
			freethespecificdata(chunks, i, tops);
			pushtob(&tops[0], &tops[1]);
			
			// appendchunk(&chunks[i], tempdata);//FREE THE DATA WHERE I PUSH FROM CHUNKS[i]
			head = tops[0];
			tempdata = head->data;//can prolly be moved out of the ifs and at the end, gotta test though
		}
		else if(flag == 1)//copy list and do calc in fc
		{
			
			rotatea(&tops[0]);
			head = tops[0];
			tempdata = head->data;
		}
		else if(flag == 0)//copy list and do calc in fc
		{
			reverserotatea(&tops[0]);//if i swap these i segfault, check why i guess 
			head = tops[0];
			tempdata = head->data;
		}
		
		if (n <= 3)
			return (i);
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
		
		// ft_printf("list a before\n");
		// printList(tops[0]);
		if (first > second && second > third)
		{
			// ft_printf("con1");
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first < third)
		{
			// ft_printf("con2");
			swapa(&tops[0]);
		}
			
		else if (first < second && second > third && first > third)
		{
			// ft_printf("con3");
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first > third)
		{
			// ft_printf("con4");
			pushtob(&tops[0], &tops[1]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first < second && second > third && first < third)
		{
			// ft_printf("con5");
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
		}
	}
	else if (first > second)
		swapa(&tops[0]);
	
	
	// ft_printf("list a after\n");
	// printList(tops[0]);
	
	// ft_printf("list b \n");
	// printList(listb);

}
// screw the chunks for now, lets go for broke, a copy is on github
//now do cost implementation for initial push to b. !!!!!!!!!!!!!!!!!!!!!!!111111oneoneeleven
//also implement for less than 3 algo pls.
void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// comparelisttops(&tops[0], &tops[1]);
	//put function here to compare tops0 and tops1 and if tops1>tops0 then do pa and sa
	// int k = 0;
	// int o = 0;

	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};
	while(i > 0) //while 
	{
			
		
		if (tops[1] == NULL)// i guess this works if i increment chunks too far
			{
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(tops[1])//while
		{
			if(isSorted(tops[0]) == 0)
			threepointalgo(tops);
			
			listbcopy1[0] = copyNodeToChunk(tops[1]);
			listbcopy2[0] = copyNodeToChunk(tops[1]);
			
			// ft_printf("listbcopy1\n");
			// printchunk(listbcopy1[0]);
			// ft_printf("listbcopy2\n");
			// printchunk(listbcopy2[0]);
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			tempdata = head->value;
			int highest = find_highest_integer(listbcopy1[0]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(tops[1])
			{	
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("listbcopy1\n");
				// printchunk(listbcopy1[0]);
				// ft_printf("listbcopy2\n");
				// printchunk(listbcopy2[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(listbcopy1[0]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					rotatebchunk(&listbcopy1[0]);
					rc++;
					tempdata = listbcopy1[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&listbcopy2[0]);
					rrc++;
					tempdata = listbcopy2[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							//FIND THE HIGHEST VALUE IN CHUNK AND FREE
							// THAT ONE INSTEAD OF THE HEAD YOU DUMB FUCK
							rrc--;
						}
						// ft_printf("pushing in rc > %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing rc > chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc > chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					// ft_printf("freeing rc > listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					// ft_printf("freeing rc > listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
						while(temprrc -1 != 0)
						{
							rotateb(&tops[1]);
							rotatebchunk(&listbcopy2[0]);///////////
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						// ft_printf("pushing in rc < %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]); //good
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);//shit be fuczzled yo
					// ft_printf("freeing rc < chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc < chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					// ft_printf("freeing rc < listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					// ft_printf("freeing rc < listbcopy2: %d\n", listbcopy2[0]->value);
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&listbcopy1[0]);
							temprc--;
						}
					}
					
				}
				else
				{
					// printList(tops[0]);
					// printchunk(chunks[i]);
					// printchunk(chonks[i]);
					// ft_printf("pushing IN ELSE %d\n", tops[1]->data);
					pushtoa(&tops[1], &tops[0]);
					// if(isSorted(tops[0]) == 1)
					// 		threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing IN ELSE chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing IN ELSE chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					// ft_printf("freeing IN ELSE listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					// ft_printf("freeing IN ELSE listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("listbcopy1\n");
				// printchunk(listbcopy1[0]);
				// ft_printf("listbcopy2\n");
				// printchunk(listbcopy2[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}


// void scanandchunk();

// void midpointrecursion(Node *tops[], Element arr[], int argc, int i)
// {
	

	
// 	if (argc <= 3)
// 		exit(1);

// 	i++;
// 	sorthalf(tops, arr, i);
	
// }

// void stalinsort(Node **lista, Node **listb, Element arr[], int argc)
// {
// 	int i = 0;
// 	while((isSorted(lista[0]) != 1) && i <= argc/2)
// 	{
// 		Node *head = *lista;
// 		int tempdata;
// 		tempdata = head->data;
// 		if(*lista)
// 		{
// 			Node *head = *lista;
// 			int tempdata;
// 			//  && tempdata >= arr[(argc-1) / 2].value
// 			tempdata = head->data;
// 			if (tempdata != arr[i].value)
// 			{
// 				ft_printf("entered if, compared %d with %d\n", tempdata, arr[i].value);
// 				pushtob(lista, listb);
// 				head = *lista;
// 				tempdata = head->data;
				
// 			}	//save the first 10 values  while parsing, get them, then do the next 5
// 				//calc costs like that in the background. could basically do background op
// 				// of like ra and rra, see which is less i guess. not elegant. or ask math.
// 			else
// 			{
// 				ft_printf("Element %d is = to %d \n", tempdata, arr[i].value);
// 				i++;
// 				rotatea(lista);
// 				head = *lista;
// 				tempdata = head->data;
// 				// int countn = countnodes(*lista);
// 				// if(countn <= argc/2)
// 				// {	ft_printf("argc/2: %d \n", argc/2);
// 				// 	ft_printf("countnodes: %d \n", countn);
// 				// 	return;
// 				// }
// 			}
// 		}
// 	}
// }

void algorithm (Node **lista, Node **listb, int median, int argc)
{
	argc -=1;
	while(isSorted(lista[0]) != 1 || isSortedB(listb[0]) != 1)
	{
		//insert error handling
		
		Node *heada = *lista;
		Node *tempa = *lista;
		// Node *tempca = *lista;
		
		Node *headb = *listb;
		// Node *tempb = *listb;
		// Node *tempcb = *listb;
		
		int firsta;
		int seconda;
		int lasta;
		// int counta;
		int firstb;
		// int secondb;
		// int lastb;
		// int countb;
		// countb = 0;
		
		firsta = heada->data;
		seconda = heada->next->data;
		while (tempa->next != NULL)
			tempa = tempa->next;
		lasta = tempa->data;

		// while(tempcb != NULL && countb < 6)
    	// {
        // 	tempcb = tempcb->next;
        // 	countb++;
    	// }
			// in case i want to implement costcomparison for list b
		// if (countb == 6 && tempcb != NULL)
		// {
		// 	firstb = headb->data;
		// 	secondb = headb->next->data;
		// 	while (tempb->next != NULL)
		// 		tempb = tempb->next;
		// 	lastb = tempb->data;
		// }

		if((*listb != NULL))
		{
		// 	 && (*listb)->next != NULL) &&
		// ((*listb)->next->next != NULL))
			firstb = headb->data;
			// secondb = headb->next->data;
			// while (tempb->next != NULL)
			// 	tempb = tempb->next;
			// lastb = tempb->data;

			if(firsta <= firstb)
				pushtoa(listb, lista);
			else if (firsta > firstb)
				rotatea(lista);
			else
				pushtoa(listb, lista);
											// so. if i go ahead with this insertion algo,
											// id have to find the highest value and lowest value
											// and compare it against every bit that im trying to 
											// insert, overall its still not gonna pass the tests, 
											// so id have to go further for sure
			// else if (firstb > firsta)
			// {
			// 	rotateb(listb);
			// 	pushtoa(listb, lista);
			// }
			 // else
			// 	pushtoa(listb, lista);
		}
		// ft_printf("list a \n");
    	// printList(*lista);
    	// ft_printf("list b \n");
    	// printList(*listb);
			median = 0;
		
		// counta = 0;
		// while(tempca != NULL && counta < 6)
    	// {
        // 	tempca = tempca->next;
        // 	counta++;
    	// }
		// if (counta == 6 && tempca != NULL)
		// 	if (comparesums(lista[0]) == 1)
		// 	{
		// 		pushtob(&lista[0], &listb[0]);
		// 		pushtob(&lista[0], &listb[0]);
		// 		pushtob(&lista[0], &listb[0]);
		// 	}

		
		
	// 	else if (firsta == lasta || firsta > lasta)
	// 		reverserotatea(&lista[0]);
		
	// 	if((*listb != NULL && (*listb)->next != NULL)
	// 		&& firstb < secondb)
	// 		swapb(&listb[0]);
	// 	else if ((*listb != NULL && tempb->next != NULL)
	// 		&& firstb < lastb)
	// 		rotateb(&lista[0]);
	// 	else if ((*listb != NULL && tempb->next != NULL)
	// 		&& firstb > lastb)
	// 		reverserotateb(&listb[0]);
			
			
		if (isSorted(*lista) == 1 && isSortedB(*listb) == 1)
			{	
				while(listb != NULL)
				{
					pushtoa(listb, &lista[0]);
					// ft_printf("conglaturation, you've sorted everything!");
				}
			}
	}
	ft_printf("yay?");
}


// stalinsort into B with any value thats not in order, leaving a sorted array in the wake
// also can then sort like half of the highernumbers over, then sort the B stack?
//