/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backuputils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/15 15:24:42 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int bubblesort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
	
	
	return(arr[n / 2]);
}





void cpra (Node **list)
{
	Node* head = *list;
	Node* temp = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list A is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int last;
	first = head->data;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->data;
	
	if (first>last)
	{
		rotatea(&list[0]);
	}
	ft_printf("cpra ");
}

void cprb (Node **list)
{
	Node* head = *list;
	Node* temp = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list B is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int last;
	first = head->data;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	last = temp->data;
	
	if (first>last)
	{
		rotateb(&list[0]);
		ft_printf("cprb ");
	}
	
}

void cpsa (Node **list)
{
	Node *head = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list A is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int second;
	
	first = head->data;
	second = head->next->data;
	
	if (first>second)
	{
		swapa(&list[0]);
		ft_printf("cpsa");
	}
}

void cpsb (Node **list)
{
	Node *head = *list;
	if(list == NULL || (*list)->next == NULL)
	{
		ft_printf("list B is empty, or doesn't have 2 args");
		exit(-1);
	}
	int first;
	int second;
	
	first = head->data;
	second = head->next->data;
	
	if (first>second)
	{
		swapb(&list[0]);
		ft_printf("cpsb");
	}
}


int isSorted(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return (1);
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->data > current->next->data) {
            return (0); 
        }
        current = current->next;
    }

    return (1); 
}

int isSortedB(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return (1);
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->data < current->next->data) {
            return (0); 
        }
        current = current->next;
    }

    return (1); 
}

int comparesums(Node *head)
{
	int sum1;
	int sum2;
	int i;

	sum1 = 0;
	sum2 = 0;
	i = 0;
	while(i < 3)
	{
		sum1 += head->data;
		head = head->next;
		i++;
	}
	i = 0;
	while(i < 3)
	{
		sum2 += head->data;
		head = head->next;
		i++;
	}
	if (sum1 <= sum2)
		return (1);
	else
		return (0);
}

int comparelisttops(Node **lista, Node **listb)
{
	Node *listan = *lista;
	Node *listbn = *listb;
	int list1head;
	int list2head;

	list1head = 0;
	list2head = 0;
	list1head += listan->data;
	list2head += listbn->data;
	if (list1head <= list2head)
		return (1);
	else
		return (0);
} 
void algorithm (Node **lista, Node **listb, int median)
{
	while(isSorted(lista[0]) != 1 || isSortedB(listb[0]) != 1)
	{
		//insert error handling
		
		Node *heada = *lista;
		Node *tempa = *lista;
		Node *tempca = *lista;
		
		Node *headb = *listb;
		Node *tempb = *listb;
		// Node *tempcb = *listb;
		
		int firsta;
		int seconda;
		int lasta;
		int counta;
		int firstb;
		int secondb;
		int lastb;
		int countb;
		countb = 0;
		
		firsta = heada->data;
		seconda = heada->next->data;
		while (tempa->next != NULL)
			tempa = tempa->next;
		lasta = tempa->data;


		// while(tempcb != NULL && countb < 6)
    	// {
        // 	tempcb = tempcb->next;
        // 	countb++;
    	// }
			// in case i want to implement costcomparison for list b
		// if (countb == 6 && tempcb != NULL)
		// {
		// 	firstb = headb->data;
		// 	secondb = headb->next->data;
		// 	while (tempb->next != NULL)
		// 		tempb = tempb->next;
		// 	lastb = tempb->data;
		// }

		if((*listb != NULL && (*listb)->next != NULL) &&
		((*listb)->next->next != NULL))
		{
			firstb = headb->data;
			secondb = headb->next->data;
			while (tempb->next != NULL)
				tempb = tempb->next;
			lastb = tempb->data;
		}
		
		counta = 0;
		while(tempca != NULL && counta < 6)
    	{
        	tempca = tempca->next;
        	counta++;
    	}
		if (counta == 6 && tempca != NULL)
			if (comparesums(lista[0]) == 1)
			{
				pushtob(&lista[0], &listb[0]);
				pushtob(&lista[0], &listb[0]);
				pushtob(&lista[0], &listb[0]);
			}
		if(firsta > seconda) 
			swapa(&lista[0]);
		else if(firsta < lasta){
			pushtob(&lista[0], &listb[0]);
			continue;
		}
		else if (firsta == lasta || firsta > lasta)
			reverserotatea(&lista[0]);
		
		if((*listb != NULL && (*listb)->next != NULL)
			&& firstb < secondb)
			swapb(&listb[0]);
		else if ((*listb != NULL && tempb->next != NULL)
			&& firstb < lastb)
			rotateb(&lista[0]);
		else if ((*listb != NULL && tempb->next != NULL)
			&& firstb > lastb)
			reverserotateb(&listb[0]);
			
			
		if (isSorted(*lista) == 1 && isSortedB(*listb) == 1)
			{	
				while(listb != NULL)
				{
					pushtoa(listb, &lista[0]);
					// ft_printf("conglaturation, you've sorted everything!");
				}
					
			}
	}
	// ft_printf("yay?");
}




