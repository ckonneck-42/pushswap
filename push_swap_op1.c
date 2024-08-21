/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:16:05 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:18:01 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
    Node *newtopofb = *sourceRef;
    if (newtopofb != NULL) {
        // Move the source pointer to the next node
        *sourceRef = newtopofb->next;

        // Push the node onto the destination list
        newtopofb->next = *destRef;
        *destRef = newtopofb;
        ft_printf("pb\n");
    }
    else
        ft_printf("list B is empty\n");
}
