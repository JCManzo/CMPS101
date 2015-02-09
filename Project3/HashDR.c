#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

int main(int argc, char const *argv[])
{
	/* code */
  	BookListRef L = newList();
  	insertAfterLast(L,3);
  	insertAfterLast(L,4);
  	insertAfterLast(L,4);

	HashRef H = newTable(4);
	addBook(H, L, 3555);
	addBook(H, L, 5454);

	printHashList(H);
	BookListRef List = lookUp(H, 0);
	printf("%s%d: ", "List at index ", 0);
	printList(List);


	freeList(&L);
	freeTable(&H);
	return 0;
}