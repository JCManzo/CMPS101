/*
 * ListTest.c
 *
 *  Created on: May 21, 2013
 *      Author: Juan Manzo
 */
#include <stdio.h>
#include "List.h"

int main(int argc, char* argv[])
{
    ListRef A = newList();
    ListRef B = newList();


    insertBeforeFirst(A, 22);
    insertBeforeFirst(A, 11);
    insertBeforeFirst(A, 55);
    insertBeforeFirst(B, 22);
    insertAfterLast(A,535);
    deleteCurrent(A);
    moveFirst(A);
    int x;
    x = getCurrent(A);
    printf("%d", x);
    moveNext(A);
    moveNext(A);
    insertBeforeCurrent(A,222);
    insertBeforeFirst(B, 55);

    insertBeforeCurrent(A, 98);
    int y;
    y = getCurrent(A);

    printf("%d\n", y );

    moveNext(B);
    deleteFirst(B);
    moveFirst(B);
    insertBeforeCurrent(B,12);
    int z;
    z = getCurrent(A);
    printf("%d\n", z );

    int le;
    le = getLength(A);
    printf("%d\n", le);

    ListRef myCopy = copyList(A);
    makeEmpty(myCopy);
    return(0);
}
