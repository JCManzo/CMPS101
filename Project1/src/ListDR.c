/**
 * Author: Julio Franco
 * Assign: ListStruct ADT
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
#define MAX_LEN 250

int main(int argc, char const *argv[])
{
  ListHndl A = newList();
  ListHndl B = newList();
  FILE *out;
  out = fopen("test.txt", "w");

  insertAtBack(A, 20);
  insertAtBack(B, 10);

  if(isEmpty(A)) {
    printf("%s\n", "ListStruct is empty." );
  }

  if(offEnd(A)) {
    printf("%s\n", "Element OFF END, undefined." );
  }

  insertAtFront(A,10);
  insertAtFront(B, 3);

  printList(out, A);
  printList(out, B);



 deleteFirst(A);

  return 0;
}