/*
 * insertionSort.c
 *
 *  Created on: April 25, 2013
 *      Author: Juan Manzo
 *  Insertion sort implemented by pseudocode given in book.
 */

#include "insertionSort.h"

void insertionSort(int keys[], int numKeys) {
  int j, i, key;

  for(j = 2; j <=numKeys; j++) {  
    
    key = keys[j];
    i = j-1;

    while(i > 0 && keys[i] > key) {
      keys[i + 1] = keys[i];
      i = i -1;
    }
    
    keys[i + 1] = key;
  }
}