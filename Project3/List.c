/**
 * Author: Julio Franco
 * Implemention of List ADT.
 *
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "List.h"


typedef struct NodeStruct {
	long data;
	struct NodeStruct* next;
    struct NodeStruct* prev;
} NodeStruct;

/*NodeStructRef is a pointer to a NodeStruct structure */
typedef NodeStruct* NodeStructRef;

typedef struct ListStruct {
	/* data */
	NodeStructRef first;
	NodeStructRef last;
	NodeStructRef current;
	int length;
} ListStruct;

ListHndl newList(void){
	/*ListStruct constructor. Allocates memory to a new ListStruct.*/
	 ListHndl L = malloc(sizeof(ListStruct));
        L->first = L->last = L->current = NULL;
        L->length = 0;
        return L;
}

void freeList(ListHndl* L) {
	/*Precondition: L is not NULL
	  Postcondition: frees allocated to this ListStruct. Sets  pointer to NULL*/

	 if(L == NULL ) {
        return;
         }
        while(!isEmpty(*L)) {
            deleteFirst(*L);
        }
         free(*L);
        *L = NULL;

}

NodeStructRef newNodeStruct(long data) {
	NodeStructRef NodeStruct = malloc(sizeof(NodeStruct));
      assert (NodeStruct != NULL);
	NodeStruct->next = NodeStruct->prev = NULL;
	NodeStruct->data = data;

	return(NodeStruct);
}

void freeNodeStruct(NodeStructRef* pN) {
 if( pN!=NULL && *pN!=NULL ){
            free(*pN);
            *pN = NULL;
        }

}
int isEmpty(ListHndl L) {
	/*Returns true if ListStruct is empty, false otherwise. ListStruct is empty if length == 0
	  Precondition: L != NULL*/
	if(L == NULL) {
		printf("%s\n", "Error, calling isEmpty() on NULL ListHndl\n" );
	}
	return(L->length == 0);
}

int  offEnd(ListHndl L) {
	/*Returns true if current if current is "off end"/ NULL
      Precondition: L != NULL*/

	if(L == NULL){
		printf("%s\n", "Error, calling offEnd() on NULL ListHndl\n");
	}
	return(L->current == NULL);
}

int  atFirst(ListHndl L) {
	/*Returns true if L->current == L->first
	  Precondition: !offEnd()*/

	if(L == NULL) {
		printf("%s\n", "Error, calling atFirst() on NULL ListHndl\n" );
	}

	if(isEmpty(L)) {
		printf("%s\n", "Error, calling atFirst() on underfined current." );
	}
	return(L->current == L->first);
}

int atLast(ListHndl L) {
	/*Returns true if L->current == L->first
	  Precondition: !offEnd()*/

	if(L == NULL) {
		printf("%s\n", "Error, calling atFirst() on NULL ListHndl\n" );
	}

	if(isEmpty(L)) {
		printf("%s\n", "Error, calling atFirst() on underfined current." );
	}
	return(L->current == L->last);
}

long getFirst(ListHndl L){
 /*Return the first element in a ListStruct.
   Precondition: !isEmpty()*/

	if(isEmpty(L)) {
		printf("%s\n","Error, calling getFirst() on an empty ListStruct." );
	}
	return(L->first->data);
}

long getLast(ListHndl L){
 /*Return the last element in a ListStruct.
   Precondition: !isEmpty()*/

	if(isEmpty(L)) {
		printf("%s\n","Error, calling getFirst() on an empty ListStruct." );
	}
	return(L->last->data);
}

long getCurrent(ListHndl L) {
 /*Return the current element.
   Precondition: !offEnd(), !isEmpty():*/
 	if(offEnd(L) || isEmpty(L)) {
 		printf("%s\n", "Error, calling getCurrent() on undefined element or empty ListStruct.");
 	}
 	return(L->current->data);
}

int  getLength(ListHndl L) {
	/* return the length of the ListStruct. */
      if(L == NULL) {
          printf("%s\n", "Error, calling getLength() on NULL ListHndl\n" );
      }
	return(L->length);
}


/*** Manipulation procedures ***/

void makeEmpty(ListHndl L) {
/*Make the ListStruct empty.
  Pre: !isEmpty(), Post: isEmpty()*/
	if(isEmpty(L)) {
		printf("%s\n", "Error, calling makeEmpty() on an empty ListStruct." );
	}
	while(!isEmpty(L)) {
		/*Traverses the ListStruct deleting the first element until there are no elements left.*/
		deleteFirst(L);
	}

}

void moveLast(ListHndl L)  {
/* set current marker to the last element in the ListStruct
   Pre: !isEmpty(); Post: !offEnd()*/
	if(isEmpty(L)) {
	printf("%s\n", "Error, calling moveLast() on empty ListStruct." );
	}

	L->current = L->last;
}

void moveFirst(ListHndl L)  {
/* set current marker to the first element in the ListStruct
   Pre: !isEmpty(); Post: !offEnd()*/
	if(isEmpty(L)) {
	printf("%s\n", "Error, calling moveFirst() on empty ListStruct." );
	exit(1);
	}

	L->current = L->first;
}

