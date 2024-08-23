/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bgutils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:07:09 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/22 17:28:05 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bgopcalc(t_Chunk *calcs[])
{
	int	i;

	i = 0;
	while (i < 100)
	{
		calcs[i] = malloc(sizeof(t_Chunk));
		if (calcs[i] == NULL)
		{
			free(calcs[i]);
			exit(-1);
		}
		calcs[i]->calcc = 0;
		calcs[i]->chunksize = 0;
		calcs[i]->next = NULL;
		i++;
	}
}

int	bgop3p1(t_Node *topsbg[], int x)
{
	x = pushtobbg(&topsbg[0], &topsbg[1], x);
	x = swapabg(&topsbg[0], x);
	x = rotateabg(&topsbg[0], x);
	x = rotateabg(&topsbg[0], x);
	x = pushtoabg(&topsbg[0], &topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	return (x);
}

int	bgop3p2(t_Node *topsbg[], int x)
{
	x = pushtobbg(&topsbg[0], &topsbg[1], x);
	x = swapabg(&topsbg[0], x);
	x = rotateabg(&topsbg[0], x);
	x = pushtoabg(&topsbg[0], &topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	return (x);
}

int	bgop3p3(t_Node *topsbg[], int x)
{
	x = pushtobbg(&topsbg[0], &topsbg[1], x);
	x = rotateabg(&topsbg[0], x);
	x = rotateabg(&topsbg[0], x);
	x = pushtoabg(&topsbg[1], &topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	return (x);
}

int	bgop3p4(t_Node *topsbg[], int x)
{
	x = pushtobbg(&topsbg[0], &topsbg[1], x);
	x = rotateabg(&topsbg[0], x);
	x = rotateabg(&topsbg[0], x);
	x = pushtoabg(&topsbg[1], &topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	x = reverserotateabg(&topsbg[0], x);
	return (x);
}
