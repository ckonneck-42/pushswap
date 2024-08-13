/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:08 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/12 13:52:33 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef NUM_LISTS
#  define NUM_LISTS 2
# endif
# include <stdlib.h>
# include "libft/libft.h"
#include <limits.h>

typedef struct Node
{
	int	data;
	struct Node*	next;
} Node;

typedef struct Chunk
{
	int	value;
	int position;
	struct Chunk*	next;
} Chunk;

void cpra (Node **list);
void cprb (Node **list);
void cpsa (Node **list);
void cpsb (Node **list);
void printchunk(Chunk* head);

void rotateb(Node **lista);
void swapb(Node **list);
void rotatea(Node **lista);
void swapa(Node **list);
void pushtob(Node **sourceRef, Node **destRef);
void pushtoa(Node **sourceRef, Node **destRef);
void reverserotatea(Node** lista);
void reverserotateb(Node** listb);
void reverserotatebchunk(Chunk **listb);
void rotatebchunk(Chunk **listb);

void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i);
void threepointalgo(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i);
void appendchunk(Chunk **headRef, int value, int position);
int sorthalf(Node *tops[],Chunk *chunks[], int i);
// void midpointrecursion(Node *tops[], Element arr[], int argc, int i);
void sendit (Node **lista, Node **listb);
// void stalinsort(Node **lista, Node **listb, Element arr[], int argc);
void halfit (Node **lista, Node **listb, int argc);
void firstsort (Node **lista, Node **listb, int median, int argc);
int	 countnodes(Node *head);
void bubblesort(int arr[], int n);
void printList(Node *node);
int  isSorted(Node *head);
int  comparesums(Node *head);
void algorithm (Node **lista, Node **listb, int median, int argc);

#endif