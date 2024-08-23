/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:16:05 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/22 17:38:08 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapb(t_Node **list)
{
	t_Node	*first;
	t_Node	*second;

	if (*list != NULL && (*list)->next != NULL)
	{
		first = *list;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*list = second;
		ft_printf("sb\n");
	}
	else
		ft_printf("not enough values to swap in list B\n");
}

void	swapa(t_Node **list)
{
	t_Node	*first;
	t_Node	*second;

	if (*list != NULL && (*list)->next != NULL)
	{
		first = *list;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*list = second;
		ft_printf("sa\n");
	}
	else
		ft_printf("not enough values to swap in list A\n");
}

void	ss(t_Node **lista, t_Node **listb)
{
	if ((*lista != NULL && (*lista)->next != NULL) && (*listb != NULL
			&& (*listb)->next != NULL))
	{
		swapa(lista);
		swapb(listb);
		ft_printf("(ss)");
	}
	else
		ft_printf("not enough values to swap in list A or B\n");
}

void	pushtob(t_Node **sourceRef, t_Node **destRef)
{
	t_Node	*newtopofb;

	newtopofb = *sourceRef;
	if (newtopofb != NULL)
	{
		*sourceRef = newtopofb->next;
		newtopofb->next = *destRef;
		*destRef = newtopofb;
		ft_printf("pb\n");
	}
	else
		ft_printf("list B is empty\n");
}
