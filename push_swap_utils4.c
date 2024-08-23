/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:22:13 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 07:59:47 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*create_t_node(int data)
{
	t_Node	*new_t_node;

	new_t_node = (t_Node *)malloc(sizeof(t_Node));
	if (new_t_node == NULL)
		return (NULL);
	new_t_node->data = data;
	new_t_node->next = NULL;
	return (new_t_node);
}

int	find_highest_integer(t_Chunk *head)
{
	int		highest;
	t_Chunk	*current;

	highest = INT_MIN;
	current = head;
	while (current != NULL)
	{
		if (current->value > highest)
		{
			highest = current->value;
		}
		current = current->next;
	}
	return (highest);
}

void	operationrc(t_Node *tops[], int rc, int rrc)
{
	if (rc != 0 || rrc != 0)
	{
		while (rc != 0 && rrc != 0)
		{
			if (rc > rrc)
			{
				reverserotateb(&tops[1]);
				rrc--;
			}
			else
			{
				rotateb(&tops[1]);
				rc--;
			}
		}
	}
	else
		pushtoa(&tops[1], &tops[0]);
}

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*appendnumbers(int argc, char **argv, t_Node *tops[], t_Node *topsbg[])
{
	int	*numbers;
	int	i;
	int	arg;

	numbers = NULL;
	numbers = malloc((argc - 1) * sizeof(int));
	if (numbers == NULL)
		exit(-1);
	i = 1;
	while (i < argc)
	{
		if (ft_isnumeric(argv[i]) != 1)
		{
			ft_printf("can't parse non numeric data");
			exit(-1);
		}
		arg = ft_atoi(argv[i]);
		numbers[i - 1] = ft_atoi(argv[i]);
		append(&tops[0], arg);
		append(&topsbg[0], arg);
		i++;
	}
	return (numbers);
}
