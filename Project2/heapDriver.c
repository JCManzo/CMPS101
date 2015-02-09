/*
 * heapDriver.c
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 *	Driver program to test the heap ADT.
 */

#include "Heap.h"
#include "heapSort.h"
#include "insertionSort.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n = 9;
	heapRef H = newHeap(n);

	insert(H,23);  
	insert(H,1);  
	insert(H,6);  
	insert(H,19);  
	insert(H,14);  
	insert(H,18);  
	insert(H,8);  
	insert(H,24);  
	insert(H,15);  
	//maxHeapify(getArray(H),n);
	

	printf("%s\n", "Heapified Array:");

	printf("%s%d\n", "Max value: ", maxValue(H));

	deleteMax(H);
	printf("\n");
	printf("%s\n", "Heapified array after max value deletion:");

	if(isEmpty(H)) {
		printf("\n%s\n", "Array is Empty.");
	} else {
		printf("\n%s\n", "Array is NOT empty.");
	}

	if(isFull(H)) {
		printf("\n%s\n","Array IS full." );
	} else {
		printf("\n%s\n", "Array IS NOT full.");
	}

	insert(H,3);
	printf("\n%s\n", "Heapified array after new element insertion:");

	if(isFull(H)) {
		printf("\n%s\n","Array IS full." );
	} else {
		printf("\n%s\n", "Array IS NOT full.");
	}
	
	freeHeap(&H);
	return 0;
}
