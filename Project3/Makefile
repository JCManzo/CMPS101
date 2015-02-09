all: main bookCountListDR HashDR bookListListDR


main: main.o HashTable.o bookListList.o bookCountList.o 
	gcc -o main main.o HashTable.o bookListList.o  bookCountList.o

HashDR: HashDR.o bookListList.o bookCountList.o HashTable.o
	gcc -o HashDR HashDR.o bookListList.o bookCountList.o HashTable.o

main.o: main.c HashTable.h bookCountList.h bookListList.h
	gcc -c main.c

HashDR.o: HashDR.c HashTable.h 
	gcc -c HashDR.c

bookListListDR: bookListListDR.o bookListList.o bookCountList.o
	gcc -o bookListListDR bookListListDR.o bookCountList.o bookListList.o 

bookListListDR.o: bookListListDR.c bookListList.h 
	gcc -c bookListListDR.c

bookCountListDR: bookCountListDR.o bookCountList.o
	gcc -o bookCountListDR bookCountListDR.o bookCountList.o

bookCountListDR.o: bookCountListDR.c bookCountList.h
	gcc -c bookCountListDR.c

HashTable.o: HashTable.c bookListList.h bookCountList.h
	gcc -c HashTable.c

bookListList.o: bookListList.c bookCountList.h
	gcc -c bookListList.c

bookCountList.o: bookCountList.c bookCountList.h
	gcc -c bookCountList.c

clean:
	rm -f main bookCountListDR HashDR main.o bookCountListDR.o HashDR.o bookCountList.o bookListList.o HashTable.o