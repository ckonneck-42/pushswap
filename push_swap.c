/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:14:24 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:36:53 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"



// Function to print the linked list and memory addresses
void printList(Node *node) {
    Node *temp = node;
    while (temp != NULL) {
        ft_printf("Data: %d, Address: %p\n", temp->data, (void *)temp);
        temp = temp->next;
    }
}




void printchunk(Chunk* head) {
    ft_printf("PRINTING CHUNK\n");
    if (!head)
        return;
    Chunk* current = head;
    while (current != NULL) {
        ft_printf("Value: %d\n", current->value);
        current = current->next;
    }
}




int main(int argc, char *argv[]) {
    int i;
    int magicnumber;
    Node* tops[NUM_LISTS] = {NULL};  // Initialize all lists as empty
    Node* topsbg[NUM_LISTS] = {NULL};  // Initialize all lists as empty
    Chunk *chunks[200] = {NULL};  // Initialize all lists as empty
    Chunk *chonks[200] = {NULL};
    Chunk *chunksbg[501] = {NULL};  // Initialize all lists as empty
    Chunk *chonksbg[501] = {NULL}; //initialize in a loop with argc
    int *numbers = malloc((argc - 1) * sizeof(int));
    if (numbers == NULL)
        return(-1);
    for (i = 1; i < argc; i++) {
        if(ft_isnumeric(argv[i]) != 1)
        {
            ft_printf("can't parse non numeric data");
            exit (-1);
        }
        int arg = ft_atoi(argv[i]);
        numbers[i - 1] = ft_atoi(argv[i]);
       append(&tops[0], arg);
       append(&topsbg[0], arg);
    }
    bubblesortarr(numbers, argc -1);
    for (int i = 0; i < argc-1; i++) {
        actuallyappendchunk(&chonks[0], numbers[i]);
        actuallyappendchunk(&chonksbg[0], numbers[i]);
    }
    
    magicnumber = backgroundoperations(topsbg, chunksbg, chonksbg, argc, argv, numbers);
    sorthalf(tops, chunks,chonks, magicnumber);
    midpointsort(tops);
    threepointalgo(tops);
    free_all2(chunks, tops, chonks);
    free(numbers);
    return(0);
}
