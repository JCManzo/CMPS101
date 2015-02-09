#if !defined(_BOOKCOUNTLIST_H_INCLUDE_)
#define _BOOKCOUNTLIST_H_INCLUDE_

#include <stdio.h>

typedef struct List * BookListRef;

/*** Constructors-Destructors ***/
BookListRef newList(void);
void freeList(BookListRef* pL);

/*** Access functions ***/
int  isEmpty(BookListRef L); /* returns true is list is empty else returns false.*/
int  offEnd(BookListRef L); /* returns true is current == NULL*/
int  atFirst(BookListRef L); /* returns true if current == first and !offEnd()*/
int  atLast(BookListRef L); /* returns true if current == last and !offEnd()*/
long getFirst(BookListRef L); /* return the first element; pre: !isEmpty()*/
long getLast(BookListRef L); /* return the last element; pre: !isEmpty()*/
long getCurrent(BookListRef L); /* return the current element pre: !offEnd()*/
int  getLength(BookListRef L); /*return the length of the list*/
int  equals (BookListRef A, BookListRef B); /* return true iff the two lists have the same keys*/

/*** Manipulation procedures ***/
void makeEmpty(BookListRef L); /* make the list empty. Post: isEmpty()*/
void moveFirst(BookListRef L); /* set current marker to the first element in the list*/

/* Pre: !isEmpty(); Post: !offEnd()*/
void moveLast(BookListRef L); /* set current marker to the last element in the list
 Pre: !isEmpty(); Post: !offEnd()*/
void movePrev(BookListRef L); /* set current marker one step backward.
 Pre: !offEnd(); Post: offEnd() only if atFirst() was true*/
void moveNext(BookListRef L); /*set current marker one step forward.
 Pre: !offEnd(); Post: offEnd() only if atLast() was true*/
void insertBeforeFirst(BookListRef L, long data); /*Inserts new element before first
 Post: !isEmpty()*/
void insertAfterLast(BookListRef L, long data); /* Inserts new element after last one
 Post: !isEmpty()*/
void insertBeforeCurrent(BookListRef L, long data); /* Inserts new element before current one
 Pre: !offEnd(); Post: !isEmpty(), !offEnd()*/
void insertAfterCurrent(BookListRef L, long data); /* Inserts new element after current one
 Pre: !offEnd(); Post: !isEmpty(), !offEnd()*/
void deleteFirst(BookListRef L); /* delete the first element. Pre: !isEmpty()*/
void deleteLast(BookListRef L); /* delete the last element. Pre: !isEmpty()*/
void deleteCurrent(BookListRef L); /*delete the current element.
Pre: !isEmpty(), !offEnd(); Post: offEnd()*/


/*** Other operations ***/
void updateBookCount(BookListRef L, long book);
void printList(BookListRef L);
void insertionSort(BookListRef L);

int isEven(BookListRef L);
int bookExists(BookListRef L, long book);
int printBookCount(BookListRef L);
int getBookCount(BookListRef L, long bookID);

BookListRef copyList(BookListRef L);

#endif