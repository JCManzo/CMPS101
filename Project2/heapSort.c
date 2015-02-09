/*
 * heapSort.c
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 */
#include <stdio.h>
#include "Heap.h"
#include "heapSort.h"


void heapSort(int keys[], int numKeys) {
	/*Post: keys[] will be in ascending sorted order*/

	int i;
	heapRef H = newHeap(numKeys);
	/*Copy elements in keys[] into the heap's array*/
	for(i = 1; i <=numKeys; i++) {
		insert(H, keys[i]);
	}

	makeHeap(H, numKeys);
	/*Replace elements in keys[] in sorted order.*/
	for(i = numKeys; i > 0; i--) {
		keys[i]= maxValue(H);
		deleteMax(H);
	}

	freeHeap(&H);
}

