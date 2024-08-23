/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:14:24 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/23 16:14:23 by ckonneck         ###   ########.fr       */
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

void print_argv(int argc, char *argv[])
{
    for (int i = 0; i < argc +1; i++)
    {
        ft_printf("argv[%d]: %s\n", i, argv[i]);
    }
}

size_t count_words(const char *s, char c)
{
    size_t counter = 0;
    size_t i = 0;

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
	int old_argc = argc;
	
	if (argc == 2)
		argv = stringhandling(&argc, argv);
	
	sdata = (t_Datastruct){{NULL}, {NULL}, {NULL}, {NULL}, NULL};
	sdata.numbers = appendnumbers(argc, argv, sdata.tops, sdata.topsbg);
	if (issorted(sdata.tops[0]) == 1)
	{
		free_listt_node(sdata.tops[0]);
		free_listt_node(sdata.topsbg[0]);
		free(sdata.numbers);
		if (old_argc == 2)
		{
			magicnumber = 1;
			while(argv[magicnumber])
			{
				free(argv[magicnumber]);
				magicnumber++;
			}
		free(argv);
		}
		exit(0);
	}
		
	if (argc == 4)
		argc3op(&sdata, old_argc, argv);
	initchunks(chunks, chonks);
	bubblesortarr(sdata.numbers, argc - 1);
	appendchunks(chonks, sdata.chonksbg, sdata.numbers, argc);
	magicnumber = backgroundoperations(&sdata, argc, argv);
	sorthalf(sdata.tops, chunks, chonks, magicnumber);
	midpointsort(sdata.tops);
	threepointalgo(sdata.tops);
	free_all2(chunks, sdata.tops, chonks);
	free(sdata.numbers);
	if (old_argc == 2)
	{
		magicnumber = 1;
	while(argv[magicnumber])
	{
		free(argv[magicnumber]);
		magicnumber++;
	}
	free(argv);
	}
	
}
