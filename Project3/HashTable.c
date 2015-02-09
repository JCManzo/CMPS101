#include "HashTable.h"
#include "bookListList.h"

#include "stdlib.h"

typedef struct HashTable {
  int size;
  BookListRef *table;
} HashTable;

HashRef newTable(int size) {
    if(size < 0) {
      printf("%s\n", "Invalid size for hash table. Size needs to be greater than 0.");
      exit(1);
    }

    int i;
    HashRef H;

    H = malloc(sizeof(HashTable));
    H->size = size;
    H->table = calloc(size, sizeof(BookListRef)); //BookListType is from the BookList struct in   //BookListList.c

    for(i = 0; i < size; i++) {
      H->table[i] = newList();
    }

    return H;
}

void freeTable(HashRef* pH) {
  int i;

  if(*pH == NULL) {
    return;
  }
  /*Free lists in hash table*/
  for(i = 0; i < 5; i++) {
    freeList(&((*pH)->table[i]));
  }
    /*Free fields*/
    free((*pH)->table);
    free(*pH);
    *pH = NULL;

}

void addBook(HashRef H, BookListRef LC,long bookID) {
  /*Post: Adds bookID to corresponding list. */
  int x;

  if(getLength(LC) > 0) {
    long y;
    /*Add book y in List into List Lx (H->table[x])*/

    x = hash(H, getFirst(LC));

      /*Only add when our list is not of even parity. This way we only
       * pair a distinct group once.*/
      if(!(bookExists(H->table[x], bookID))) {
          insertAfterLast(H->table[x], bookID);
        } else {
          updateBookCount(H->table[x], bookID);
        } /*end else*/

        x = hash(H, bookID);

        /*Add book bookID into List Ly (H->table[y])*/
         if(!(bookExists(H->table[x], getFirst(LC)))) {

          insertAfterLast(H->table[x], getFirst(LC));

      }
 } else {
    /*Length is 1. Just add it to the list once or update it already exists*/
      x = hash(H, bookID);
    if(!(bookExists(H->table[x], bookID))) {
      insertAfterLast(H->table[x], bookID);
    } else {
        updateBookCount(H->table[x], bookID);
      }/*end else*/
  }/*end else*/
}

int hash(HashRef H, long bookID) {
  /*Pre: H != NULL
   *PostL returns a key corresponding to an index in a hash table*/
    if(H == NULL) {
      printf("%s\n","Calling hash() on NULL Hash Table" );
      exit(1);
    }
    return ((bookID) % H->size);
}

BookListRef lookUp(HashRef H, long bookID) {
  /*Post: Returns list Lx by hasing bookID and finding the correct list.*/
     BookListRef L;
     int x = hash(H, bookID);

    L = H->table[x];
    return L;
}

void printHashList(HashRef H){
  /*Post: Prints the entire hash table. Starts at index 0, prints its list. Format
   * is bookID/count for that book..*/

  int i;

  for(i = 0; i < H->size; i++) {
    if(!isEmpty(H->table[i])) {
      printf("%d: ",i );
      printList(H->table[i]);
    }
  }
}