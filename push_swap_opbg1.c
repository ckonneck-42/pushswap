/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opbg1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:01 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:24:20 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swapbbg(Node** list, int x)
{
    if (*list != NULL && (*list)->next != NULL)
    {
        Node* first = *list;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        *list = second;
        x += 1;
    }
    else
        ft_printf("not enough values to swap in list B\n");
    return(x);
}

int swapabg(Node **list, int x)
{
    if (*list != NULL && (*list)->next != NULL)
    {
        Node* first = *list;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        *list = second;
        x += 1;
       
    }
    else
        ft_printf("not enough values to swap in list A\n");
    return(x);
}

int ssbg(Node **lista, Node **listb, int x)
{
    if ((*lista != NULL && (*lista)->next != NULL) &&
    (*listb != NULL && (*listb)->next != NULL) )
    {
        swapabg(lista, x);
        swapbbg(listb, x);
        x += 1;
    }
    else    
        ft_printf("not enough values to swap in list A or B\n");
    return(x);
}

int pushtobbg(Node **sourceRef, Node **destRef, int x) {
    // Get the first node from the source list
    Node *newtopofb = *sourceRef;
    if (newtopofb != NULL) {
        // Move the source pointer to the next node
        *sourceRef = newtopofb->next;

        // Push the node onto the destination list
        newtopofb->next = *destRef;
        *destRef = newtopofb;
        x += 1;
    }
    else
        ft_printf("list B is empty\n");
    return(x);
}

int pushtoabg(Node **sourceRef, Node **destRef, int x) {
    // Get the first node from the source list
    Node* newtopofa = *sourceRef;
    if (newtopofa != NULL) {
        // Move the source pointer to the next node
        *sourceRef = newtopofa->next;

        // Push the node onto the destination list
        newtopofa->next = *destRef;
        *destRef = newtopofa;
        x += 1;
    }
    else
        ft_printf("list A is empty\n");
    return(x);
}

