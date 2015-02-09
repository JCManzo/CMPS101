#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

#define MAX_LEN 250

int main(int argc, char const *argv[])
{
	/* code */

  int i;
	FILE *in;
    /*stores first line of file, a strign representation of a single ingeter.*/
    int customers;
    int purchases = 0;
    int tableSize;
    int custID;
    int shouldRecommend;    /*0 = don't print recommendations. 1 = print*/
    long bookID;
    HashRef H;
    int hashval;

    /*check command line for correct number of arguments*/
    if( argc != 2){
      printf("Usage: %s infile\n", argv[0]);
      exit(1);
   }

	in = fopen(argv[1], "r");

    if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }

  
  /*Reads first 3 lines of file which contains number of customers, total
   *purchases and the size for this hash table respectively*/
  fscanf(in, "%d", &customers);
  fscanf(in, "%d", &purchases);
  fscanf(in, "%d", &tableSize);

  BookListRef custArray[customers];
  /*Creates customer purchase history list Lc*/
    for(i =0; i < customers; i++) {
      custArray[i + 1] = newList();
    }
  H = newTable(tableSize);
  BookListRef L;
  while(purchases > 0) {
    fscanf(in, "%d %ld %d", &custID, &bookID, &shouldRecommend);
    if(bookExists(custArray[custID], bookID)) {
      updateBookCount(custArray[custID], bookID);
    } else {
      addBook(H, custArray[custID], bookID);
      insertAfterLast(custArray[custID], bookID);
    }
    
    if(shouldRecommend) {
      /*Recommend book according to bookID hash list's larger book-count*/
     BookListRef R;
      /*Sort the list by count. Largest will be last*/
      R = lookUp(H, bookID);
      
     insertionSort(R);
     long book = getLast(R);
     if(bookExists(custArray[custID], book)) {
        moveLast(R);
        movePrev(R);
        book = getCurrent(R);
      }
     printf("%s%ld%s%ld\n", "Customers buying book ", bookID, " also purchased ", book);
    }
    purchases--;

  }
  
  /*Frees our Lc lists*/
  for(i =0; i < customers; i++) {
    freeList(&custArray[i+1]);
  }
  freeTable(&H);
   
   /*Close input file streams.*/
  fclose(in);
  return 0;
}