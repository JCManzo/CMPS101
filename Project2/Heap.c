/*
 * Heap.c
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 */

#include "Heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <Math.h>

typedef struct Heap
{
	/* data */
	int max_size;
	int curr_size;
	int* heapArray;
} Heap;

/*Constructor*/
heapRef newHeap(int maxSize) {
	/*Allocate memory, initialize and return a new heap*/
	heapRef H;
	H = malloc(sizeof(Heap));
	H->max_size = maxSize;
	H->curr_size = 0;
	H->heapArray = (int*)calloc((maxSize+1), sizeof(int));
	
	return (H);
}

void freeHeap(heapRef *pH) {
	/*Post:Frees memory allocated to array and pointer. Set pointer to NULL*/
    free(((*pH)->heapArray));
    free(*pH);
    pH = NULL;
}

/*Access Functions*/
int isFull(heapRef H) {
	/*Post: Returns true if the heap is full*/
	return(H->curr_size == H->max_size);
}

int isEmpty(heapRef H) {
	/*Post: Returns true if th heap is empty*/
	return(H->curr_size == 0);
}

int maxValue(heapRef H) {
	/*Pre: !isEmpty()*/
	/*Post: Returns the max value of the heap. H will be sorted according to the heap property.
	  Max will be reside in H->heapArray[1]*/
	if(isEmpty(H)) {
		printf("%s\n", "Heap error, calling maxValue() on empty heap.");
		exit(1);
	}
	return H->heapArray[1];;
}

/*Manipulation Functions*/
void deleteMax(heapRef H) {
	/*Pre: !isEmpty()*/
	/*Post: Deletes the max value of the  heap.
	 *Restores the heap property after deleting the largerst element*/
	
	if(isEmpty(H)) {
		printf("%s\n", "Heap error, calling deleteMax() on empty heap.");
		exit(1);
	}
	H->heapArray[1] = H->heapArray[H->curr_size];
	H->curr_size--;

	/*Restore heap property*/
	makeHeap(H, H->curr_size);
}

void insert(heapRef H, int priority) {
	/*Pre: !isFull()*/
	/*Post: Inserts a new element into the heap*/
	if(isFull(H)) {
		printf("%s\n", "Heap error, calling insert on full heap.");
		exit(1);
	}

	H->curr_size++;
	H->heapArray[H->curr_size] = priority;
}

void printHeap(int data[], int size) {
	/*Post: Iterates through array and prints out array elements*/

	int i;

	for(i = 1; i <= size; i++ ) {
		printf("%d ", data[i]);
	}

	printf("\n");
}

/*Helper functions not required by assignment.*/

void makeHeap(heapRef H, int size) {
	/*Pre: !isEmpty()
	 *Post: heapArray will be sorted so it satisfies heap property*/

	int i, key, j, parent;

    for ( i = 1 ; i <= size ; i++ )
    {
    	key = H->heapArray[i] ;
        j = i ;
        parent = ( j  ) / 2 ;
        /*Fix problem child*/
        while ( j > 1 && H->heapArray[parent] < key )
        {
            H->heapArray[j] = H->heapArray[parent] ;
            j = parent ;
            parent = ( j  ) / 2 ;
        }
        H->heapArray[j] = key ;
    }

}
