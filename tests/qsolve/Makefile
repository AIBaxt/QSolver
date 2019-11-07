CC = gcc
CFLAGS = -Wall -pedantic -std=c11
INC = -I../../src

main: main.o qstest.o 
	${CC} ${INC} main.c qstest.c -o test -lm

qtest.o: qstest.c qtsest.h
	${CC} ${CFLAGS} -c qstest.c
