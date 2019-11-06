/*
A very basic program that reads in a line from the user
and spits it right back out into the console until the
user enters Q or q.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "getline.h"

int main(){
    bool stop;
    int size = 20;
    char* line = malloc(sizeof (char*) * size);
    while(stop == false)
    {
        GetLine(line, size);
        printf("You entered: %s", line);
        if(!strcmp(line, "q\n") || !strcmp(line, "Q\n")){
            stop = true;
        }
    }
}

