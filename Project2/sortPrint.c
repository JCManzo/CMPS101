/*
 * sortPrint.c
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 *	Driver program to test/print heapsort and insertion sort algorithms.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heapSort.h"
#include "insertionSort.h"
#include "Heap.h"

 int main(int argc, char const *argv[])
 {
 	/* code */
 	FILE *in;
 	int numOfKeys, key;
 	int i = 0;
 	/*check command line for correct number of arguments*/
    if( argc != 2 ){
      printf("Usage: %s infile\n", argv[0]);
      exit(1);
   }

	in = fopen(argv[1], "r");

    if( in == NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

 	/*Reads first line of file which contains the number of keys contained int he file.*/
 	fscanf(in, "%i", &numOfKeys);

 	/*Create two arrays for each sorting alogorithm.*/
 	int keysA[numOfKeys];
 	int keysB[numOfKeys];

 	while(i < numOfKeys) {
    	fscanf(in, "%i", &key);
    	keysA[i+1] = key;
  		keysB[i+1] = key;
		i++;
  	}
  	printf("%s\n", "Unsorted array A: ");
  	printHeap(keysA, numOfKeys);
  	printf("\n");

  	printf("%s\n", "Sorted aray A using heap sort:");
  	heapSort(keysA,  numOfKeys);
  	printHeap(keysA, numOfKeys);
  	printf("\n");

  	printf("%s\n", "Unsorted array B:");
  	printHeap(keysB, numOfKeys);
  	printf("\n");

  	printf("%s\n", "Sorted array B using insertion sort:");
    insertionSort(keysB, numOfKeys);
    printHeap(keysB, numOfKeys);

	fclose(in);

 	return 0;
 }