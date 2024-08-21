/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:22:13 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:37:08 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


Node* create_node(int data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
		return NULL;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

int find_highest_integer(Chunk *head) {
	int highest = INT_MIN;
	Chunk *current = head;

	while (current != NULL) {
		if (current->value > highest) {
			highest = current->value;
		}
		current = current->next;
	}
	return highest;
}

void operationrc(Node *tops[], int rc, int rrc)
{
	if (rc != 0 || rrc != 0)
	{
		while (rc != 0 && rrc != 0)
		{
			if (rc > rrc) 
			{
				reverserotateb(&tops[1]);
				rrc--;
			} 
			else 
			{
				rotateb(&tops[1]);
				rc--;
			}
		}
	}
	else
		pushtoa(&tops[1], &tops[0]);
}

int	ft_isnumeric(char *str)
{
	int i = 0;
    if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}