/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:12:34 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/22 17:37:33 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesortarr(int arr[], int n)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (n - 1))
	{
		if (arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	bubble_sortlist(t_Node *head)
{
	t_Node	*current;
	t_Node	*last;
	int		temp;

	if (head == NULL)
		return ;
	last = NULL;
	while (head != last)
	{
		current = head;
		while (current->next != last)
		{
			if (current->data > current->next->data)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				current = head;
			}
			else
				current = current->next;
		}
		last = current;
	}
}

void	bubblesortchunk(t_Chunk *head)
{
	t_Chunk	*current;
	t_Chunk	*last;
	int		temp;

	if (head == NULL)
		return ;
	last = NULL;
	while (head != last)
	{
		current = head;
		while (current->next != last)
		{
			if (current->value > current->next->value)
			{
				temp = current->value;
				current->value = current->next->value;
				current->next->value = temp;
				current = head;
			}
			else
				current = current->next;
		}
		last = current;
	}
}

int	bubblesortchunkbg(t_Chunk *arr[], int n)
{
	int		i;
	t_Chunk	*temp;

	i = 0;
	temp = 0;
	while (i < (n - 1))
	{
		if (arr[i]->chunksize > arr[i + 1]->chunksize)
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (arr[1]->calcc);
}
