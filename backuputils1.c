/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backuputils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/07 15:08:45 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int bubblesort(int arr[], int n) {
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
	
	
	return(arr[n / 2]);
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

    Node* current = head;
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
void algorithm (Node **lista, Node **listb, int median)
{
	while(isSorted(lista[0]) != 1 || isSortedB(listb[0]) != 1)
	{
		//insert error handling
		
		Node *heada = *lista;
		Node *tempa = *lista;
		Node *tempca = *lista;
		
		Node *headb = *listb;
		Node *tempb = *listb;
		// Node *tempcb = *listb;
		
		int firsta;
		int seconda;
		int lasta;
		int counta;
		int firstb;
		int secondb;
		int lastb;
		int countb;
		countb = 0;
		
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

		if((*listb != NULL && (*listb)->next != NULL) &&
		((*listb)->next->next != NULL))
		{
			firstb = headb->data;
			secondb = headb->next->data;
			while (tempb->next != NULL)
				tempb = tempb->next;
			lastb = tempb->data;
		}
		
		counta = 0;
		while(tempca != NULL && counta < 6)
    	{
        	tempca = tempca->next;
        	counta++;
    	}
		if (counta == 6 && tempca != NULL)
			if (comparesums(lista[0]) == 1)
			{
				pushtob(&lista[0], &listb[0]);
				pushtob(&lista[0], &listb[0]);
				pushtob(&lista[0], &listb[0]);
			}
		if(firsta > seconda) 
			swapa(&lista[0]);
		else if(firsta < lasta){
			pushtob(&lista[0], &listb[0]);
			continue;
		}
		else if (firsta == lasta || firsta > lasta)
			reverserotatea(&lista[0]);
		
		if((*listb != NULL && (*listb)->next != NULL)
			&& firstb < secondb)
			swapb(&listb[0]);
		else if ((*listb != NULL && tempb->next != NULL)
			&& firstb < lastb)
			rotateb(&lista[0]);
		else if ((*listb != NULL && tempb->next != NULL)
			&& firstb > lastb)
			reverserotateb(&listb[0]);
			
			
		if (isSorted(*lista) == 1 && isSortedB(*listb) == 1)
			{	
				while(listb != NULL)
				{
					pushtoa(listb, &lista[0]);
					// ft_printf("conglaturation, you've sorted everything!");
				}
					
			}
	}
	// ft_printf("yay?");
}




int initelem(int *numbers, int argc)
{
    int i = 0;
    Element arr[argc-1];
    // Assuming the array is already sorted and filled with values
    for (int i = 0; i < argc-1; i++) {
        arr[i].position = i;
        arr[i].value = numbers[i];
    }
    printArray(arr, argc-1);
    return(arr);
}


    // Element arr[] = initelem(numbers, argc);
    

	void sorthalf(Node **lista, Node **listb, Element arr[], int argc)
{
	while(1)
	{
		Node *head = *lista;
		int tempdata;
		int countforargc = countnodes(*lista);
		tempdata = head->data;
		if(tempdata <= arr[(countforargc) / 2].value)
		{
			
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
			if(countn <= (countforargc) / 2)
			{
				ft_printf("argc/2: %d \n", argc/2);
				ft_printf("countnodes: %d \n", countn);
				return;
			}
		}argc -=1;
	}
}