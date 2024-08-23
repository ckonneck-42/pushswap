/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:19:07 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/22 17:39:24 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_Node **lista, t_Node **listb)
{
	if ((*lista != NULL && (*lista)->next != NULL) && (*listb != NULL
			&& (*listb)->next != NULL))
	{
		rotatea(lista);
		rotateb(listb);
		ft_printf("(rr)");
	}
	else
		ft_printf("not enough values to rotate in list A or B\n");
}

void	reverserotatea(t_Node **lista)
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
		ft_printf("rra\n");
	}
	else
		ft_printf("list A empty\n");
}

void	reverserotateb(t_Node **listb)
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
		ft_printf("rrb\n");
	}
	else
		ft_printf("list B empty\n");
}

void	rrr(t_Node **lista, t_Node **listb)
{
	if ((*lista != NULL && (*lista)->next != NULL) && (*listb != NULL
			&& (*listb)->next != NULL))
	{
		reverserotatea(lista);
		reverserotateb(listb);
		ft_printf("(rrr)");
	}
	else
		ft_printf("not enough values to revrotate in list A or B\n");
}
