/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bgutils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:58:47 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 08:44:11 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	midpointopbg(t_Chunk *listbcopy1[], t_Chunk *listbcopy2[], int *rc,
		int *rrc)
{
	int		highest;
	int		tempdata;
	t_Chunk	*head;

	highest = find_highest_integer(listbcopy1[0]);
	head = listbcopy1[0];
	tempdata = head->value;
	while (tempdata != highest)
	{
		rotatebchunk(&listbcopy1[0]);
		(*rc)++;
		tempdata = listbcopy1[0]->value;
	}
	tempdata = head->value;
	while (tempdata != highest)
	{
		reverserotatebchunk(&listbcopy2[0]);
		(*rrc)++;
		tempdata = listbcopy2[0]->value;
	}
}

int	costcalcopbg(t_Ccop *op, int *rc, int *rrc)
{
	int	tempdata;

	tempdata = op->head->data;
	if (tempdata <= op->middle)
	{
		free_listchunk(op->listbcopy3);
		free_listchunk(op->listbcopy4);
		return (2);
	}
	while (tempdata > op->middle)
	{
		reverserotatebchunk(&op->listbcopy3);
		(*rrc)++;
		tempdata = op->listbcopy3->value;
	}
	tempdata = op->head->data;
	while (tempdata > op->middle)
	{
		rotatebchunk(&op->listbcopy4);
		(*rc)++;
		tempdata = op->listbcopy4->value;
	}
	return (0);
}

void	update_calcs(t_Chunk *calcs[], int *calcc, int *x)
{
	calcs[*calcc]->calcc = *calcc;
	calcs[*calcc]->chunksize = (*x);
	(*calcc)++;
	(*x) = 0;
}

void	reformos(int argc, char **argv, t_Node *topsbg[])
{
	int	i;
	int	arg;

	i = 1;
	while (i < argc)
	{
		if (ft_isnumeric(argv[i]) != 1)
		{
			ft_printf("can't parse non numeric data");
			exit(-1);
		}
		arg = ft_atoi(argv[i]);
		append(&topsbg[0], arg);
		i++;
	}
}

int	flagop(t_Datastruct *sdata, int i, int x, int flag)
{
	if (flag == 2)
	{
		freethespecificdatabg(sdata->chunksbg, i, sdata->topsbg);
		x = pushtobbg(&sdata->topsbg[0], &sdata->topsbg[1], x);
	}
	else if (flag == 1)
		x = rotateabg(&sdata->topsbg[0], x);
	else if (flag == 0)
		x = reverserotateabg(&sdata->topsbg[0], x);
	return (x);
}