int initelem(int *numbers, int argc)
{
    int i = 0;
    Element arr[argc-1];
    // Assuming the array is already sorted and filled with values
    for (int i = 0; i < argc-1; i++) {
        arr[i].position = i;
        arr[i].value = numbers[i];
    }
    printArray(arr, argc-1);
    return(arr);
}


    // Element arr[] = initelem(numbers, argc);
    

	void sorthalf(Node **lista, Node **listb, Element arr[], int argc)
{
	while(1)
	{
		Node *head = *lista;
		int tempdata;
		int countforargc = countnodes(*lista);
		tempdata = head->data;
		if(tempdata <= arr[(countforargc) / 2].value)
		{
			
			pushtob(lista, listb);
			head = *lista;
			tempdata = head->data;
		}
		else
		{
			rotatea(lista);
			head = *lista;
			tempdata = head->data;
			int countn = countnodes(*lista);
			if(countn <= (countforargc) / 2)
			{
				ft_printf("argc/2: %d \n", argc/2);
				ft_printf("countnodes: %d \n", countn);
				return;
			}
		}argc -=1;
	}
}

	if(n <= p/2)
	{
		if (hasLowerThanMiddle(lista, middle) == 1)
		{
			ft_printf("huston, we can increment\n");
			i++;
			middle = find_median(lista);
			p = p/2;
		}
		// else
		// {
		// 	rotatea(&lista);
		// 	head = lista;
		// 	tempdata = head->data;
		// }	
	}



// this works
void sorthalf(Node *tops[],Chunk *chunks[], int i)
{
	int k = 0;	
	
	int middle;
	
	// Node *lista = tops[0];
	// Node *listb = tops[1];
	middle = find_median(tops[0]);
	int n = countnodes(tops[0]);
	int p = countnodes(tops[0]);
	ft_printf("p = %d\n",p);
	ft_printf("n = %d\n",n);
	while(tops[0] && n > 2)
	{
		n = countnodes(tops[0]);
		if(hasLowerThanMiddle(tops[0], middle) == 0)
		{
			//condition to search should be here, to get one last check in befire incrementing i
			ft_printf("huston, we are incrementing\n");
			i++;
			middle = find_median(tops[0]);
			p = p/2;
		}
		ft_printf("n = %d\n",n);

		// ft_printf("list a \n");
    	// printList(lista);
    	// ft_printf("list b \n");
    	// printList(listb);
		if (n <= 3)
		{
			ft_printf("list a \n");
			printList(tops[0]);
			ft_printf("list b \n");
			printList(tops[1]);
			ft_printf("exiting");
			return ;
		}
		
		Node *head = tops[0];
		int tempdata;
		tempdata = head->data;

		ft_printf("middle: %d\n", middle);
		ft_printf("i: %d\n", i);
		ft_printf("tempdata: %d\n", tempdata);
		if(tempdata <= middle)
		{
			ft_printf("appending tempdata %d, because middle is %d\n", tempdata, middle);
			ft_printf("p is currently %d\n", p);
			pushtob(&tops[0], &tops[1]);
			appendchunk(&chunks[i], tempdata, k);
			k++;
			
			// ft_printf("list b \n");
			// printList(listb);
			head = tops[0];
			tempdata = head->data;
		}
		else
		{
			rotatea(&tops[0]);
			head = tops[0];
			tempdata = head->data;
			// int countn = countnodes(lista);
			// if(countn <= p/2)
			// {ft_printf("YOU SHOULD NOT BE IN HERE EVER\n");
			// 	i++;
			// 	p = p/2;
			// 	// printDataChunkArray((*chunkarray)[i], n/2);
			// 	// sorthalf(tops, chunks, i);
			// }
		}
	}
}

// this one below doesnt



void sorthalf(Node *tops[],Chunk *chunks[], int i)
{
	int k = 0;	
	
	int middle;
	
	Node *lista = tops[0];
	Node *listb = tops[1];
	middle = find_median(lista);
	int n = countnodes(lista);
	int p = countnodes(lista);
	ft_printf("p = %d\n",p);
	ft_printf("n = %d\n",n);
	while(lista && n > 2)
	{
		n = countnodes(lista);
		if(hasLowerThanMiddle(lista, middle) == 0)
		{
			//condition to search should be here, to get one last check in befire incrementing i
			ft_printf("huston, we are incrementing\n");
			i++;
			middle = find_median(lista);
			p = p/2;
		}
		ft_printf("n = %d\n",n);

		// ft_printf("list a \n");
    	// printList(lista);
    	// ft_printf("list b \n");
    	// printList(listb);
		if (n <= 3)
		{
			ft_printf("list a \n");
			printList(lista);
			ft_printf("list b \n");
			printList(listb);
			ft_printf("exiting");
			return ;
		}
		
		Node *head = lista;
		int tempdata;
		tempdata = head->data;

		ft_printf("middle: %d\n", middle);
		ft_printf("i: %d\n", i);
		ft_printf("tempdata: %d\n", tempdata);
		if(tempdata <= middle)
		{
			ft_printf("appending tempdata %d, because middle is %d\n", tempdata, middle);
			ft_printf("p is currently %d\n", p);
			pushtob(&lista, &listb);
			appendchunk(&chunks[i], tempdata, k);
			k++;
			
			// ft_printf("list b \n");
			// printList(listb);
			head = lista;
			tempdata = head->data;
		}
		else
		{
			rotatea(&lista);
			head = lista;
			tempdata = head->data;
			// int countn = countnodes(lista);
			// if(countn <= p/2)
			// {ft_printf("YOU SHOULD NOT BE IN HERE EVER\n");
			// 	i++;
			// 	p = p/2;
			// 	// printDataChunkArray((*chunkarray)[i], n/2);
			// 	// sorthalf(tops, chunks, i);
			// }
		}
	}
}