void movePrev(ListHndl L) {
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


void moveNext(ListHndl L) {
/* set current marker one step forward.
Pre: !offEnd(); Post: offEnd() only if atLast() was true*/
	if(offEnd(L)) {
		printf("%s\n", "Error, you called movePrev() but you are offEnd()" );
	}

	if(atLast(L)) {
		L->current = NULL;
	} else {
		L->current = L->current->next;
	}
}

void insertAtFront(ListHndl L, long data) {
/*Inserts new element before first
 Post: !isEmpty()*/
	NodeStructRef NodeStruct = newNodeStruct(data);
	if(isEmpty(L)) {
		/*ListStruct is empty so just make first and last equal to the NodeStruct*/
		L->last = NodeStruct;
		L->first = NodeStruct;
	} else {
		L->first->prev = NodeStruct;
		NodeStruct->next = L->first;
		L->first = NodeStruct;
	}
	L->length++;
}

void insertAtBack(ListHndl L, long data) {
/*Inserts new element after last
 Post: !isEmpty()*/
	NodeStructRef NodeStruct = newNodeStruct(data);
	if(isEmpty(L)) {
		/*ListStruct is empty so just make first and last equal to the NodeStruct*/
		L->last = NodeStruct;
		L->first = NodeStruct;
	} else {
		L->last->next = NodeStruct;
		NodeStruct->prev = L->last;
		L->last = NodeStruct;
	}
	L->length++;
}

void insertBeforeCurrent(ListHndl L, long data) {
/*Inserts new element before current one
 Pre: !offEnd(); Post: !isEmpty(), !offEnd()*/
	  NodeStructRef NodeStruct = newNodeStruct(data);

        if( L==NULL || isEmpty(L) || offEnd(L)){
            printf("ListStruct Error: calling insertBeforeCurrent() on NULL ListHndl\n or NULL current");
        }

        if( L->current == L->first) {
            insertAtFront(L, data);
        } else {
            NodeStruct->next = L->current;
            NodeStruct->prev = L->current->prev;
            NodeStruct->prev->next = NodeStruct;
            NodeStruct->next->prev = NodeStruct;
            L->length++;
        }
}

void insertAfterCurrent(ListHndl L, long data) {
/* Inserts new element before current one
 Pre: !offEnd(); Post: !isEmpty(), !offEnd()*/
	 NodeStructRef NodeStruct = newNodeStruct(data);

        if( L==NULL || isEmpty(L) || offEnd(L)){
            printf("ListStruct Error: calling insertAfterCurrent() on NULL ListHndl\n or NULL current");
        }

        if(L->current == L->last){
            insertAtBack(L, data);
        } else{
            NodeStruct->next = L->current->next;
            NodeStruct->prev = L->current;
            L->current->next = NodeStruct;
            NodeStruct->next->prev = NodeStruct;
            L->length++;
        }
}

void deleteFirst(ListHndl L) {
/* delete the first element. Pre: !isEmpty()*/

    NodeStructRef NodeStruct = NULL;

	if(isEmpty(L)){
        printf("ListStruct Error:  deleteFirst() called on empty ListHndl\n");
    }

    if(atFirst(L)) {
        L->current = NULL;
    }

    if(L->length == 1) {
      freeNodeStruct(&(L->first));
      L->first = L->last = NULL;
    } else {
          NodeStruct = L->first;
          L->first->next->prev = NULL;
          L->first = L->first->next;
          NodeStruct->next = NULL;
          freeNodeStruct(&NodeStruct);
          NodeStruct = NULL;
    }
    L->length--;
}

void deleteLast(ListHndl L) {
/*delete the last element. Pre: !isEmpty()*/
	 NodeStructRef NodeStruct = NULL;

        if(isEmpty(L)){
            printf("ListStruct Error: calling deleteLast() on empty ListHndl\n");
            exit(1);
        }
        if(atLast(L)) {
        L->current = NULL;
    }

    if(L->length == 1) {
      freeNodeStruct(&(L->first));
      L->first = L->last = NULL;
    } else {
          NodeStruct = L->last;
          L->last = NodeStruct->prev;
          NodeStruct->prev->next = NULL;
          NodeStruct->prev = NULL;
          freeNodeStruct(&NodeStruct);
          NodeStruct = NULL;
    }

        L->length--;

}

void deleteCurrent(ListHndl L) {
/* delete the current element.
 Pre: !isEmpty(), !offEnd(); Post: offEnd()*/
	NodeStructRef NodeStruct = NULL;
    if (isEmpty(L) || offEnd(L)){
		printf("ListStruct Error: calling deleteCurrent() on underfined current or empty ListStruct.\n");
        exit(1);
    }

    if (L->current == L->last){
        deleteLast(L);
    } else if(L->current == L->first) {
        deleteFirst(L);
    } else {
       if (L->current->next != NULL) {
      L->current->next->prev = L->current->prev;
  }
      if (L->current->prev != NULL) {
          L->current->prev->next = L->current->next;
      }
      L->current->next = NULL;
      L->current->prev =NULL;
      freeNodeStruct(&(L->current));
    }

    L->length--;
}

ListHndl copyListStruct(ListHndl L) {
	NodeStructRef NodeStruct;
	ListHndl ListStruct = newList();
	long data_copy;
        for(NodeStruct = L->first; NodeStruct != NULL; NodeStruct = NodeStruct->next){
        	data_copy = NodeStruct->data;
        	insertAtBack(ListStruct, data_copy);
        }
        return ListStruct;

}

void printList(FILE* out,ListHndl L){
    NodeStructRef NodeStruct = L->first;

    if (L == NULL) {
        printf( "Error: ListHndl is underfined\n");
    }

    while (NodeStruct != NULL) {
        fprintf(out, "%ld ", NodeStruct->data);
        NodeStruct = NodeStruct->next;
    }

    fprintf(out, "\n");
}