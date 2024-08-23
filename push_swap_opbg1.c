/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opbg1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:01 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:02:59 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swapbbg(t_Node **list, int x)
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
		x += 1;
	}
	else
		ft_printf("not enough values to swap in list B\n");
	return (x);
}

int	swapabg(t_Node **list, int x)
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
		x += 1;
	}
	else
		ft_printf("not enough values to swap in list A\n");
	return (x);
}

int	ssbg(t_Node **lista, t_Node **listb, int x)
{
	if ((*lista != NULL && (*lista)->next != NULL) && (*listb != NULL
			&& (*listb)->next != NULL))
	{
		swapabg(lista, x);
		swapbbg(listb, x);
		x += 1;
	}
	else
		ft_printf("not enough values to swap in list A or B\n");
	return (x);
}

int	pushtobbg(t_Node **sourceRef, t_Node **destRef, int x)
{
	t_Node	*newtopofb;

	newtopofb = *sourceRef;
	if (newtopofb != NULL)
	{
		*sourceRef = newtopofb->next;
		newtopofb->next = *destRef;
		*destRef = newtopofb;
		x += 1;
	}
	else
		ft_printf("list B is empty\n");
	return (x);
}

int	pushtoabg(t_Node **sourceRef, t_Node **destRef, int x)
{
	t_Node	*newtopofa;

	newtopofa = *sourceRef;
	if (newtopofa != NULL)
	{
		*sourceRef = newtopofa->next;
		newtopofa->next = *destRef;
		*destRef = newtopofa;
		x += 1;
	}
	else
		ft_printf("list A is empty\n");
	return (x);
}
