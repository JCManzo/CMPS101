#include <stdio.h>
#include <stdlib.h>
#include "bookCountList.h"


typedef struct Node {
	long data;				/*bookID*/
	int bookCount;			
	struct Node* next;
    struct Node* prev;
} Node;

/*NodeRef is a pointer to a Node structure */
typedef Node* NodeRef;

typedef struct List {
	/* data */
	NodeRef first;
	NodeRef last;
	NodeRef current;
	int length;
} List;

int isEven(BookListRef L){

	NodeRef node;

	node = L->first;
    while(node!=NULL && node->next!=NULL){
        node = node->next->next;
    }
    if(node==NULL) return 1;//even
    else return 0;
}

BookListRef newList(void){
	/*List constructor. Allocates memory to a new List.*/
	 BookListRef L;
        L = malloc(sizeof(List));
        L->first = L->last = NULL;
        L->current = NULL;
        L->length = 0;
        return L;
}

void freeList(BookListRef* pL) {
	/*Precondition: pL is not NULL
	  Postcondition: frees allocated to this list. Sets  pointer to NULL*/

	if(*pL == NULL) {
		/*List already free, no need to run the rest of our method.*/
		return;
	}

	while(!isEmpty(*pL)) {
		deleteFirst(*pL);
	}

}

NodeRef newNode(long data) {
	NodeRef node;
	node = malloc(sizeof(Node));
	node->next = node->prev = NULL;
	node->data = data;
	node->bookCount = 0;

	return(node);
}

void freeNode(NodeRef* pN) {
 if( pN!=NULL && *pN!=NULL ){
            free(*pN);
            *pN = NULL;
        }

}


void updateBookCount(BookListRef L, long x) {
	/*Post: updates the book x count if the book has been previously bought*/
	NodeRef node;
	for(node = L->first; node != NULL; node = node->next) {
		if(node->data == x){
			node->bookCount += 1;
		}
	}
}


int getBookCount(BookListRef L, long x) {
	/*Post: Returns the number of times customer bough book x */
	NodeRef node;

	    for(node = L->first; node != NULL; node = node->next) {
			if(node->data == x){
				return node->bookCount;
			}
		}
}

int printBookCount(BookListRef L) {
	NodeRef node;
	for(node = L->first; node != NULL; node = node->next) {
			
			printf("%s%ld%s%d ", "Book: ", node->data, " Count: " ,node->bookCount );
		}
}

int isEmpty(BookListRef L) {
	/*Returns true if List is empty, false otherwise. List is empty if length == 0
	  Precondition: L != NULL*/
	if (L==NULL) {
        printf( "Error: calling isEmpty() on NULL BookListRef\n");
        exit(1);
    }
    return L->length == 0;
}

int offEnd(BookListRef L) {
	/*Returns true if current if current is "off end"/ NULL
      Precondition: L != NULL*/

	if(L == NULL){
		printf("%s\n", "Error, calling offEnd() on NULL BookListRef\n");
		exit(1);
	}
	return(L->current == NULL);
}

int atFirst(BookListRef L) {
	/*Returns true if L->current == L->first
	  Precondition: !offEnd()*/	

	if(L == NULL) {
		printf("%s\n", "Error, calling atFirst() on NULL BookListRef\n" );
		exit(1);
	}

	if(offEnd(L)) {
		printf("%s\n", "Error, calling atFirst() on underfined current." );
	}
	return(L->current == L->first);
}

int atLast(BookListRef L) {
	/*Returns true if L->current == L->first
	  Precondition: !offEnd()*/	

	if(L == NULL) {
		printf("%s\n", "Error, calling atFirst() on NULL BookListRef\n" );
		exit(1);
	}

	if(offEnd(L)) {
		printf("%s\n", "Error, calling atFirst() on underfined current." );
	}
	return(L->current == L->last);
}


long getFirst(BookListRef L){
 /*Return the first element in a list.
   Precondition: !isEmpty()*/

	if(isEmpty(L)) {
		printf("%s\n","Error, calling getFirst() on an empty list." );
		exit(1);
	}
	return(L->first->data);
}	

long getLast(BookListRef L){
 /*Return the last element in a list.
   Precondition: !isEmpty()*/

	if(isEmpty(L)) {
		printf("%s\n","Error, calling getFirst() on an empty list." );
		exit(1);
	}
	return(L->last->data);
}	

