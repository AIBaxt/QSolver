CC = gcc
CFLAGS = -Wall -pedantic -std=c11

qs: qs.o getit.o validate.o
	${CC} qs.c getit.c validate.c -o qs

getit.o: getit.c getit.h
	${CC} ${CFLAGS} -c getit.c

validate.o: validate.c validate.h
	${CC} ${CFLAGS} -c validate.c

clean: 
	rm *.o qs