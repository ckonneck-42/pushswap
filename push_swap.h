/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:44:08 by ckonneck          #+#    #+#             */
/*   Updated: 2024/07/25 13:35:06 by ckonneck         ###   ########.fr       */
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

#endif