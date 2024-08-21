/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opbg2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:47 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:25:38 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int rotateabg(Node** lista, int x)
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
        x += 1;
    }
    else
        ft_printf("list A empty\n");
    return(x);
}

int rotatebbg(Node** listb, int x)
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
        x += 1;
    }
    else
        ft_printf("list B empty\n");
    return(x);
}


int reverserotateabg(Node** lista, int x)
{
    Node* newtop = *lista;
    if(*lista != NULL ||(*lista)->next != NULL)
    {
        while(newtop->next->next != NULL)
            newtop = newtop->next;
        newtop->next->next = *lista;
        *lista = newtop->next;
        newtop->next = NULL;
        x += 1;
        
    }
    else
        ft_printf("list A empty\n");
    return(x);
}

int reverserotatebbg(Node** listb, int x)
{
    Node* newtop = *listb;
    if(*listb != NULL || (*listb)->next != NULL)
    {
        while(newtop->next->next != NULL)
            newtop = newtop->next;
        newtop->next->next = *listb;
        *listb = newtop->next;
        newtop->next = NULL;
        x += 1;
    }
    else
        ft_printf("list B empty\n");
    return(x);
}


int operationrcbg(Node *topsbg[], int rc, int rrc, int x)
{
if (rc != 0 || rrc != 0)
	{
		while (rc != 0 && rrc != 0)
		{
			if (rc > rrc) 
			{
				x = reverserotatebbg(&topsbg[1], x);
				rrc--;
			} 
			else 
			{
				x = rotatebbg(&topsbg[1], x);
				rc--;
			}
		}
	}
	else
		x = pushtoabg(&topsbg[1], &topsbg[0], x);
	return (x);
}