int find_medianchunk(Chunk *head) {
    if (head == NULL) return -1; // Handle empty list

    // Copy and sort the list
    Chunk *sorted_copy = copy_list(head);
    bubble_sort(sorted_copy);

    // Traverse to find the median
    Chunk *slow = sorted_copy;
    Chunk *fast = sorted_copy;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    int median = slow->value;

    // Free the copied list
    while (sorted_copy != NULL) {
        Chunk *temp = sorted_copy;
        sorted_copy = sorted_copy->next;
        free(temp);
    }

    return median;
}


void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	int k = 0;
	int o = 0;
	if(i > 0) //while 
	{
		
		if (chunks[i] == NULL)// i guess this works if i increment chunks too far
			i--;				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		ft_printf("i is %d\n", i);
		
		int middle = find_medianchunk(chunks[i]);
		ft_printf("middle is %d\n", middle);
		if(chunks[i])//while
		{

			Chunk *head = chunks[i];
			int tempdata;
			tempdata = head->value;

			ft_printf("middle: %d\n", middle);
			ft_printf("i: %d\n", i);
			ft_printf("tempdata: %d\n", tempdata);
			if(tempdata > middle && countnodeschunk(chonks[o]) >= 2)
			{
				ft_printf("appending tempdata %d, because middle is %d\n", tempdata, middle);
				addbottomchunk(&chonks[o], tempdata, k);
				k++;
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				head = chunks[i];
				tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
			ft_printf("listb:\n");
			printList(tops[1]);
			
			freechunk(&chunks[i]); // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		{
			middle = find_medianchunk(chunks[i]);
		}
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
}

void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// int k = 0;
	// int o = 0;

	chonks[1] = 0;
	while(i > 0) //while 
	{
		
		if (chunks[i] == NULL)// i guess this works if i increment chunks too far
			{
				i--;
				if (i == 0)
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(chunks[i])//while
		{

			Chunk *head = chunks[i];
			int tempdata;
			tempdata = head->value;
			int highest = find_highest_integer(chunks[i]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(chunks[i])
			{
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(chunks[i]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					rotatebchunk(&chunks[i]);
					rc++;
					tempdata = chunks[i]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				tempdata = chunks[i]->value;
				while(tempdata != highest)
				{
					reverserotatebchunk(&chunks[i]);
					rrc++;
					tempdata = chunks[i]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				
				if(rc <= rrc)
				{
					tempdata = tops[1]->data;
				ft_printf("I AM IN RC1\n");
				ft_printf("highest: %d\n", highest);
				ft_printf("tempdata: %d\n", tempdata);
				ft_printf("rrc: %d\n", rrc);
				ft_printf("rc: %d\n", rc);
					while(tempdata != highest)
					{
						ft_printf("I AM IN RC2\n");
						rotateb(&tops[1]);
						tempdata = tops[1]->data;
						ft_printf("listb:\n");
						printList(tops[1]);
						ft_printf("chunk:\n");
						printchunk(chunks[i]);
					}	
				}
				else if (rc >= rrc)
				{
					tempdata = tops[1]->data;
				ft_printf("I AM IN RRC1\n");
				ft_printf("highest: %d\n", highest);
				ft_printf("tempdata: %d\n", tempdata);
				ft_printf("rrc: %d\n", rrc);
				ft_printf("rc: %d\n", rc);
					while(tempdata != highest)
					{
						ft_printf("I AM IN RRC2\n");
						reverserotateb(&tops[1]);
						tempdata = tops[1]->data;
						ft_printf("listb:\n");
						printList(tops[1]);
						ft_printf("chunk:\n");
						printchunk(chunks[i]);
					}
				}
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;
				if(tempdata == highest)
				{
					// ft_printf("PUSHING");
					pushtoa(&tops[1], &tops[0]);
					freechunk(&chunks[i]);
				}
				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}

// v v is completely bricked
void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// int k = 0;
	// int o = 0;

	while(i > 0) //while 
	{
		
		if (chunks[i] == NULL)// i guess this works if i increment chunks too far
			{
				i--;
				if (i == 0)
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(chunks[i])//while
		{
			
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			Chunk *head = chunks[i];
			Chunk *headchonk = chonks[i];
			int tempdata;
			tempdata = head->value;
			
			int highest = find_highest_integer(chunks[i]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(chunks[i])
			{	ft_printf("listb:\n");
				printList(tops[1]);
				printchunk(chunks[i]);
				printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(chunks[i]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					
					rotatebchunk(&chunks[i]);
					rc++;
					tempdata = chunks[i]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&chonks[i]);
					rrc++;
					tempdata = chonks[i]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							rrc--;
						}
						pushtoa(&tops[1], &tops[0]);
						freechunk(&chonks[i]);
						
						while(temprrc -1 != 0)
						{

							rotateb(&tops[1]);
							rotatebchunk(&chonks[i]);
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						pushtoa(&tops[1], &tops[0]);
						
						freechunk(&chunks[i]);
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&chunks[i]);
							temprc--;
						}
					}
					
				}
				else
				{
					printList(tops[1]);
					printchunk(chunks[i]);
					printchunk(chonks[i]);
					pushtoa(&tops[1], &tops[0]);
						freechunk(&chunks[i]);
						freechunk(&chonks[i]);
						
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}



// v v v vv vv v v  v i need to
 //change chunks and chonks against lists, because obv if i try to find the cost and
 // i'm comparing chunks against the whole list, no wonder i'm never gonna find the cheapest operation


void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// int k = 0;
	// int o = 0;

	while(i > 0) //while 
	{
		
		if (chunks[i] == NULL)// i guess this works if i increment chunks too far
			{
				ft_printf("HUSTON WE ARE DECREMENTING\n");
				i--;
				
				if (i == 0)
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(chunks[i])//while
		{
			
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			Chunk *head = chunks[i];
			Chunk *headchonk = chonks[i];
			int tempdata;
			tempdata = head->value;
			
			int highest = find_highest_integer(chunks[i]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(chunks[i])
			{	ft_printf("listb:\n");
				printList(tops[1]);
				ft_printf("lista:\n");
				printList(tops[0]);
				ft_printf("chunks:\n");
				printchunk(chunks[i]);
				ft_printf("chonks:\n");
				printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(chunks[i]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					
					rotatebchunk(&chunks[i]);
					rc++;
					tempdata = chunks[i]->value;
					ft_printf("highest: %d\n", highest);
					ft_printf("tempdata: %d\n", tempdata);
					ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&chonks[i]);
					rrc++;
					tempdata = chonks[i]->value;
					ft_printf("highest: %d\n", highest);
					ft_printf("tempdata: %d\n", tempdata);
					ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							
							rrc--;
						}
						ft_printf("pushing %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						freechunk(&chonks[i]);//original
						freechunk(&chunks[i]);
						while(temprrc -1 != 0)
						{

							rotateb(&tops[1]);
							rotatebchunk(&chonks[i]);///////////
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						ft_printf("pushing %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						freechunk(&chonks[i]);
						freechunk(&chunks[i]);//original
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&chunks[i]);
							temprc--;
						}
					}
					
				}
				else
				{
					// printList(tops[1]);
					// printchunk(chunks[i]);
					// printchunk(chonks[i]);
					ft_printf("pushing IN ELSE %d\n", tops[1]->data);
					pushtoa(&tops[1], &tops[0]);
					freechunk(&chunks[i]);
					freechunk(&chonks[i]);
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}


// vv v v v v v  vIT WORKS

void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// int k = 0;
	// int o = 0;
	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};

	while(i > 0) //while 
	{
		
		if (chunks[i] == NULL)// i guess this works if i increment chunks too far
			{
				// ft_printf("HUSTON WE ARE DECREMENTING\n");
				i--;
				
				if (i == 0)
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(chunks[i])//while
		{
			
			listbcopy1[0] = copyNodeToChunk(tops[1]);
			listbcopy2[0] = copyNodeToChunk(tops[1]);
			// ft_printf("listbcopy1\n");
			// printchunk(listbcopy1[0]);
			// ft_printf("listbcopy2\n");
			// printchunk(listbcopy2[0]);
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			tempdata = head->value;
			
			int highest = find_highest_integer(chunks[i]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(chunks[i])
			{	
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(listbcopy1[0]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					
					rotatebchunk(&listbcopy1[0]);
					rc++;
					tempdata = listbcopy1[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&listbcopy2[0]);
					rrc++;
					tempdata = listbcopy2[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							
							rrc--;
						}
						// ft_printf("pushing in rc > %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						freechunk(&chonks[i]);//original
						freechunk(&chunks[i]);
						freechunk(&listbcopy1[0]);
						freechunk(&listbcopy2[0]);
						while(temprrc -1 != 0)
						{

							rotateb(&tops[1]);
							rotatebchunk(&listbcopy2[0]);///////////
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						// ft_printf("pushing in rc < %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]); //good
						freechunk(&chonks[i]);
						freechunk(&chunks[i]);//original
						freechunk(&listbcopy1[0]); //good
						freechunk(&listbcopy2[0]); //good
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&listbcopy1[0]);
							temprc--;
						}
					}
					
				}
				else
				{
					// printList(tops[1]);
					// printchunk(chunks[i]);
					// printchunk(chonks[i]);
					// ft_printf("pushing IN ELSE %d\n", tops[1]->data);
					pushtoa(&tops[1], &tops[0]);
					freechunk(&chunks[i]);
					freechunk(&chonks[i]);
					freechunk(&listbcopy1[0]);
					freechunk(&listbcopy2[0]);
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}

//vvv fucked the chunks

void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// int k = 0;
	// int o = 0;
	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};
	while(i > 0) //while 
	{
		if (tops[1] == NULL)// i guess this works if i increment chunks too far
			{
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(tops[1])//while
		{
			
			listbcopy1[0] = copyNodeToChunk(tops[1]);
			listbcopy2[0] = copyNodeToChunk(tops[1]);
			
			// ft_printf("listbcopy1\n");
			// printchunk(listbcopy1[0]);
			// ft_printf("listbcopy2\n");
			// printchunk(listbcopy2[0]);
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			tempdata = head->value;
			int highest = find_highest_integer(listbcopy1[0]);
			// ft_printf("middle: %d\n", middle);
			ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(tops[1])
			{	
				ft_printf("listb:\n");
				printList(tops[1]);
				ft_printf("lista:\n");
				printList(tops[0]);
				ft_printf("listbcopy1\n");
				printchunk(listbcopy1[0]);
				ft_printf("listbcopy2\n");
				printchunk(listbcopy2[0]);
				ft_printf("chunks:\n");
				printchunk(chunks[i]);
				ft_printf("chonks:\n");
				printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(listbcopy1[0]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					rotatebchunk(&listbcopy1[0]);
					rc++;
					tempdata = listbcopy1[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&listbcopy2[0]);
					rrc++;
					tempdata = listbcopy2[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							//FIND THE HIGHEST VALUE IN CHUNK AND FREE
							// THAT ONE INSTEAD OF THE HEAD YOU DUMB FUCK
							rrc--;
						}
						// ft_printf("pushing in rc > %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing rc > chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc > chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					ft_printf("freeing rc > listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					ft_printf("freeing rc > listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
						while(temprrc -1 != 0)
						{
							rotateb(&tops[1]);
							rotatebchunk(&listbcopy2[0]);///////////
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						// ft_printf("pushing in rc < %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]); //good
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);//shit be fuczzled yo
					// ft_printf("freeing rc < chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc < chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					ft_printf("freeing rc < listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					ft_printf("freeing rc < listbcopy2: %d\n", listbcopy2[0]->value);
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&listbcopy1[0]);
							temprc--;
						}
					}
					
				}
				else
				{
					// printList(tops[0]);
					// printchunk(chunks[i]);
					// printchunk(chonks[i]);
					ft_printf("pushing IN ELSE %d\n", tops[1]->data);
					pushtoa(&tops[1], &tops[0]);
					// if(isSorted(tops[0]) == 1)
					// 		threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing IN ELSE chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing IN ELSE chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					ft_printf("freeing IN ELSE listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					ft_printf("freeing IN ELSE listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
				ft_printf("listb:\n");
				printList(tops[1]);
				ft_printf("lista:\n");
				printList(tops[0]);
				ft_printf("listbcopy1\n");
				printchunk(listbcopy1[0]);
				ft_printf("listbcopy2\n");
				printchunk(listbcopy2[0]);
				ft_printf("chunks:\n");
				printchunk(chunks[i]);
				ft_printf("chonks:\n");
				printchunk(chonks[i]);
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}


//vvvvvv made this work properly with another check if its sorted or not

void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// comparelisttops(&tops[0], &tops[1]);
	//put function here to compare tops0 and tops1 and if tops1>tops0 then do pa and sa
	// int k = 0;
	// int o = 0;

	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};
	while(i > 0) //while 
	{
			
		
		if (tops[1] == NULL)// i guess this works if i increment chunks too far
			{
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(tops[1])//while
		{
			if(isSorted(tops[0]) == 0)
			threepointalgo(tops);
			
			listbcopy1[0] = copyNodeToChunk(tops[1]);
			listbcopy2[0] = copyNodeToChunk(tops[1]);
			
			// ft_printf("listbcopy1\n");
			// printchunk(listbcopy1[0]);
			// ft_printf("listbcopy2\n");
			// printchunk(listbcopy2[0]);
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			tempdata = head->value;
			int highest = find_highest_integer(listbcopy1[0]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(tops[1])
			{	
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("listbcopy1\n");
				// printchunk(listbcopy1[0]);
				// ft_printf("listbcopy2\n");
				// printchunk(listbcopy2[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(listbcopy1[0]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					rotatebchunk(&listbcopy1[0]);
					rc++;
					tempdata = listbcopy1[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&listbcopy2[0]);
					rrc++;
					tempdata = listbcopy2[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							//FIND THE HIGHEST VALUE IN CHUNK AND FREE
							// THAT ONE INSTEAD OF THE HEAD YOU DUMB FUCK
							rrc--;
						}
						// ft_printf("pushing in rc > %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing rc > chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc > chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					ft_printf("freeing rc > listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					ft_printf("freeing rc > listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
						while(temprrc -1 != 0)
						{
							rotateb(&tops[1]);
							rotatebchunk(&listbcopy2[0]);///////////
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						// ft_printf("pushing in rc < %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]); //good
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);//shit be fuczzled yo
					// ft_printf("freeing rc < chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc < chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					ft_printf("freeing rc < listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					ft_printf("freeing rc < listbcopy2: %d\n", listbcopy2[0]->value);
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&listbcopy1[0]);
							temprc--;
						}
					}
					
				}
				else
				{
					// printList(tops[0]);
					// printchunk(chunks[i]);
					// printchunk(chonks[i]);
					ft_printf("pushing IN ELSE %d\n", tops[1]->data);
					pushtoa(&tops[1], &tops[0]);
					// if(isSorted(tops[0]) == 1)
					// 		threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing IN ELSE chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing IN ELSE chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					ft_printf("freeing IN ELSE listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					ft_printf("freeing IN ELSE listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("listbcopy1\n");
				// printchunk(listbcopy1[0]);
				// ft_printf("listbcopy2\n");
				// printchunk(listbcopy2[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}



////the following 3 functions are all working, i'm about to rip it's heart out and go play ping pong
////with it, so i'm gonna save it right now in case it breaks

int sorthalf(Node *tops[],Chunk *chunks[], int i)
{
	
	int middle;
	middle = find_median(tops[0]);
	int n = countnodes(tops[0]);
	
	while(tops[0])
	{
		n = countnodes(tops[0]);
		if(hasLowerThanMiddle(tops[0], middle) == 0)
		{
			i++;
			middle = find_median(tops[0]);
		}
		Node *head = tops[0];
		int tempdata;
		tempdata = head->data;
		int flag = costcalc(tops, middle);
		if(flag == 2)
		{
			pushtob(&tops[0], &tops[1]);
			appendchunk(&chunks[i], tempdata);

			head = tops[0];
			tempdata = head->data;
		}
		else if(flag == 1)//copy list and do calc in fc
		{
			
			rotatea(&tops[0]);
			head = tops[0];
			tempdata = head->data;
		}
		else if(flag == 0)//copy list and do calc in fc
		{
			reverserotatea(&tops[0]);//if i swap these i segfault, check why i guess 
			head = tops[0];
			tempdata = head->data;
		}
		
		if (n <= 3)
			return (i);
	}
	return (i);
}

void threepointalgo(Node *tops[])
{
	
	Node *head = tops[0];
	int first;
	int second;
	int third;
	first = head->data;
	second = head->next->data;
	
	if (countnodes(tops[0]) != 2)
	{
		third = head->next->next->data;
		
		// ft_printf("list a before\n");
		// printList(tops[0]);
		if (first > second && second > third)
		{
			// ft_printf("con1");
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first < third)
		{
			// ft_printf("con2");
			swapa(&tops[0]);
		}
			
		else if (first < second && second > third && first > third)
		{
			// ft_printf("con3");
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first > third)
		{
			// ft_printf("con4");
			pushtob(&tops[0], &tops[1]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first < second && second > third && first < third)
		{
			// ft_printf("con5");
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
		}
	}
	else if (first > second)
		swapa(&tops[0]);
	
	
	// ft_printf("list a after\n");
	// printList(tops[0]);
	
	// ft_printf("list b \n");
	// printList(listb);

}

void midpointsort(Node *tops[],Chunk *chunks[],Chunk *chonks[], int i)
{
	// comparelisttops(&tops[0], &tops[1]);
	//put function here to compare tops0 and tops1 and if tops1>tops0 then do pa and sa
	// int k = 0;
	// int o = 0;

	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};
	while(i > 0) //while 
	{
			
		
		if (tops[1] == NULL)// i guess this works if i increment chunks too far
			{
					break ;
			}				// nowdo the midpoint of chunks 
							//and start sorting them over the 3 highest at a time
		// ft_printf("i is %d\n", i);
		
		// int middle = find_medianchunk(chunks[i]);
		// ft_printf("middle is %d\n", middle);
		while(tops[1])//while
		{
			if(isSorted(tops[0]) == 0)
			threepointalgo(tops);
			
			listbcopy1[0] = copyNodeToChunk(tops[1]);
			listbcopy2[0] = copyNodeToChunk(tops[1]);
			
			// ft_printf("listbcopy1\n");
			// printchunk(listbcopy1[0]);
			// ft_printf("listbcopy2\n");
			// printchunk(listbcopy2[0]);
			chonks[i] = copy_listchunk(chunks[i]);//need 2 more copies because i fuck them
			
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			tempdata = head->value;
			int highest = find_highest_integer(listbcopy1[0]);
			// ft_printf("middle: %d\n", middle);
			// ft_printf("i: %d\n", i);
			// ft_printf("tempdata: %d\n", tempdata);
			if(tops[1])
			{	
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("listbcopy1\n");
				// printchunk(listbcopy1[0]);
				// ft_printf("listbcopy2\n");
				// printchunk(listbcopy2[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
				int rc = 0;
				int rrc = 0;
				highest = find_highest_integer(listbcopy1[0]);
				tempdata = head->value;
				while(tempdata != highest)
				{
					rotatebchunk(&listbcopy1[0]);
					rc++;
					tempdata = listbcopy1[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rc in rotatebchunk: %d\n", rc);
				}
				
				tempdata = headchonk->value;
				while(tempdata != highest)
				{//copy the list from chunnks to chonks then do one rotate op with
				//chonks and one with chunks
					reverserotatebchunk(&listbcopy2[0]);
					rrc++;
					tempdata = listbcopy2[0]->value;
					// ft_printf("highest: %d\n", highest);
					// ft_printf("tempdata: %d\n", tempdata);
					// ft_printf("rrc in reverserotatebchunk: %d\n", rrc);
				}
				// ft_printf("rc : %d\n", rc);
				// ft_printf("rrc : %d\n", rrc);
				int temprrc = rrc;
				int temprc = rc;
				if(rc != 0 || rrc != 0)
				{
					// ft_printf("ENTERED");
					// ft_printf("rc in 1: %d\n", rc);
					// ft_printf("rrc in 1: %d\n", rrc);
					if(rc >= rrc)
					{
						// ft_printf("rc in rotatebchunk: %d\n", rc);
						// ft_printf("ENTERED2");
						// ft_printf("rc in 2: %d\n", rc);
						// ft_printf("rrc in 2: %d\n", rrc);
						while(rrc != 0)
						{
							// ft_printf("ENTERED3");
							reverserotateb(&tops[1]);
							//FIND THE HIGHEST VALUE IN CHUNK AND FREE
							// THAT ONE INSTEAD OF THE HEAD YOU DUMB FUCK
							rrc--;
						}
						// ft_printf("pushing in rc > %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]);
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing rc > chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc > chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					// ft_printf("freeing rc > listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					// ft_printf("freeing rc > listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
						while(temprrc -1 != 0)
						{
							rotateb(&tops[1]);
							rotatebchunk(&listbcopy2[0]);///////////
							temprrc--;
						}
					}
					else if(rc <= rrc)
					{
						while(rc != 0)
						{
							
							rotateb(&tops[1]);
							rc--;
						}
						// ft_printf("pushing in rc < %d\n", tops[1]->data);
						pushtoa(&tops[1], &tops[0]); //good
						// if(isSorted(tops[0]) == 1)
						// 	threepointalgo(tops, chunks,chonks, i);//shit be fuczzled yo
					// ft_printf("freeing rc < chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing rc < chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					// ft_printf("freeing rc < listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					// ft_printf("freeing rc < listbcopy2: %d\n", listbcopy2[0]->value);
						while(temprc != 0)
						{
							reverserotateb(&tops[1]);
							reverserotatebchunk(&listbcopy1[0]);
							temprc--;
						}
					}
					
				}
				else
				{
					// printList(tops[0]);
					// printchunk(chunks[i]);
					// printchunk(chonks[i]);
					// ft_printf("pushing IN ELSE %d\n", tops[1]->data);
					pushtoa(&tops[1], &tops[0]);
					// if(isSorted(tops[0]) == 1)
					// 		threepointalgo(tops, chunks,chonks, i);
					// ft_printf("freeing IN ELSE chunks: %d\n", chunks[i]->value);
					// freechunk(&chunks[i]);
					// ft_printf("freeing IN ELSE chonks: %d\n", chonks[i]->value);
					// freechunk(&chonks[i]);
					// ft_printf("freeing IN ELSE listbcopy1: %d\n", listbcopy1[0]->value);
					freechunk(&listbcopy1[0]);
					// ft_printf("freeing IN ELSE listbcopy2: %d\n", listbcopy2[0]->value);
					freechunk(&listbcopy2[0]);
				}
				
				// else
				// {
				// 	tempdata = tops[1]->data;
				// // ft_printf("I AM IN RRC1\n");
				// // ft_printf("highest: %d\n", highest);
				// // ft_printf("tempdata: %d\n", tempdata);
				// // ft_printf("rrc: %d\n", rrc);
				// // ft_printf("rc: %d\n", rc);
				// 	while(tempdata != highest)
				// 	{
				// 		// ft_printf("I AM IN RRC2\n");
				// 		reverserotateb(&tops[1]);
				// 		tempdata = tops[1]->data;
				// 	}
				// }
				// tempdata = tops[1]->data;

					// ft_printf("PUSHING");
				

				
				//and insert recursion, simple as that
				// ft_printf("list b \n");
				// printList(listb);
				// head = chunks[i];
				// tempdata = head->value;
			}
			// Node *listb = tops[1];
			// ft_printf("Bchunk: %d\n", Bchunk->value);
			// ft_printf("listB; %d\n", tops[1][0]);
			// ft_printf("lista:\n");
			// printList(tops[0]);

			
				// ft_printf("listb:\n");
				// printList(tops[1]);
				// ft_printf("lista:\n");
				// printList(tops[0]);
				// ft_printf("listbcopy1\n");
				// printchunk(listbcopy1[0]);
				// ft_printf("listbcopy2\n");
				// printchunk(listbcopy2[0]);
				// ft_printf("chunks:\n");
				// printchunk(chunks[i]);
				// ft_printf("chonks:\n");
				// printchunk(chonks[i]);
			 // when pushing is done, free
			// ft_printf("Bchunk: %d\n", chunks[i]->value);

		 //in here needs to push from b to a, and also delete from the chunk each time an 
		 //element is pushed
		 // i am getting the median consistently with a copy of the chunks
		 // in find_medianchunk
		 //now i should be able to compare, push and delete chunks 
		 	
		}
		// if(hasHigherThanMiddle(chunks[i], middle) == 0)//  && data is in top3
		// {
		// 	middle = find_medianchunk(chunks[i]);
		// }
		// if(chunks[i] == NULL)
		// {
		// 	ft_printf("huston, we are decrementing\n");
		// 	i--;
		// }
	}
			// ft_printf("listb:\n");
			// printList(tops[1]);
			// ft_printf("lista:\n");
			// printList(tops[0]);
}
///// end of ping pong with heart




// safety save vvvvv


void midpointsort(Node *tops[], int i)
{
	Chunk *listbcopy1[1] = {NULL};
	Chunk *listbcopy2[1] = {NULL};
	while(i > 0)
	{		

		if (tops[1] == NULL)
			break ;
		while(tops[1])
		{
            // ft_printf("lista\n");
            // printList(tops[0]);

			if(isSorted(tops[0]) == 0)
				threepointalgo(tops);
			listbcopy1[0] = copyNodeToChunk(tops[1]);//theres something to think about here,
			listbcopy2[0] = copyNodeToChunk(tops[1]);//since i am copzing again every iteration
            
            // ft_printf("lista\n");//i might be wasting moves here.
            // printList(tops[0]);// why even restore the list if i end up copying again anyways
            // ft_printf("listb\n");//i might be wasting moves here.
            // printList(tops[1]);
        	// ft_printf("listbcopy1\n");
			// printchunk(listbcopy1[0]);
			// ft_printf("listbcopy2\n");
			// printchunk(listbcopy2[0]);
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			int highest;
			int rc = 0;
			int rrc = 0;
			highest = find_highest_integer(listbcopy1[0]);
			tempdata = head->value;
			while(tempdata != highest)
			{
				rotatebchunk(&listbcopy1[0]);
				rc++;
				tempdata = listbcopy1[0]->value;
			}

			tempdata = headchonk->value;
			while(tempdata != highest)
			{
				reverserotatebchunk(&listbcopy2[0]);
				rrc++;
				tempdata = listbcopy2[0]->value;
			}
			int temprrc = rrc;
			int temprc = rc;
            // ft_printf("rc: %d, rrc: %d\n", rc, rrc);
			if(rc != 0 || rrc != 0)
			{
				if(rc > rrc)
				{
					while(rrc != 0 && rrc < rc)
					{
						reverserotateb(&tops[1]);
						rrc--;
					}
					while(temprrc -1 != 0)
					{
                        // ft_printf("i came from line 658");
                        // if (pushtoaandchonk(tops, listbcopy1, listbcopy2) == 1)// 1 for yes
                        // {
                        //     ft_printf("chonking finished2\n");
                        //     // break;
                        // }
                        rotatebchunk(&listbcopy1[0]);
						temprrc--;
                        // ft_printf("found two\n");
					}
				}
				else if(rc <= rrc)
				{
					// ft_printf("rc = %d, rrc = %d\n", rc, rrc);
					while(rc != 0 && rrc >= rc)
					{
                        // if (nextinlinechunk(&listbcopy1[0]) == 1)// 1 for yes
                        // {
                        //     pushtoa(&tops[1], &tops[0]);
                        //     break;
                        // }
						rotateb(&tops[1]);
                        //one here
						rc--;
						// ft_printf("rc is: %d, rrc is %d\n", rc, rrc);
					}
                    // ft_printf("i came from line 683\n");
					// if(pushtoaandchunk(tops, listbcopy1, listbcopy2) == 1)

                    // {
                    //     ft_printf("chonking finished3\n");
                    //     // ft_printf("lista\n");//i might be wasting moves here.
                    //     // printList(tops[0]);// why even restore the list if i end up copying again anyways
                    //     // ft_printf("listb\n");//i might be wasting moves here.
                    //     // printList(tops[1]);
                    //     // ft_printf("listbcopy1\n");
                    //     // printchunk(listbcopy1[0]);
                    //     // ft_printf("listbcopy2\n");
                    //     // printchunk(listbcopy2[0]);
                    //     // break;
                    // }
                    
					while(temprc -1 != 0)
					{   
                        // ft_printf("i came from line 699\n");
                        // if (pushtoaandchunk(tops, listbcopy1, listbcopy2) == 1)// 1 for yes
                        // {
                        //     ft_printf("chonking finished4\n");
                        //     // break;
                        // }
                        reverserotatebchunk(&listbcopy2[0]);
                        
						temprc--;
                        // ft_printf("found four\n");
					}
				}
			}
			else
			{
                pushtoaandchonk(tops, listbcopy1, listbcopy2);
                // ft_printf("chonking finished5\n");
			}
		}
	}
}



//// safety safe done ^^^ 