/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opbg2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:24:47 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:03:11 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotateabg(t_Node **lista, int x)
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
		x += 1;
	}
	else
		ft_printf("list A empty\n");
	return (x);
}

int	rotatebbg(t_Node **listb, int x)
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
		x += 1;
	}
	else
		ft_printf("list B empty\n");
	return (x);
}

int	reverserotateabg(t_Node **lista, int x)
{
	t_Node	*newtop;

	newtop = *lista;
	if (*lista != NULL || (*lista)->next != NULL)
	{
		while (newtop->next->next != NULL)
			newtop = newtop->next;
		newtop->next->next = *lista;
		*lista = newtop->next;
		newtop->next = NULL;
		x += 1;
	}
	else
		ft_printf("list A empty\n");
	return (x);
}

int	reverserotatebbg(t_Node **listb, int x)
{
	t_Node	*newtop;

	newtop = *listb;
	if (*listb != NULL || (*listb)->next != NULL)
	{
		while (newtop->next->next != NULL)
			newtop = newtop->next;
		newtop->next->next = *listb;
		*listb = newtop->next;
		newtop->next = NULL;
		x += 1;
	}
	else
		ft_printf("list B empty\n");
	return (x);
}

int	operationrcbg(t_Node *topsbg[], int rc, int rrc, int x)
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
