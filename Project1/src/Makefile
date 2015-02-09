# Julio Franco - Spring 2014
all : Listdr store

Listdr : Listdr.o List.o
	gcc -o Listdr Listdr.o List.o

Listdr.o : Listdr.c List.h
	gcc -c Listdr.c

List.o : List.h List.c
	gcc -c List.c

store : store.o List.o
	gcc -o store store.o List.o

store.o : store.c List.h
	gcc -c store.c

clean :
	rm -f store Listdr store.o Listdr.o List.o