/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:20:47 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 07:52:55 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	appendchunks(t_Chunk *chonks[], t_Chunk *chonksbg[], int *numbers,
		int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		actuallyappendchunk(&chonks[0], numbers[i]);
		actuallyappendchunk(&chonksbg[0], numbers[i]);
		i++;
	}
}

void	op3p1(t_Node *tops[])
{
	pushtob(&tops[0], &tops[1]);
	swapa(&tops[0]);
	rotatea(&tops[0]);
	rotatea(&tops[0]);
	pushtoa(&tops[0], &tops[0]);
	reverserotatea(&tops[0]);
	reverserotatea(&tops[0]);
}

void	op3p2(t_Node *tops[])
{
	pushtob(&tops[0], &tops[1]);
	swapa(&tops[0]);
	rotatea(&tops[0]);
	pushtoa(&tops[0], &tops[0]);
	reverserotatea(&tops[0]);
}

void	op3p3(t_Node *tops[])
{
	pushtob(&tops[0], &tops[1]);
	rotatea(&tops[0]);
	rotatea(&tops[0]);
	pushtoa(&tops[1], &tops[0]);
	reverserotatea(&tops[0]);
	reverserotatea(&tops[0]);
}

void	op3p4(t_Node *tops[])
{
	pushtob(&tops[0], &tops[1]);
	swapa(&tops[0]);
	pushtoa(&tops[1], &tops[0]);
}
