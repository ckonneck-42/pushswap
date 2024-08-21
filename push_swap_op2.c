/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:18:25 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:18:37 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void rotatebchunk(Chunk **listb)
{
    Chunk *newbottom = *listb;
    Chunk *second = newbottom->next;
   
    if(newbottom != NULL)
    {
        *listb = second;
        newbottom->next = NULL;
        Chunk *last = *listb;
        while(last->next != NULL)
            last = last->next;
        last->next = newbottom;
        // ft_printf("rb\n");
    }
    else
        ft_printf("list B empty\n");
}

void reverserotatebchunk(Chunk **listb)
{
    Chunk *newtop = *listb;
    if(*listb != NULL || (*listb)->next != NULL)
    {
        while(newtop->next->next != NULL)
            newtop = newtop->next;
        newtop->next->next = *listb;
        *listb = newtop->next;
        newtop->next = NULL;
        // ft_printf("rrb ");
    }
    else
        ft_printf("list B empty\n");
}
