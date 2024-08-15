/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backupswapworkingclean.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:42:32 by ckonneck          #+#    #+#             */
/*   Updated: 2024/08/14 17:58:57 by ckonneck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubblesort(int arr[], int n) {
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
}

int countnodes(Node *head)
{
	int i = 0;
	Node *temp = head;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
int countnodeschunk(Chunk *head)
{
	int i = 0;
	Chunk *temp = head;
	while(temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}


int isSorted(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return (2); //maybe change this to 2 so i can sort
    }

    Node *current = head;
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


int find_middle(Chunk* head) {
    Chunk* slow = head;
    Chunk* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return (slow->value);
}

//OMG PLEASE DELETE THIS ASAP

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Chunk* create_nodechunk(int value) {
    Chunk* new_node = (Chunk*)malloc(sizeof(Chunk));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
// Function to copy the linked list
Node* copy_list(Node* head) {
    if (head == NULL) return NULL;

    Node* new_head = create_node(head->data);
    Node* current = new_head;
    Node* original = head->next;

    while (original != NULL) {
        current->next = create_node(original->data);
        current = current->next;
        original = original->next;
    }
    return new_head;
}
Chunk* copy_listchunk(Chunk* head) {
    if (head == NULL) return NULL;

    Chunk* new_head = create_nodechunk(head->value);
    Chunk* current = new_head;
    Chunk* original = head->next;

    while (original != NULL) {
        current->next = create_nodechunk(original->value);
        current = current->next;
        original = original->next;
    }
    return new_head;
}

Chunk* copy_current_chunk(Chunk* node) {
    if (node == NULL) return NULL;

    Chunk* new_node = create_nodechunk(node->value);
    return new_node;
}

Chunk* copyNodeToChunk(Node* head) {
    if (head == NULL)
		return NULL;

    Chunk* chunkHead = create_nodechunk(head->data);
    Chunk* chunkCurrent = chunkHead;
    Node* nodeCurrent = head->next;

    while (nodeCurrent != NULL) {
        Chunk* newChunk = create_nodechunk(nodeCurrent->data);
        chunkCurrent->next = newChunk;
        chunkCurrent = newChunk;
        nodeCurrent = nodeCurrent->next;
    }

    return (chunkHead);
}

// Function to bubble sort the linked list
void bubble_sort(Node* head) 
{
    if (head == NULL)
		return;

    int swapped;
    Node* current;
    Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Function to find the median value
int find_median(Node* head) {
    if (head == NULL) return -1; // Handle empty list

    // Copy and sort the list
    Node* sorted_copy = copy_list(head);
    bubble_sort(sorted_copy);

    // Traverse to find the median
    Node* slow = sorted_copy;
    Node* fast = sorted_copy;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    int median = slow->data;

    // Free the copied list
    while (sorted_copy != NULL) {
        Node* temp = sorted_copy;
        sorted_copy = sorted_copy->next;
        free(temp);
    }

    return median;
}

void swap(Chunk* a, Chunk* b) {
    int tempValue = a->value;
    int tempPosition = a->position;
    a->value = b->value;
    a->position = b->position;
    b->value = tempValue;
    b->position = tempPosition;
}

// Function to perform Bubble Sort on the linked list
void bubblesortchunk(Chunk* head) {
    int swapped;
    Chunk* ptr1;
    Chunk* lptr = NULL;

    // Checking for empty list
    if (head == NULL)
        return;

    swapped = 1;
    while (swapped) {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->value > ptr1->next->value) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

int find_medianchunk(Chunk *head) {
    if (head == NULL) return -1; // Handle empty list

    // Copy and sort the list
    Chunk *sorted_copy = copy_listchunk(head);
    bubblesortchunk(sorted_copy);

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



//PLEASE DELETE THE ABOVE ASAP

int hasLowerThanMiddle(Chunk *chunk, int middle) {
    Chunk *current = chunk;
    while (current != NULL) {
        if (current->value < middle) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int hasHigherThanMiddle(Chunk *head, int middle) {
    Chunk *current = head;
    while (current != NULL) {
        if (current->value > middle) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void freechunk(Chunk **head)
{
    if (*head == NULL)
        return;
    Chunk *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int find_highest_integer(Chunk *head) {
    int highest = INT_MIN;
    Chunk *current = head;

    while (current != NULL) {
        if (current->value > highest) {
            highest = current->value;
        }
        current = current->next;
    }

    return highest;
}


int costcalc(Node *tops[], int middle)
{	
	Chunk *listbcopy3[1] = {NULL};
	Chunk *listbcopy4[1] = {NULL};
	
	listbcopy3[0] = copyNodeToChunk(tops[0]);
	listbcopy4[0] = copyNodeToChunk(tops[0]);
	Node *head = tops[0];
	int tempdata;
	int rrc = 0;
	int rc = 0;
	
	
	tempdata = head->data;
	if (tempdata <= middle)
		return(2);
	while (tempdata > middle)
	{
		reverserotatebchunk(&listbcopy3[0]);
		rrc++;
		tempdata = listbcopy3[0]->value;
	}
	tempdata = head->data;
	while (tempdata > middle)
	{
		rotatebchunk(&listbcopy4[0]);
		rc++;
		tempdata = listbcopy4[0]->value;
	}
	if (rc <= rrc)
		return (1);
	else
		return (0);
}

void sortintochunks(Chunk *chunks[], Chunk *chonks[], int i)
{
	int count = 0;
	Chunk* current = chonks[0];
	Chunk* last = NULL;
    while (current != NULL && count < 48)
	{
        Chunk* new_node = copy_current_chunk(current);
        if (chunks[i] == NULL) 
            chunks[i] = new_node;
		else
            last->next = new_node;
        last = new_node;
		Chunk* temp = chonks[0];
        chonks[0] = chonks[0]->next;
        free(temp);
        current = chonks[0];
        count++;
    }
}

void freethespecificdata(Chunk *chunks[], int i, Node *tops[])
{
	Chunk *headchunk = chunks[i];
    Chunk *prevchunk = NULL;

    while (headchunk != NULL && headchunk->value != tops[0]->data)
    {
        prevchunk = headchunk;
        headchunk = headchunk->next;
    }

    if (headchunk != NULL && headchunk->value == tops[0]->data)
    {
        if (prevchunk == NULL)
            freechunk(&chunks[i]);
        else
        {
            prevchunk->next = headchunk->next;
            free(headchunk);
        }
    }
}


int sorthalf(Node *tops[],Chunk *chunks[], Chunk *chonks[], int i)
{
	sortintochunks(chunks, chonks, i);
	int middle;
	middle = find_medianchunk(chunks[i]);
	int n = countnodes(tops[0]);
	while(tops[0])
	{
		n = countnodes(tops[0]);
		if(!chunks[i])
		{
			i++;
			sortintochunks(chunks, chonks, i);
		}
		middle = find_medianchunk(chunks[i]);
		int flag = costcalc(tops, middle);
		if(flag == 2)
		{
			freethespecificdata(chunks, i, tops);
			pushtob(&tops[0], &tops[1]);
		}
		else if(flag == 1)
			rotatea(&tops[0]);
		else if(flag == 0)
			reverserotatea(&tops[0]);
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
		if (first > second && second > third)
		{
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first < third)
			swapa(&tops[0]);
		else if (first < second && second > third && first > third)
		{
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[0], &tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first > second && second < third && first > third)
		{
			pushtob(&tops[0], &tops[1]);
			rotatea(&tops[0]);
			rotatea(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
			reverserotatea(&tops[0]);
			reverserotatea(&tops[0]);
		}
		else if (first < second && second > third && first < third)
		{
			pushtob(&tops[0], &tops[1]);
			swapa(&tops[0]);
			pushtoa(&tops[1], &tops[0]);
		}
	}
	else if (first > second)
		swapa(&tops[0]);
}

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
			if(isSorted(tops[0]) == 0)
				threepointalgo(tops);
			listbcopy1[0] = copyNodeToChunk(tops[1]);
			listbcopy2[0] = copyNodeToChunk(tops[1]);
			Chunk *head = listbcopy1[0];
			Chunk *headchonk = listbcopy2[0];
			int tempdata;
			tempdata = head->value;
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
			if(rc != 0 || rrc != 0)
			{
				if(rc >= rrc)
				{
					while(rrc != 0)
					{
						reverserotateb(&tops[1]);
						rrc--;
					}
					pushtoa(&tops[1], &tops[0]);
					freechunk(&listbcopy1[0]);
					freechunk(&listbcopy2[0]);
					while(temprrc -1 != 0)
					{
						rotateb(&tops[1]);
						rotatebchunk(&listbcopy2[0]);
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
					freechunk(&listbcopy1[0]);
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
				pushtoa(&tops[1], &tops[0]);
				freechunk(&listbcopy1[0]);
				freechunk(&listbcopy2[0]);
			}
		}
	}
}


70 11 424 439 198 208 263 155 347 449 75 349 435 117 345 461 493 300 368 153 404 357 110 45 228 60 319 452 466 395 22 408 20 249 12 420 289 250 232 253 44 320 417 405 122 423 91 43 103 475 356 426 422 482 418 454 80 162 148 391 136 7 199 307 130 5 448 95 434 21 222 353 281 36 219 133 288 268 131 383 1 481 365 72 387 266 121 440 235 406 384 65 313 326 236 40 37 15 373 58 183 499 254 393 49 303 113 295 87 467 13 433 114 126 18 135 230 137 398 213 410 115 487 19 120 119 53 261 269 209 480 272 376 394 160 47 284 123 381 184 2 237 297 16 244 177 378 277 134 273 25 50 206 377 399 166 215 428 246 71 124 127 229 66 445 388 29 344 218 101 389 390 328 56 194 150 176 35 340 196 34 386 161 187 419 138 78 252 33 181 24 471 455 402 470 143 308 227 333 86 111 437 62 285 100 446 330 462 38 427 431 52 444 379 164 311 476 234 83 192 203 221 323 322 287 89 450 412 242 460 116 397 447 193 429 260 256 382 82 139 158 77 306 28 415 142 204 170 403 477 98 214 6 304 233 149 380 264 9 257 324 79 238 315 241 496 362 302 76 240 367 26 73 335 112 293 212 106 490 359 96 69 348 495 97 167 485 81 364 413 146 159 337 432 93 500 438 99 375 491 332 421 88 358 299 401 346 267 334 30 67 151 331 473 10 174 372 291 3 251 231 90 271 61 179 274 239 396 484 57 292 68 74 318 262 414 157 182 385 294 492 225 197 31 464 309 325 17 494 14 224 85 191 279 217 132 453 39 338 351 84 109 220 210 59 298 457 163 370 366 409 472 336 188 327 205 55 280 102 202 154 94 342 259 290 488 400 442 305 223 169 459 283 129 145 105 156 144 108 125 282 54 201 104 430 329 63 478 92 147 498 27 312 443 248 474 211 128 360 140 374 189 46 479 207 363 258 354 314 48 465 270 168 186 310 4 216 350 296 497 41 316 141 226 425 468 486 371 469 463 436 317 361 341 411 190 275 489 51 23 107 441 355 458 173 451 255 175 301 171 321 180 200 416 42 392 286 247 276 64 185 243 278 165 369 483 152 339 118 178 407 245 265 32 172 8 456 195 343 352 70 11 424 439 198 208 263 155 347 449 75 349 435 117 345 461 493 300 368 153 404 357 110 45 228 60 319 452 466 395 22 408 20 249 12 420 289 250 232 253 44 320 417 405 122 423 91 43 103 475 356 426 422 482 418 454 80 162 148 391 136 7 199 307 130 5 448 95 434 21 222 353 281 36 219 133 288 268 131 383 1 481 365 72 387 266 121 440 235 406 384 65 313 326 236 40 37 15 373 58 183 499 254 393 49 303 113 295 87 467 13 433 114 126 18 135 230 137 398 213 410 115 487 19 120 119 53 261 269 209 480 272 376 394 160 47 284 123 381 184 2 237 297 16 244 177 378 277 134 273 25 50 206 377 399 166 215 428 246 71 124 127 229 66 445 388 29 344 218 101 389 390 328 56 194 150 176 35 340 196 34 386 161 187 419 138 78 252 33 181 24 471 455 402 470 143 308 227 333 86 111 437 62 285 100 446 330 462 38 427 431 52 444 379 164 311 476 234 83 192 203 221 323 322 287 89 450 412 242 460 116 397 447 193 429 260 256 382 82 139 158 77 306 28 415 142 204 170 403 477 98 214 6 304 233 149 380 264 9 257 324 79 238 315 241 496 362 302 76 240 367 26 73 335 112 293 212 106 490 359 96 69 348 495 97 167 485 81 364 413 146 159 337 432 93 500 438 99 375 491 332 421 88 358 299 401 346 267 334 30 67 151 331 473 10 174 372 291 3 251 231 90 271 61 179 274 239 396 484 57 292 68 74 318 262 414 157 182 385 294 492 225 197 31 464 309 325 17 494 14 224 85 191 279 217 132 453 39 338 351 84 109 220 210 59 298 457 163 370 366 409 472 336 188 327 205 55 280 102 202 154 94 342 259 290 488 400 442 305 223 169 459 283 129 145 105 156 144 108 125 282 54 201 104 430 329 63 478 92 147 498 27 312 443 248 474 211 128 360 140 374 189 46 479 207 363 258 354 314 48 465 270 168 186 310 4 216 350 296 497 41 316 141 226 425 468 486 371 469 463 436 317 361 341 411 190 275 489 51 23 107 441 355 458 173 451 255 175 301 171 321 180 200 416 42 392 286 247 276 64 185 243 278 165 369 483 152 339 118 178 407 245 265 32 172 8 456 195 343 352 70 11 424 439 198 208 263 155 347 449 75 349 435 117 345 461 493 300 368 153 404 357 110 45 228 60 319 452 466 395 22 408 20 249 12 420 289 250 232 253 44 320 417 405 122 423 91 43 103 475 356 426 422 482 418 454 80 162 148 391 136 7 199 307 130 5 448 95 434 21 222 353 281 36 219 133 288 268 131 383 1 481 365 72 387 266 121 440 235 406 384 65 313 326 236 40 37 15 373 58 183 499 254 393 49 303 113 295 87 467 13 433 114 126 18 135 230 137 398 213 410 115 487 19 120 119 53 261 269 209 480 272 376 394 160 47 284 123 381 184 2 237 297 16 244 177 378 277 134 273 25 50 206 377 399 166 215 428 246 71 124 127 229 66 445 388 29 344 218 101 389 390 328 56 194 150 176 35 340 196 34 386 161 187 419 138 78 252 33 181 24 471 455 402 470 143 308 227 333 86 111 437 62 285 100 446 330 462 38 427 431 52 444 379 164 311 476 234 83 192 203 221 323 322 287 89 450 412 242 460 116 397 447 193 429 260 256 382 82 139 158 77 306 28 415 142 204 170 403 477 98 214 6 304 233 149 380 264 9 257 324 79 238 315 241 496 362 302 76 240 367 26 73 335 112 293 212 106 490 359 96 69 348 495 97 167 485 81 364 413 146 159 337 432 93 500 438 99 375 491 332 421 88 358 299 401 346 267 334 30 67 151 331 473 10 174 372 291 3 251 231 90 271 61 179 274 239 396 484 57 292 68 74 318 262 414 157 182 385 294 492 225 197 31 464 309 325 17 494 14 224 85 191 279 217 132 453 39 338 351 84 109 220 210 59 298 457 163 370 366 409 472 336 188 327 205 55 280 102 202 154 94 342 259 290 488 400 442 305 223 169 459 283 129 145 105 156 144 108 125 282 54 201 104 430 329 63 478 92 147 498 27 312 443 248 474 211 128 360 140 374 189 46 479 207 363 258 354 314 48 465 270 168 186 310 4 216 350 296 497 41 316 141 226 425 468 486 371 469 463 436 317 361 341 411 190 275 489 51 23 107 441 355 458 173 451 255 175 301 171 321 180 200 416 42 392 286 247 276 64 185 243 278 165 369 483 152 339 118 178 407 245 265 32 172 8 456 195 343 352 