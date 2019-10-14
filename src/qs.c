#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"
#include "validate.h"

void displayHelp();

int main(int argc, char *argv[]){
    //setup for retrieving input
    int size = 20; //size isn't definite, not entirely sure what to set it to
    char *line = malloc (sizeof (char*) * size);
    double a, b, c;
    int errFlag = 0; // 0 for all clear, 1 for no input, 2 for exit, 3 for help menu

    printf("Quadratic Equation Solver\n");
    printf("Q to quit, H for help, or enter your three values.\n");
    
    while(errFlag!=2)
    {
        printf("Input: ");
        getit(line, size);
        errFlag = (validate(line, size, &a, &b, &c));
        if(errFlag == 3)
        {
           displayHelp();
        }
    }
}


void displayHelp(){
//Here we would display example input and output to the user.
}
