#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bookCountList.h"

int main(int argc, char const *argv[])
{
	/* code */
  BookListRef custArray[2];
  custArray[1] = newList();
  custArray[2] = newList();

	
  insertAfterLast(custArray[1], 343);
  insertAfterLast(custArray[1], 9888);

  moveFirst(custArray[1]);
  long x = getCurrent(custArray[1]);
  printf("%s%ld\n", "Current: ", x);

  moveLast(custArray[1]);
     x = getCurrent(custArray[1]);

    printf("%s%ld\n", "Current: ", x);

	return 0;
}