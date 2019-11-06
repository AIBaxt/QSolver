CC = gcc
CFLAGS = -Wall -pedantic -std=c11

bIO: bIO.o getline.o
	${CC} bIO.c getline.c -o bIO -lm

getline.o: getline.h getline.c
	${CC} ${CFLAGS} -c getline.c

clean:
	rm *.o qs