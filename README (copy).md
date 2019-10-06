CC = gcc
CFLAGS = -Wall -pedantic -std=c11

qs: qs.o validate.o getit.o
	gcc -o qsolver qs.c validate.c getit.c

qs.o: src/qs.c src/validate.o src/getit.o
	gcc -o qs.c

validate.o: header/validate.h
	gcc -o validate.c

getit.o: header/getit.h
	gcc -o getit.c

clean:
	rm *.o qsolver
