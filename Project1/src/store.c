/**
 * Author: Julio Franco
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#define MAX_LEN 250

int main(int argc, char const *argv[]) {
    char line[MAX_LEN];
    int i;
    FILE *in, *out;
    int customers;
    int purchases;
    int custID;
    long bookID;
    if( argc != 3 ){
      printf("Usage: %s infile outfile\n", argv[0]);
      exit(1);
   }

	in = fopen(argv[1], "r");
   	out = fopen(argv[2], "w");

    if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

  if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
  }

  fscanf(in, "%d", &customers);
  fscanf(in, "%d", &purchases);
  ListHndl custArray[customers];

    for(i =0; i < customers; i++) {
      custArray[i + 1] = newList();
    }

  fprintf(out,"%s\n", "Customer#       books purchased" );
  while(fgets(line , sizeof(line), in) != NULL) {
     fscanf(in, "%d%ld", &custID, &bookID);
     insertAtBack(custArray[custID], bookID);
  }

  for(i = 0; i < customers; i++) {
    fprintf(out,"%d:      ",i + 1);
    printList(out,custArray[i + 1]);
  }

    freeList(&custArray[1]);

   fclose(in);
   fclose(out);
  return 0;
}