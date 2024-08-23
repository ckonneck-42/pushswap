/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:21:28 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:49:58 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Chunk	*create_t_nodechunk(int value)
{
	t_Chunk	*new_t_node;

	new_t_node = (t_Chunk *)malloc(sizeof(t_Chunk));
	if (new_t_node == NULL)
		return (NULL);
	new_t_node->value = value;
	new_t_node->next = NULL;
	return (new_t_node);
}

t_Node	*copy_list(t_Node *head)
{
	t_Node	*new_head;
	t_Node	*current;
	t_Node	*original;

	if (head == NULL)
		return (NULL);
	new_head = create_t_node(head->data);
	current = new_head;
	original = head->next;
	while (original != NULL)
	{
		current->next = create_t_node(original->data);
		current = current->next;
		original = original->next;
	}
	return (new_head);
}

t_Chunk	*copy_listchunk(t_Chunk *head)
{
	t_Chunk	*new_head;
	t_Chunk	*current;
	t_Chunk	*original;

	if (head == NULL)
		return (NULL);
	new_head = create_t_nodechunk(head->value);
	current = new_head;
	original = head->next;
	while (original != NULL)
	{
		current->next = create_t_nodechunk(original->value);
		current = current->next;
		original = original->next;
	}
	return (new_head);
}

t_Chunk	*copy_current_chunk(t_Chunk *t_node)
{
	t_Chunk	*new_t_node;

	if (t_node == NULL)
		return (NULL);
	new_t_node = create_t_nodechunk(t_node->value);
	return (new_t_node);
}

t_Chunk	*copyt_nodetochunk(t_Node *head)
{
	t_Chunk	*chunkhead;
	t_Chunk	*chunkcurrent;
	t_Node	*t_nodecurrent;

	if (head == NULL)
		return (NULL);
	chunkhead = create_t_nodechunk(head->data);
	if (chunkhead == NULL)
		return (NULL);
	chunkcurrent = chunkhead;
	t_nodecurrent = head->next;
	process_nodes(t_nodecurrent, chunkcurrent);
	return (chunkhead);
}
