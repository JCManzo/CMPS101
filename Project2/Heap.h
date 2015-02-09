/*
 * Heap.h
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 */

#if !defined(_HEAP_H_INCLUDE_)
#define _HEAP_H_INCLUDE_

/*Handle pointer to type Heap.*/
typedef struct Heap* heapRef;

/*Constructor*/
heapRef newHeap(int maxSize);

/*Access functions*/
int isFull(heapRef H);
int isEmpty(heapRef H);
int maxValue(heapRef H);

/*Manipulation Procedures*/
void deleteMax(heapRef H);
void insert(heapRef H, int priority);

/*optional*/
void makeHeap(heapRef H, int size);
void printHeap(int data[], int size);
void freeHeap(heapRef *pH);
#endif