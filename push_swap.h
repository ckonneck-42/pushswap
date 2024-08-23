/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:08 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 16:02:16 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef NUM_LISTS
#  define NUM_LISTS 2
# endif
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct t_Node
{
	int				data;
	struct t_Node	*next;
}					t_Node;

typedef struct t_Chunk
{
	int				value;
	int				calcc;
	int				chunksize;
	struct t_Chunk	*next;
}					t_Chunk;

typedef struct t_Datastruct
{
	t_Node			*tops[NUM_LISTS];
	t_Node			*topsbg[NUM_LISTS];
	t_Chunk			*chunksbg[501];
	t_Chunk			*chonksbg[501];
	int				*numbers;
}					t_Datastruct;

typedef struct t_Ccop
{
	t_Node			*head;
	int				middle;
	t_Chunk			*listbcopy3;
	t_Chunk			*listbcopy4;
}					t_Ccop;

void				print_argv(int argc, char *argv[]);
size_t				count_words(const char *s, char c);
char				**stringhandling(int *argc, char **argv);
void				initchunks(t_Chunk *chunks[], t_Chunk *chonks[]);
void				argc3op(t_Datastruct *sdata, int old_argc, char **argv);
void				argc3(t_Node *tops[]);
t_Chunk				*process_nodes(t_Node *t_nodecurrent,
						t_Chunk *chunkcurrent);
int					flagop(t_Datastruct *sdata, int i, int x, int flag);
void				reformos(int argc, char **argv, t_Node *topsbg[]);
void				update_calcs(t_Chunk *calcs[], int *calcc, int *x);
void				op3p1(t_Node *tops[]);
void				op3p2(t_Node *tops[]);
void				op3p3(t_Node *tops[]);
void				op3p4(t_Node *tops[]);
void				sortintochunks(t_Chunk *chunks[], t_Chunk *chonks[], int i,
						int magicnumber);
int					minifunc(t_Chunk *chunks[], t_Chunk *chonks[],
						int magicnumber, int i);
void				bgopcalc(t_Chunk *calcs[]);
int					bgop3p1(t_Node *topsbg[], int x);
int					bgop3p2(t_Node *topsbg[], int x);
int					bgop3p3(t_Node *topsbg[], int x);
int					bgop3p4(t_Node *topsbg[], int x);
void				midpointopbg(t_Chunk *listbcopy1[], t_Chunk *listbcopy2[],
						int *rc, int *rrc);
int					costcalcopbg(t_Ccop *op, int *rc, int *rrc);
void				appendchunks(t_Chunk *chonks[], t_Chunk *chonksbg[],
						int *numbers, int argc);
int					*appendnumbers(int argc, char **argv, t_Node *tops[],
						t_Node *topsbg[]);
void				printchunk(t_Chunk *head);
int					rotatebbg(t_Node **lista, int x);
int					swapbbg(t_Node **list, int x);
int					rotateabg(t_Node **lista, int x);
int					swapabg(t_Node **list, int x);
int					pushtobbg(t_Node **sourceRef, t_Node **destRef, int x);
int					pushtoabg(t_Node **sourceRef, t_Node **destRef, int x);
int					reverserotateabg(t_Node **lista, int x);
int					reverserotatebbg(t_Node **listb, int x);
int					costcalcbg(t_Node *topsbg[], int middle);
void				sortintochunksbg(t_Chunk *chunksbg[], t_Chunk *chonksbg[],
						int i, int calcc);
void				freethespecificdatabg(t_Chunk *chunksbg[], int i,
						t_Node *topsbg[]);
int					sorthalfbg(t_Datastruct *sdata, int x, int calcc);
int					threepointalgobg(t_Node *topsbg[], int x);
int					operationrcbg(t_Node *topsbg[], int rc, int rrc, int x);
int					midpointsortbg(t_Node *topsbg[], int x);
int					backgroundoperations(t_Datastruct *sdata, int argc,
						char **argv);
void				reformbg(int argc, char **argv, t_Datastruct *sdata);
int					ft_isnumeric(char *str);
void				append(t_Node **headRef, int data);
int					bubblesortchunkbg(t_Chunk *arr[], int n);
void				bubblesortchunk(t_Chunk *head);

void				rotateb(t_Node **lista);
void				swapb(t_Node **list);
void				rotatea(t_Node **lista);
void				swapa(t_Node **list);
void				pushtob(t_Node **sourceRef, t_Node **destRef);
void				pushtoa(t_Node **sourceRef, t_Node **destRef);
void				reverserotatea(t_Node **lista);
void				reverserotateb(t_Node **listb);
void				reverserotatebchunk(t_Chunk **listb);
void				rotatebchunk(t_Chunk **listb);

void				operationrc(t_Node *tops[], int rc, int rrc);
void				freethespecificdata(t_Chunk *chunks[], int i,
						t_Node *tops[]);
int					find_medianchunk(t_Chunk *head);
void				freechunk(t_Chunk **head);
t_Chunk				*copy_current_chunk(t_Chunk *t_Node);
t_Chunk				*copyt_nodetochunk(t_Node *head);
t_Node				*copy_list(t_Node *head);
t_Chunk				*copy_listchunk(t_Chunk *head);
t_Chunk				*create_t_nodechunk(int value);
t_Node				*create_t_node(int data);
int					find_highest_integer(t_Chunk *head);
void				free_listchunk(t_Chunk *head);
void				free_listt_node(t_Node *head);
void				free_all(t_Chunk *chunksbg[], t_Node *topsbg[],
						t_Chunk *chonksbg[]);
void				free_all2(t_Chunk *chunks[], t_Node *tops[],
						t_Chunk *chonks[]);
void				free_allbg(t_Chunk *chunksbg[], t_Node *topsbg[],
						t_Chunk *chonksbg[], t_Chunk *calcs[]);

void				midpointsort(t_Node *tops[]);
void				threepointalgo(t_Node *tops[]);
void				actuallyappendchunk(t_Chunk **headRef, int value);
int					sorthalf(t_Node *tops[], t_Chunk *chunks[],
						t_Chunk *chonks[], int magicnumber);
int					countt_nodes(t_Node *head);
void				bubblesortarr(int arr[], int n);
void				printlist(t_Node *t_Node);
int					issorted(t_Node *head);

#endif