/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/07 16:02:46 by ckonneck         ###   ########.fr       */
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
	while(head)
	{
		head = head->next;
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
        return (1);
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
	if (list1head <= list2head)
		return (1);
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

#include <stdio.h>

void printDataChunkArray(Chunk array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("  Value: %d\n", array[i].value);
        printf("  Position: %d\n", array[i].position);
        }
        printf("\n");
    }

void sorthalf(Node **lista, Node **listb, Element arr[], Chunk array[])
{
	int i = 0;
	int n = countnodes(*lista);
	while(*lista)
	{
		Node *head = *lista;
		int tempdata;
		tempdata = head->data;
		if(tempdata <= arr[(n-1) / 2].value)
		{
			array[i].value = tempdata;
            array[i].position = i;
			i++;
			pushtob(lista, listb);
			head = *lista;
			tempdata = head->data;
		}
		else
		{
			rotatea(lista);
			head = *lista;
			tempdata = head->data;
			int countn = countnodes(*lista);
			if(countn <= n/2)
			{
				countn /= 2;
				midpointrecursion(lista, listb, arr, countn);
				printDataChunkArray(array, n/2);
				return ;
			}
		}
	}
}



// void scanandchunk();

void midpointrecursion(Node **lista, Node **listb, Element arr[], int argc)
{
	int i = 0;
	Chunk array[i]
	 = sorthalf(lista, listb, arr, Chunk.array[i]);
	i++;
}

void stalinsort(Node **lista, Node **listb, Element arr[], int argc)
{
	int i = 0;
	while((isSorted(lista[0]) != 1) && i <= argc/2)
	{
		Node *head = *lista;
		int tempdata;
		tempdata = head->data;
		if(*lista)
		{
			Node *head = *lista;
			int tempdata;
			//  && tempdata >= arr[(argc-1) / 2].value
			tempdata = head->data;
			if (tempdata != arr[i].value)
			{
				ft_printf("entered if, compared %d with %d\n", tempdata, arr[i].value);
				pushtob(lista, listb);
				head = *lista;
				tempdata = head->data;
				
			}	//save the first 10 values  while parsing, get them, then do the next 5
				//calc costs like that in the background. could basically do background op
				// of like ra and rra, see which is less i guess. not elegant. or ask math.
			else
			{
				ft_printf("Element %d is = to %d \n", tempdata, arr[i].value);
				i++;
				rotatea(lista);
				head = *lista;
				tempdata = head->data;
				// int countn = countnodes(*lista);
				// if(countn <= argc/2)
				// {	ft_printf("argc/2: %d \n", argc/2);
				// 	ft_printf("countnodes: %d \n", countn);
				// 	return;
				// }
			}
		}
	}
}

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