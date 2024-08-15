/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/15 18:02:25 by ckonneck         ###   ########.fr       */
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
    if (head == NULL)
		return NULL;

    Chunk* chunkHead = create_nodechunk(head->data);
    Chunk* chunkCurrent = chunkHead;
    Node* nodeCurrent = head->next;

    while (nodeCurrent != NULL) {
        Chunk* newChunk = create_nodechunk(nodeCurrent->data);
        chunkCurrent->next = newChunk;
        chunkCurrent = newChunk;
        nodeCurrent = nodeCurrent->next;
    }

    return (chunkHead);
}

// Function to bubble sort the linked list
void bubble_sort(Node* head) 
{
    if (head == NULL)
		return;

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

int hasLowerThanMiddle(Chunk *chunk, int middle) {
    Chunk *current = chunk;
    while (current != NULL) {
        if (current->value < middle) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int hasHigherThanMiddle(Chunk *head, int middle) {
    Chunk *current = head;
    while (current != NULL) {
        if (current->value > middle) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void freechunk(Chunk **head)
{
    if (*head == NULL)
        return;
    Chunk *temp = *head;
    *head = (*head)->next;
    free(temp);
}

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
		return(2);
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
	if (rc <= rrc)
		return (1);
	else
		return (0);
}

void sortintochunks(Chunk *chunks[], Chunk *chonks[], int i)
{
	int count = 0;
	Chunk* current = chonks[0];
	Chunk* last = NULL;
    while (current != NULL && count < 75)
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
	sortintochunks(chunks, chonks, i);
	int middle;
	middle = find_medianchunk(chunks[i]);
	int n = countnodes(tops[0]);
	while(tops[0])
	{
		n = countnodes(tops[0]);
		if(!chunks[i])
		{
			i++;
			sortintochunks(chunks, chonks, i);
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

int nextinlinechonk(Chunk *listbcopy2[])
{
		Chunk *headchonk = listbcopy2[0];
		int tempdata;
        int highest;
        
		tempdata = headchonk->value;
        highest = find_highest_integer(listbcopy2[0]);
        // ft_printf("highest is in chonk %d, temp is %d\n", highest,tempdata);
        // ft_printf("listbcopy1\n");
        //                 printchunk(listbcopy2[0]);
        if(tempdata == highest)
            return(1);
        else
            return(0);
}

int nextinlinechunk(Chunk *listbcopy1[])
{
        Chunk *head = listbcopy1[0];
		int tempdata;
        int highest;
		tempdata = head->value;
        highest = find_highest_integer(listbcopy1[0]);
        // ft_printf("highest is in chunk %d, temp is %d\n", highest,tempdata);
        // ft_printf("listbcopy1\n");
        //                 printchunk(listbcopy1[0]);

        if(tempdata == highest)
            return(1);
        else 
            return(0);
}

int pushtoaandchonk(Node *tops[], Chunk *listbcopy1[], Chunk *listbcopy2[])
{
    if (nextinlinechonk(&listbcopy2[0]) == 1)// 1 for yes
        {
            // ft_printf("listb in pushandchonk\n");//i might be wasting moves here.
            //             printList(tops[1]);
            //             // ft_printf("listbcopy1\n");
            //             // printchunk(listbcopy1[0]);
            //             ft_printf("listbcopy2\n");
            //             printchunk(listbcopy2[0]);
            // ft_printf("LOOK AT ME I'M PUSHING %d\n",tops[1]->data);
            pushtoa(&tops[1], &tops[0]);
            freechunk(&listbcopy1[0]);
            freechunk(&listbcopy2[0]);
            return(1);
        }
        else
            return(0);
}

int pushtoaandchunk(Node *tops[], Chunk *listbcopy1[], Chunk *listbcopy2[])
{
    if (nextinlinechunk(&listbcopy1[0]) == 1)// 1 for yes//IT DO BE IN HERE
        {
            // ft_printf("listb in pushandchunk\n");//i might be wasting moves here.
            //             printList(tops[1]);
            //             // ft_printf("listbcopy1\n");
            //             // printchunk(listbcopy1[0]);
            //             ft_printf("listbcopy2\n");
            //             printchunk(listbcopy2[0]);
            // ft_printf("LOOK AT ME I'M PUSHING %d\n",tops[1]->data);
            pushtoa(&tops[1], &tops[0]);
            freechunk(&listbcopy1[0]);
            freechunk(&listbcopy2[0]);
            return(1);
        }
        else
            return(0);
}

void operationrc(Node *tops[], int rc, int rrc)
{
    if (rc != 0 || rrc != 0)
            {
                while (rc != 0 && rrc != 0)
                    if (rc > rrc) 
                    {
                        reverserotateb(&tops[1]);
                        rrc--;
                    } 
                    else 
                    {
                        rotateb(&tops[1]);
                        rc--;
                    }
            }
            else
                pushtoa(&tops[1], &tops[0]);
}

void midpointsort(Node *tops[])
{
	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};

		while(tops[1])
		{
			if(isSorted(tops[0]) == 0)
				threepointalgo(tops);
			listbcopy1[0] = copyNodeToChunk(tops[1]);//theres something to think about here,
			listbcopy2[0] = copyNodeToChunk(tops[1]);//since i am copzing again every iteration

			Chunk *head = listbcopy1[0];
			int tempdata;
			int highest;
			int rc = 0;
			int rrc = 0;
			highest = find_highest_integer(listbcopy1[0]);
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
		}
	
}

