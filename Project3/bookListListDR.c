#include "bookListList.h"

int main(int argc, char const *argv[])
{
	/* code */
	BookListRef L = newList();

	insertAfterLast(L,4343);
	insertAfterLast(L,32222);

	if(bookExists(L, 4343)) {
		printf("%s%d%s\n", "Book ", 4343, " exists.");
	} else {
		printf("%s%d%s\n", "Book ", 4343, " does not exists.");
	}

	if(bookExists(L, 22)) {
		printf("%s%d%s\n", "Book ", 22, " exists.");
	} else {
		printf("%s%d%s\n", "Book ", 22, " does not exists.");
	}
	return 0;
}