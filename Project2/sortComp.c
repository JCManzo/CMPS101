/*
 * sortComp.c
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heapSort.h"
#include "insertionSort.h"

int main(int argc, char const *argv[])
{
	/* code */
 	FILE *in;
 	int numOfKeys, key;
 	int i = 0;
 	clock_t startTime, duration;

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
 	
 	/*Read and initialize data*/
 	fscanf(in, "%i", &numOfKeys);

 	int keysA[numOfKeys];
 	int keysB[numOfKeys];

 	while(i < numOfKeys) {
    	fscanf(in, "%i", &key);
    	keysA[i+1] = key;
  		keysB[i+1] = key;
		i++;
  	} 

  	startTime = clock();
  	/*Run heap sort algorithm*/
  	heapSort(keysA,  numOfKeys);
  	duration = clock() - startTime;
  	printf ("Heap sort took %f seconds.\n", ((float) duration ) / CLOCKS_PER_SEC);
  	
  	startTime = clock();
  	/*Run insertion sort algorithm*/
  	insertionSort(keysA,  numOfKeys);
  	duration = clock() - startTime;
  	printf ("Insertion sort took %f seconds.\n", ((float) duration ) / CLOCKS_PER_SEC);
  	
  	fclose(in);
  	return 0;
}