long getCurrent(BookListRef L) {
 /*Return the current element.
   Precondition: !offEnd(), !isEmpty():*/
 	 if(isEmpty(L) ){
            printf("List error: getCurrent() was called on an empty list.");
            exit(1);
        }
 
 	if(offEnd(L) ){
            printf("List error: getCurrent() was called on an underfined element.");
            exit(1);
        }
        return (L->current->data);
}

int getLength(BookListRef L) {
	/* return the length of the list. */
if(L == NULL) {
		printf("%s\n", "Error, calling getLength() on NULL BookListRef\n" );
		exit(1);
	}
	return(L->length);
}

int equals (BookListRef A, BookListRef B) {
/*Return true iff the two lists have the same keys. Here we do this
  by checking each node in our lists and comparing ther "data"	*/

	NodeRef n1 = A->first;
	NodeRef n2 = B->first;

	if(getLength(A) == getLength(B)) {
		int flag = 1;
		/*First we check to see if both our lists are equal in lengths*/
		while(flag && n1 != NULL) {
			/*While flag continues to be true (the data elements in n1 and n2 are still equal
			  and n1 (we could have used n2 as well but once suffices) is not NULL then flag will be
			  assigned either true or false depending on the comparisons between the data fields of n1 and n2*/
			flag = (n1->data == n2->data);
			n1 = n1->next;
			n2 = n2->next;
		}
		return flag;
	} else {
		/*A and B are NOT equal. Return false*/
		return 0;
	}

}

/*** Manipulation procedures ***/

void makeEmpty(BookListRef L) {
/*Make the list empty.
  Pre: !isEmpty(), Post: isEmpty()*/
	if(isEmpty(L)) {
		printf("%s\n", "Error, calling makeEmpty() on an empty list." );
		exit(1);
	}
	while(!isEmpty(L)) {
		/*Traverses the list deleting the first element until there are no elements left.*/
		deleteFirst(L);
	}

}

void moveLast(BookListRef L)  {
/* set current marker to the last element in the list
   Pre: !isEmpty(); Post: !offEnd()*/
	if(isEmpty(L)) {
	printf("%s\n", "Error, calling moveLast() on empty list." );
	exit(1);
	}

	L->current = L->last;
}

void moveFirst(BookListRef L)  {
/* set current marker to the first element in the list
   Pre: !isEmpty(); Post: !offEnd()*/
	if(isEmpty(L)) {
	printf("%s\n", "Error, calling moveFirst() on empty list." );
	exit(1);
	}

	L->current = L->first;
}

void movePrev(BookListRef L) {
/* set current marker one step backward.
  Pre: !offEnd(); Post: offEnd() only if atFirst() was true*/
	if(offEnd(L)) {
		printf("%s\n", "Error, you called movePrev() but you are offEnd()" );
	}

	if(atFirst(L)) {
		L->current = NULL;
	} else {
		L->current = L->current->prev;
	}
}


void moveNext(BookListRef L) {
/* set current marker one step forward.
Pre: !offEnd(); Post: offEnd() only if atLast() was true*/
	
        if(isEmpty(L) && offEnd(L)){
            printf("List Error: calling moveNext() on NULL ListRef\n");
            exit(1);
        }

        if (L->current == L->last){
            L->current = NULL;

        }

        else   {L->current = L->current->next;  }
}

void insertBeforeFirst(BookListRef L, long data) {
/*Inserts new element before first
 Post: !isEmpty()*/
	NodeRef node = newNode(data);
	if(isEmpty(L)) {
		/*List is empty so just make first and last equal to the node*/
		L->last = node;
		L->first = node;
	} else {
		L->first->prev = node;
		node->next = L->first;
		L->first = node;
	}
	L->length++;
	node->bookCount += 1;
}

void insertAfterLast(BookListRef L, long data) {
/*Inserts new element after last
 Post: !isEmpty()*/
	NodeRef node = newNode(data);

        if( L==NULL ){
            printf("List Error: calling insertBack() on NULL BookListRef\n");
            exit(1);
        }
        if( isEmpty(L) ) { L->first =node; }
        else { L->last->next = node;  }

        node->prev = L->last;
        L->last = node;
	node->bookCount += 1;
        L->length++;
}

