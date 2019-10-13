#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"

void input();

int main(int argc, char *argv[]){
    //setup for retrieving input
    int size = 20; //size isn't definite, not entirely sure what to set it to
    char *line = malloc (sizeof (char*) * size);
    printf("Quadratic Equation Solver\n");
    do{
        printf("Enter three roots separated by spaces or type q to exit: ");
        getit(line, size);
    }while(strncmp(line, "q", 1) != 0); //while first character of line is not q
}
