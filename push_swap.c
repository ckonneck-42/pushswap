/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:14:24 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/26 16:38:22 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_Node *Node)
{
	t_Node	*temp;

	temp = Node;
	while (temp != NULL)
	{
		ft_printf("Data: %d", temp->data);
		temp = temp->next;
	}
}

void	printchunk(t_Chunk *head)
{
	t_Chunk	*current;

	current = head;
	ft_printf("PRINTING CHUNK\n");
	if (!head)
		return ;
	while (current != NULL)
	{
		ft_printf("Value: %d\n", current->value);
		current = current->next;
	}
}

void	print_argv(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc + 1)
	{
		ft_printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
}

size_t	count_words(const char *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (counter);
}

int	main(int argc, char *argv[])
{
	int				magicnumber;
	t_Chunk			*chunks[100];
	t_Chunk			*chonks[100];
	t_Datastruct	sdata;
	int				old_argc;

	old_argc = argc;
	magicnumber = 1;
	if (is_empty_or_spaces(argv[1]) == 1)
		exit(0);
	if (argc == 2)
		argv = stringhandling(&argc, argv);
	errorhandling(argv, old_argc);
	sdata = (t_Datastruct){{NULL}, {NULL}, {NULL}, {NULL}, NULL};
	sdata.numbers = appendnumbers(argc, argv, sdata.tops, sdata.topsbg);
	listsorted(&sdata, old_argc, argv, magicnumber);
	if (argc >= 3 && argc <= 6)
		twotofiveargs(&sdata, argc, old_argc, argv);
	initsortapp(&sdata, chunks, chonks, argc);
	magicnumber = backgroundoperations(&sdata, argc, argv);
	sortmidfree(&sdata, chunks, chonks, magicnumber);
	argvfree(argv, magicnumber, old_argc);
}

//freeing chunks, chonks, 
//		chunksbg chonksbg,
//		tops, topsbg,
//		numbers,
//free_all(sdata.chunksbg, sdata.topsbg, sdata.chonksbg);
//magicnumber = 50;