void insertBeforeCurrent(BookListRef L, long data) {
/*Inserts new element before current one
 Pre: !offEnd(); Post: !isEmpty(), !offEnd()*/
	  NodeRef node = newNode(data);

        if( L==NULL || isEmpty(L) || offEnd(L)){
            printf("List Error: calling insertBeforeCurrent() on NULL BookListRef\n or NULL current");
            exit(1);
        }
        node->next = L->current;
        node->prev = L->current->prev;

        if( L->current == L->first) {
            L->first = node;
        } else {
            L->current->prev->next = node;
        }
        L->current->prev = node;
        L->length++;
}

void insertAfterCurrent(BookListRef L, long data) {
/* Inserts new element before current one
 Pre: !offEnd(); Post: !isEmpty(), !offEnd()*/
	 NodeRef node = newNode(data);

        if( L==NULL || isEmpty(L) || offEnd(L)){
            printf("List Error: calling insertAfterCurrent() on NULL BookListRef\n or NULL current");
            exit(1);
        }
        node->prev = L->current;
        node->next = L->current->next;

        if(L->current == L->last){
            node->next = NULL;
            L->last = node;

        } else{
            node->next = L->current->next;
            L->current->next->prev  = node;
        }

        node->prev = L->current;
        L->current->next = node;
        L->length++;
}

void deleteFirst(BookListRef L) {
/* delete the first element. Pre: !isEmpty()*/
	
    NodeRef node = NULL;
		
	if(isEmpty(L)){
        printf("List Error:  deleteFirst() called on empty BookListRef\n");
        exit(1);
    }

    node = L->first;
    if(getLength(L)>1){
    	L->first = L->first->next;
    } else {
      	L->first = L->last = NULL;
    }

    L->length--;
    freeNode(&node);
}

void deleteLast(BookListRef L) {
/*delete the last element. Pre: !isEmpty()*/
	 NodeRef node = NULL;
   
        if(isEmpty(L)){
            printf("List Error: calling deleteLast() on empty BookListRef\n");
            exit(1);
        }
        if (L->current == L->first){
            L->current = NULL;
        }
        node = L->last;
        if(getLength(L) > 1){
            L->last = L->last->prev;
        }else {
            L->first = L->last = NULL;
        }

        L->length--;
        freeNode(&node);
    
}

void deleteCurrent(BookListRef L) {
/* delete the current element.
 Pre: !isEmpty(), !offEnd(); Post: offEnd()*/
	NodeRef node = NULL;
    if (isEmpty(L) || offEnd(L)){
		printf("List Error: calling deleteCurrent() on underfined current or empty list.\n");
        exit(1);
    }

    node = L->current;

    if (L->current == L->last){
        L->current = NULL;
    }
    if(getLength(L)==1){
        L->first = L->last = L->current = NULL;
    } else {
        L->current->prev->next = L->current->next;
        L->current->next->prev = L->current->prev;
        L->current = NULL;
    }

    L->length--;
    freeNode(&node);
}

BookListRef copyList(BookListRef L) {
	NodeRef node;
	BookListRef list = newList();
	long data_copy;
        for(node = L->first; node != NULL; node = node->next){
        	data_copy = node->data;
        	insertAfterLast(list, data_copy);
        }
        return list;

}

void printList(BookListRef L){

	Node* node = NULL;
    //insertionSort(L);
    
    for(node = L->first; node != NULL; node = node->next){
        printf("%ld/%d ", node->data, node->bookCount);
    }
        printf("\n");

        freeNode(&node);
}



void insertionSort(BookListRef L) {
	/*Pre:  Takes in unsorted List
	 *Post: Sorts book IDs in ascending order*/
    NodeRef node = NULL;
    NodeRef count = NULL;	/* "dummy node used to keep track where we are on the list
							 * relative to the front of the list.*/
	long temp, temp2;

  for(node = L->first->next; node != NULL; node = node->next) { 
    NodeRef key = node;
    count = key;

    while(count->prev != NULL && count->prev->bookCount > key->bookCount) {
      	/*Swap the data fields of our two nodes*/
      	temp = key->data;
      	temp2 = key->bookCount;
      	key->data = count->prev->data;
      	key->bookCount = count->prev->bookCount;
      	count->prev->bookCount = temp2;
      	count->prev->data = temp;
      	key = key->prev;

        count = count->prev;
    }
 }
}