/**
 * Author: Julio Franco
 *  List ADT header. Includes function prototypes.
 */
#include <stdio.h>

typedef struct ListStruct * ListHndl;

/*** Constructors-Destructors ***/
ListHndl newList(void);
void freeList(ListHndl* L);

/* NOTE:  all Access functions and Manipulation procedures also have the
   precondition that L has been initialized by newList().
   */

/*** Access functions ***/
int  isEmpty(ListHndl L); // returns true is list is empty else returns false.
int  offEnd(ListHndl L); /* returns true is current == NULL*/
int  atFirst(ListHndl L); /* returns true if current == first and !offEnd()*/
int  atLast(ListHndl L); /* returns true if current == last and !offEnd()*/
long getFirst(ListHndl L); /* return the first element; pre: !isEmpty()*/
long getLast(ListHndl L); /* return the last element; pre: !isEmpty()*/
long getCurrent(ListHndl L); /* return the current element pre: !offEnd()*/

/*** Manipulation procedures ***/
void makeEmpty(ListHndl L); /* make the ListStruct empty. Post: isEmpty()*/
void moveFirst(ListHndl L); /* set current marker to the first element in the ListStruct*/
void moveLast(ListHndl L); /* set current marker to the last element in the ListStruct**/
void movePrev(ListHndl L); /* set current marker one step backward.**/
void moveNext(ListHndl L); /*set current marker one step forward**/
void insertAtFront(ListHndl L, long data); /*Inserts new element before first**/
void insertAtBack(ListHndl L, long data); /* Inserts new element after last one**/
void insertBeforeCurrent(ListHndl L, long data); /* Inserts new element before current one**/
void insertAfterCurrent(ListHndl L, long data); /* Inserts new element after current one**/
void deleteFirst(ListHndl L); /* delete the first element. Pre: !isEmpty()*/
void deleteLast(ListHndl L); /* delete the last element. Pre: !isEmpty()*/
void deleteCurrent(ListHndl L); /*delete the current element.**/

/*** Other operations ***/
void printList(FILE* out, ListHndl L);
