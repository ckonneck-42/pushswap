/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:14:24 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/07 16:19:36 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

Node* newNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL) {
        ft_printf("Error: could not allocate memory\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void append(Node **headRef, int data) {
    // 1. Allocate new node
    Node* new1Node = newNode(data);

    // 4. If the Linked List is empty, then make the new node as head
    if (*headRef == NULL) {
        *headRef = new1Node;
        return;
    }

    // 5. Else traverse till the last node
    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    // 6. Change the next of last node
    last->next = new1Node;
}

void swapb(Node** list)
{
    if (*list != NULL && (*list)->next != NULL)
    {
        Node* first = *list;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        *list = second;

        ft_printf("sb\n");
    }
    else
        ft_printf("not enough values to swap in list B\n");
}

void swapa(Node **list)
{
    if (*list != NULL && (*list)->next != NULL)
    {
        Node* first = *list;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        *list = second;

        ft_printf("sa\n");
    }
    else
        ft_printf("not enough values to swap in list A\n");
}

void ss(Node **lista, Node **listb)
{
    if ((*lista != NULL && (*lista)->next != NULL) &&
    (*listb != NULL && (*listb)->next != NULL) )
    {
        swapa(lista);
        swapb(listb);
        ft_printf("(ss)");
    }
    else    
        ft_printf("not enough values to swap in list A or B\n");
}

void pushtob(Node **sourceRef, Node **destRef) {
    // Get the first node from the source list
    Node* newtopofb = *sourceRef;
    if (newtopofb != NULL) {
        // Move the source pointer to the next node
        *sourceRef = newtopofb->next;

        // Push the node onto the destination list
        newtopofb->next = *destRef;
        *destRef = newtopofb;
        ft_printf("pb ");
    }
    else
        ft_printf("list B is empty\n");
}

void pushtoa(Node **sourceRef, Node **destRef) {
    // Get the first node from the source list
    Node* newtopofa = *sourceRef;
    if (newtopofa != NULL) {
        // Move the source pointer to the next node
        *sourceRef = newtopofa->next;

        // Push the node onto the destination list
        newtopofa->next = *destRef;
        *destRef = newtopofa;
        ft_printf("pa\n");
    }
    else
        ft_printf("list A is empty\n");
}

void rotatea(Node** lista)
{
    Node* newbottom = *lista;
    Node* second = newbottom->next;
   
    if(newbottom != NULL)
    {
        *lista = second;
        newbottom->next = NULL;
        Node* last = *lista;
        while(last->next != NULL)
            last = last->next;
        last->next = newbottom;
        ft_printf("ra\n");
    }
    else
        ft_printf("list A empty\n");
}

void rotateb(Node** listb)
{
    Node* newbottom = *listb;
    Node* second = newbottom->next;
   
    if(newbottom != NULL)
    {
        *listb = second;
        newbottom->next = NULL;
        Node* last = *listb;
        while(last->next != NULL)
            last = last->next;
        last->next = newbottom;
        ft_printf("rb\n");
    }
    else
        ft_printf("list B empty\n");
}

void rr(Node** lista, Node** listb)
{
    if ((*lista != NULL && (*lista)->next != NULL) &&
        (*listb != NULL && (*listb)->next != NULL) )
    {
        rotatea(lista);
        rotateb(listb);
        ft_printf("(rr)");
    }
    else
        ft_printf("not enough values to rotate in list A or B\n");
}

void reverserotatea(Node** lista)
{
    Node* newtop = *lista;
    if(*lista != NULL ||(*lista)->next != NULL)
    {
        while(newtop->next->next != NULL)
            newtop = newtop->next;
        newtop->next->next = *lista;
        *lista = newtop->next;
        newtop->next = NULL;
        ft_printf("rra ");
    }
    else
        ft_printf("list A empty\n");
}

void reverserotateb(Node** listb)
{
    Node* newtop = *listb;
    if(*listb != NULL || (*listb)->next != NULL)
    {
        while(newtop->next->next != NULL)
            newtop = newtop->next;
        newtop->next->next = *listb;
        *listb = newtop->next;
        newtop->next = NULL;
        ft_printf("rrb ");
    }
    else
        ft_printf("list B empty\n");
}

void rrr(Node** lista, Node** listb)
{
    if ((*lista != NULL && (*lista)->next != NULL) &&
        (*listb != NULL && (*listb)->next != NULL) )
    {
        reverserotatea(lista);
        reverserotateb(listb);
        ft_printf("(rrr)");
    }
    else
        ft_printf("not enough values to revrotate in list A or B\n");
}

// Function to print the linked list and memory addresses
void printList(Node *node) {
    while (node != NULL) {
        ft_printf("Data: %d, Address: %p\n", node->data, (void *)node);
        node = node->next;
    }
}

int	ft_isnumeric(char *str)
{
	int i = 0;
    if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


void printArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        ft_printf("Value: %d, Position: %d\n", arr[i].value, arr[i].position);
    }
}




int main(int argc, char *argv[]) {
    int i;
    Node* tops[NUM_LISTS] = {NULL};  // Initialize all lists as empty
    int *numbers = malloc((argc - 1) * sizeof(int));
    // Convert each command-line argument to an integer and push it onto the stack
    for (i = 1; i < argc; i++) {
        if(ft_isnumeric(argv[i]) != 1)
        {
            ft_printf("can't parse non numeric data");
            exit (-1);
        }
        int arg = ft_atoi(argv[i]);
       append(&tops[0], arg);
    }

        for (i = 1; i < argc; i++) {
        if(ft_isnumeric(argv[i]) != 1)
        {
            ft_printf("can't parse non numeric data");
            exit (-1);
        }
        numbers[i - 1] = ft_atoi(argv[i]);
    }
    
    
    bubblesort(numbers, argc -1);

    
    Element arr[argc-1];
    // Assuming the array is already sorted and filled with values
    for (int i = 0; i < argc-1; i++) {
        arr[i].position = i;
        arr[i].value = numbers[i];
    }

    printArray(arr, argc-1);

    int median = numbers[(argc-1) / 2];
    int smallest = numbers[0];
    int biggest = numbers[argc -2];
    ft_printf("smallest = %d\n", smallest);
    ft_printf("median = %d\n", median);
    ft_printf("biggest = %d\n", biggest);
    // ft_printf("list a before op \n");
    // printList(tops[0]);
    // Print the stack
    //  halfit(&tops[0], &tops[1], argc);
    // sendit(&tops[0], &tops[1]);
    Chunk myarr[argc];
    sorthalf(&tops[0], &tops[1], arr, myarr);
    
    
    // midpointrecursion(&tops[0], &tops[1], arr, argc);
    // stalinsort(&tops[0], &tops[1], arr, argc);
    // algorithm(&tops[0], &tops[1], arr, argc);
    ft_printf("list a \n");
    printList(tops[0]);
    ft_printf("list b \n");
    printList(tops[1]);
    free(tops[0]);
    free(tops[1]);
    return(0);
}