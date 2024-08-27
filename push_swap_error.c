/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:52:34 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 15:13:19 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	listsorted(t_Datastruct *sdata, int old_argc, char **argv,
		int magicnumber)
{
	if (issortedtwo(sdata->tops[0]) == 1)
	{
		free_listt_node(sdata->tops[0]);
		free_listt_node(sdata->topsbg[0]);
		free(sdata->numbers);
		if (old_argc == 2)
		{
			magicnumber = 1;
			while (argv[magicnumber])
			{
				free(argv[magicnumber]);
				magicnumber++;
			}
			free(argv);
		}
		exit(0);
	}
}

int	issortedtwo(t_Node *head)
{
	t_Node	*current;

	if (head == NULL)
		return (2);
	current = head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	errorhandling(char **argv, int old_argc)
{
	int	i;

	if (good_input(argv) == 0)
	{
		ft_printf("Error\n");
		if (old_argc == 2)
		{
			i = 1;
			while (argv[i])
			{
				free(argv[i]);
				i++;
			}
			free(argv);
		}
		exit(0);
	}
}
