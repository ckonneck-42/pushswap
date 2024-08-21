/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:19:56 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:21:02 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void append(Node **headRef, int data) {
    // 1. Allocate new node
    Node* new1Node = create_node(data);

    // 4. If the Linked List is empty, then make the new node as head
    if (*headRef == NULL) {
        *headRef = new1Node;
        return;
    }

    // 5. Else traverse till the last node
    Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    // 6. Change the next of last node
    last->next = new1Node;
}


void actuallyappendchunk(Chunk **headRef, int value) {
    // 1. Allocate new node
    Chunk* new1Node = create_nodechunk(value);
    if (new1Node == NULL)
        return;
    // 4. If the Linked List is empty, then make the new node as head
    if (*headRef == NULL) {
        *headRef = new1Node;
        return;
    }

    // 5. Else traverse till the last node
    Chunk* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }

    // 6. Change the next of last node
    last->next = new1Node;
}


int countnodes(Node *head)
{
	int i = 0;
	Node *temp = head;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int issorted(Node *head)
{
	if (head == NULL || head->next == NULL) {
		return (2);
	}

	Node *current = head;
	while (current->next != NULL) {
		if (current->data > current->next->data) {
			return (0); 
		}
		current = current->next;
	}

	return (1); 
}


int find_medianchunk(Chunk *head) {
	if (head == NULL) return -1; // Handle empty list

	// Copy and sort the list
	Chunk *sorted_copy = copy_listchunk(head);
	bubblesortchunk(sorted_copy);

	// Traverse to find the median
	Chunk *slow = sorted_copy;
	Chunk *fast = sorted_copy;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	int median = slow->value;

	// Free the copied list
	while (sorted_copy != NULL) {
		Chunk *temp = sorted_copy;
		sorted_copy = sorted_copy->next;
		free(temp);
	}

	return median;
}
