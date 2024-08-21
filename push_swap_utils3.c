/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:21:28 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:34:44 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Chunk* create_nodechunk(int value) {
	Chunk* new_node = (Chunk*)malloc(sizeof(Chunk));
	if (new_node == NULL)
		return NULL;
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

Node* copy_list(Node* head) {
	if (head == NULL) return NULL;

	Node* new_head = create_node(head->data);
	Node* current = new_head;
	Node* original = head->next;

	while (original != NULL) {
		current->next = create_node(original->data);
		current = current->next;
		original = original->next;
	}
	return new_head;
}

Chunk* copy_listchunk(Chunk* head) {
	if (head == NULL) return NULL;

	Chunk* new_head = create_nodechunk(head->value);
	Chunk* current = new_head;
	Chunk* original = head->next;

	while (original != NULL) {
		current->next = create_nodechunk(original->value);
		current = current->next;
		original = original->next;
	}
	return new_head;
}

Chunk* copy_current_chunk(Chunk* node) {
	if (node == NULL) return NULL;

	Chunk* new_node = create_nodechunk(node->value);
	return new_node;
}

Chunk* copyNodeToChunk(Node* head) {
	if (head == NULL)
		return NULL;

	Chunk* chunkHead = create_nodechunk(head->data);
	if (chunkHead == NULL)
        return NULL;
	Chunk* chunkCurrent = chunkHead;
	Node* nodeCurrent = head->next;

	    while (nodeCurrent != NULL) {
        Chunk* newChunk = create_nodechunk(nodeCurrent->data);
        if (newChunk == NULL) {
            while (chunkHead != NULL) {
                Chunk* temp = chunkHead;
                chunkHead = chunkHead->next;
                free(temp);
            }
            return NULL;
        }
        chunkCurrent->next = newChunk;
        chunkCurrent = newChunk;
        nodeCurrent = nodeCurrent->next;
    }
	return (chunkHead);
}
