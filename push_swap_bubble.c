/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:12:34 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:53:00 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesortarr(int arr[], int n) {
	int	i = 0;
	int	temp;

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


void bubble_sortlist(Node* head) 
{
    if (head == NULL)
        return;

    Node* current;
    Node* last = NULL;

    while (head != last) {
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                current = head; // Reset current to head
            } else {
                current = current->next;
            }
        }
        last = current;
    }
}

void bubblesortchunk(Chunk* head) 
{
    if (head == NULL)
        return;

    Chunk* current;
    Chunk* last = NULL;

    while (head != last) {
        current = head;

        while (current->next != last) {
            if (current->value > current->next->value) {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                current = head; // Reset current to head
            } else {
                current = current->next;
            }
        }
        last = current;
    }
}


int bubblesortchunkbg(Chunk *arr[], int n) 
{
	int i;
	Chunk *temp;

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
