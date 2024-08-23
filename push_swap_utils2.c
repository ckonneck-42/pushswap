/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:19:56 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 07:59:32 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append(t_Node **headRef, int data)
{
	t_Node	*new1t_node;
	t_Node	*last;

	new1t_node = create_t_node(data);
	if (*headRef == NULL)
	{
		*headRef = new1t_node;
		return ;
	}
	last = *headRef;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new1t_node;
}

void	actuallyappendchunk(t_Chunk **headRef, int value)
{
	t_Chunk	*new1t_node;
	t_Chunk	*last;

	new1t_node = create_t_nodechunk(value);
	if (new1t_node == NULL)
		return ;
	if (*headRef == NULL)
	{
		*headRef = new1t_node;
		return ;
	}
	last = *headRef;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new1t_node;
}

int	countt_nodes(t_Node *head)
{
	int		i;
	t_Node	*temp;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	issorted(t_Node *head)
{
	t_Node	*current;

	if (head == NULL || head->next == NULL)
		return (2);
	current = head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_medianchunk(t_Chunk *head)
{
	t_Chunk	*sorted_copy;
	t_Chunk	*slow;
	t_Chunk	*fast;
	int		median;
	t_Chunk	*temp;

	if (head == NULL)
		return (-1);
	sorted_copy = copy_listchunk(head);
	bubblesortchunk(sorted_copy);
	slow = sorted_copy;
	fast = sorted_copy;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	median = slow->value;
	while (sorted_copy != NULL)
	{
		temp = sorted_copy;
		sorted_copy = sorted_copy->next;
		free(temp);
	}
	return (median);
}
