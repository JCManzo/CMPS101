/*Keeps track of boook-list pairs.*/

#include "bookListList.h"

int bookExists(BookListRef L, long bookID) {
	/*Post: returns true if the customer has bought book x and it's
     *already stored in their purchase history list Lc*/

	if(!isEmpty(L) ) {
		for(moveFirst(L); !offEnd(L); moveNext(L)) {
			int x = getCurrent(L);
			if(x == bookID){
				
			return 1;
			}
		}
	}
    /*Book has not been inserted previously. */
    return 0;
}


