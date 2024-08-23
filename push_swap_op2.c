/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:18:25 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/22 17:39:14 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushtoa(t_Node **sourceRef, t_Node **destRef)
{
	t_Node	*newtopofa;

	newtopofa = *sourceRef;
	if (newtopofa != NULL)
	{
		*sourceRef = newtopofa->next;
		newtopofa->next = *destRef;
		*destRef = newtopofa;
		ft_printf("pa\n");
	}
	else
		ft_printf("list A is empty\n");
}

void	rotatea(t_Node **lista)
{
	t_Node	*newbottom;
	t_Node	*second;
	t_Node	*last;

	newbottom = *lista;
	second = newbottom->next;
	if (newbottom != NULL)
	{
		*lista = second;
		newbottom->next = NULL;
		last = *lista;
		while (last->next != NULL)
			last = last->next;
		last->next = newbottom;
		ft_printf("ra\n");
	}
	else
		ft_printf("list A empty\n");
}

void	rotateb(t_Node **listb)
{
	t_Node	*newbottom;
	t_Node	*second;
	t_Node	*last;

	newbottom = *listb;
	second = newbottom->next;
	if (newbottom != NULL)
	{
		*listb = second;
		newbottom->next = NULL;
		last = *listb;
		while (last->next != NULL)
			last = last->next;
		last->next = newbottom;
		ft_printf("rb\n");
	}
	else
		ft_printf("list B empty\n");
}

void	rotatebchunk(t_Chunk **listb)
{
	t_Chunk	*newbottom;
	t_Chunk	*second;
	t_Chunk	*last;

	newbottom = *listb;
	second = newbottom->next;
	if (newbottom != NULL)
	{
		*listb = second;
		newbottom->next = NULL;
		last = *listb;
		while (last->next != NULL)
			last = last->next;
		last->next = newbottom;
	}
	else
		ft_printf("list B empty\n");
}

void	reverserotatebchunk(t_Chunk **listb)
{
	t_Chunk	*newtop;

	newtop = *listb;
	if (*listb != NULL || (*listb)->next != NULL)
	{
		while (newtop->next->next != NULL)
			newtop = newtop->next;
		newtop->next->next = *listb;
		*listb = newtop->next;
		newtop->next = NULL;
	}
	else
		ft_printf("list B empty\n");
}
