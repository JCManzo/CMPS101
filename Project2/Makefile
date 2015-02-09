all : heapDriver sortComp sortPrint

heapDriver : heapDriver.o Heap.o heapSort.o insertionSort.o
	gcc -o heapDriver heapDriver.o Heap.o heapSort.o insertionSort.o

heapDriver.o : heapDriver.c heapSort.h insertionSort.h
	gcc -c heapDriver.c

Heap.o : Heap.h Heap.c
	gcc -c Heap.c

heapSort.o : heapSort.c heapSort.h Heap.h
	gcc -c heapSort.c

insertionSort.o : insertionSort.c insertionSort.h
	gcc -c insertionSort.c

sortComp : sortComp.o Heap.o heapSort.o insertionSort.o
	gcc -o sortComp sortComp.o Heap.o heapSort.o insertionSort.o

sortComp.o : sortComp.c heapSort.h insertionSort.h
	gcc -c sortComp.c

sortPrint : sortPrint.o Heap.o heapSort.o insertionSort.o
	gcc -o sortPrint sortPrint.o Heap.o heapSort.o insertionSort.o

sortPrint.o : sortPrint.c heapSort.h insertionSort.h Heap.h
	gcc -c sortPrint.c

clean :
	rm -f heapDriver sortPrint sortComp heapDriver.o heapSort.o Heap.o insertionSort.o sortPrint.o sortComp.o