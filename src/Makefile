CC = gcc
CFLAGS = -Wall -pedantic -std=c11

qs: qs.o getit.o validate.o endDisplay.o initialDisplay.o loopDisplay.o qsolve.o
	${CC} qs.c getit.c validate.c initialDisplay.c loopDisplay.c endDisplay.c qsolve.c -o qs -lm

getit.o: getit.c getit.h
	${CC} ${CFLAGS} -c getit.c

validate.o: validate.c validate.h
	${CC} ${CFLAGS} -c validate.c

endDisplay.o: endDisplay.c endDisplay.h
	${CC} ${CFLAGS} -c endDisplay.c

initialDisplay.o: initialDisplay.c initialDisplay.h
	${CC} ${CFLAGS} -c initialDisplay.c

loopDisplay.o: loopDisplay.c loopDisplay.h
	${CC} ${CFLAGS} -c loopDisplay.c

qsolve.o: qsolve.c qsolve.h
	${CC} ${CFLAGS} -c qsolve.c

clean: 
	rm *.o qs