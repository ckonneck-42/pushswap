/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:08 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/15 17:57:18 by ckonneck         ###   ########.fr       */
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

void midpointsort(Node *tops[]);
void threepointalgo(Node *tops[]);
void appendchunk(Chunk **headRef, int value);
void actuallyappendchunk(Chunk **headRef, int value);
int sorthalf(Node *tops[],Chunk *chunks[], Chunk *chonks[], int i);
int	 countnodes(Node *head);
void bubblesort(int arr[], int n);
void printList(Node *node);
int  isSorted(Node *head);
int  comparesums(Node *head);


#endif