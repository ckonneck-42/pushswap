/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:08 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/07 15:40:08 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef NUM_LISTS
#  define NUM_LISTS 2
# endif
# include <stdlib.h>
# include "libft/libft.h"

typedef struct Node
{
	int	data;
	struct Node*	next;
} Node;

typedef struct
{
    int value;
    int position;
} Element;

typedef struct {
	int *array;
    int value;
    int position;
} Chunk;

void cpra (Node **list);
void cprb (Node **list);
void cpsa (Node **list);
void cpsb (Node **list);


void rotateb(Node **lista);
void swapb(Node **list);
void rotatea(Node **lista);
void swapa(Node **list);
void pushtob(Node **sourceRef, Node **destRef);
void pushtoa(Node **sourceRef, Node **destRef);
void reverserotatea(Node** lista);
void reverserotateb(Node** listb);

void sorthalf(Node **lista, Node **listb, Element arr[], Chunk array[]);
void midpointrecursion(Node **lista, Node **listb, Element arr[], int argc);
void sendit (Node **lista, Node **listb);
void stalinsort(Node **lista, Node **listb, Element arr[], int argc);
void halfit (Node **lista, Node **listb, int argc);
void firstsort (Node **lista, Node **listb, int median, int argc);
int	 countnodes(Node *head);
void bubblesort(int arr[], int n);
void printList(Node *node);
int  isSorted(Node *head);
int  comparesums(Node *head);
void algorithm (Node **lista, Node **listb, int median, int argc);

#endif