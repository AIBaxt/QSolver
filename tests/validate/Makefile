CC = gcc
CFLAGS = -Wall -pedantic -std=c11
INC = -I../../src

main: main.o valtests.o
	${CC} ${CFLAGS} main.c valtests.c -o test -lm

valtests.o: valtests.c valtests.h
	${CC} ${CFLAGS} -c valtests.c