/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:08 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/21 14:34:27 by ckonneck         ###   ########.fr       */
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
	int calcc;
	int chunksize;
	struct Chunk*	next;
} Chunk;

typedef struct calcs
{

} calcs;



void printchunk(Chunk* head);

int rotatebbg(Node **lista, int x);
int swapbbg(Node **list, int x);
int rotateabg(Node **lista, int x);
int swapabg(Node **list, int x);
int pushtobbg(Node **sourceRef, Node **destRef, int x);
int pushtoabg(Node **sourceRef, Node **destRef, int x);
int reverserotateabg(Node** lista, int x);
int reverserotatebbg(Node** listb, int x);
int costcalcbg(Node *topsbg[], int middle);
void sortintochunksbg(Chunk *chunksbg[], Chunk *chonksbg[], int i, int calcc);
void freethespecificdatabg(Chunk *chunksbg[], int i, Node *topsbg[]);
int sorthalfbg(Node *topsbg[],Chunk *chunksbg[], Chunk *chonksbg[], int x, int calcc);
int threepointalgobg(Node *topsbg[], int x);
int operationrcbg(Node *topsbg[], int rc, int rrc, int x);
int midpointsortbg(Node *topsbg[], int x);
int backgroundoperations(Node *topsbg[], Chunk *chunksbg[], Chunk *chonksbg[], int argc, char **argv, int *numbers);
void reformbg(int argc, char **argv, Node *topsbg[], Chunk *chunksbg[], Chunk *chonksbg[], int *numbers);
int	ft_isnumeric(char *str);
void append(Node **headRef, int data);
int bubblesortchunkbg(Chunk *arr[], int n);
void bubblesortchunk(Chunk* head);

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


void operationrc(Node *tops[], int rc, int rrc);
void freethespecificdata(Chunk *chunks[], int i, Node *tops[]);
int find_medianchunk(Chunk *head);
void freechunk(Chunk **head);
Chunk* copy_current_chunk(Chunk* node);
Chunk* copyNodeToChunk(Node* head);
Node* copy_list(Node* head);
Chunk* copy_listchunk(Chunk* head);
Chunk* create_nodechunk(int value);
Node* create_node(int data);
int find_highest_integer(Chunk *head);
void free_listchunk(Chunk *head);
void free_listnode(Node *head);
void free_all(Chunk *chunksbg[], Node *topsbg[], Chunk *chonksbg[]);
void free_all2(Chunk *chunks[], Node *tops[], Chunk *chonks[]);
void free_allbg(Chunk *chunksbg[], Node *topsbg[], Chunk *chonksbg[], Chunk *calcs[]);



void midpointsort(Node *tops[]);
void threepointalgo(Node *tops[]);
void actuallyappendchunk(Chunk **headRef, int value);
int sorthalf(Node *tops[],Chunk *chunks[], Chunk *chonks[], int magicnumber);
int	 countnodes(Node *head);
void bubblesortarr(int arr[], int n);
void printList(Node *node);
int  issorted(Node *head);



#endif