CC = gcc
CFLAGS = -wall -pedantic -std=c11

qs: qs.o validate.o getit.o
qs.o: qs.c getit.h validate.h
getit.o: getit.c getit.h
validate.o: validate.c validate.h
