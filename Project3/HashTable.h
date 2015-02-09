#if !defined(_HASHTABLE_H_INCLUDE_)
#define _HASHTABLE_H_INCLUDE_

#include "bookCountList.h"

typedef struct HashTable * HashRef;
/*Constructor/Destructor*/
HashRef newTable(int size);
void freeTable(HashRef* pH);
/*************************/

void printHashList(HashRef H);
void addBook(HashRef H, BookListRef List,long bookID);
int hash(HashRef H, long bookID);
BookListRef lookUp(HashRef H, long key);

#endif