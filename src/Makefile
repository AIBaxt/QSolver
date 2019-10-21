CC = gcc
CFLAGS = -Wall -pedantic -std=c11

qs: qs.o getit.o validate.o  displays.o qsolve.o
	${CC} qs.c getit.c validate.c displays.c qsolve.c -o qs -lm

getit.o: getit.c getit.h
	${CC} ${CFLAGS} -c getit.c

validate.o: validate.c validate.h
	${CC} ${CFLAGS} -c validate.c

displays.o: displays.c displays.h
	${CC} ${CFLAGS} -c displays.c

qsolve.o: qsolve.c qsolve.h
	${CC} ${CFLAGS} -c qsolve.c

clean: 
	rm *.o qs