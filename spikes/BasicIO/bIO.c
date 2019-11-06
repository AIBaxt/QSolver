/*
A very basic program that reads in a line from the user
and spits it right back out into the console.
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
        if(strncmp(line, "q", 3) == 0 || strncmp(line, "Q", 3) == 0){
            stop = true;
        }
    }
}

