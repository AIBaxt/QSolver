#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"
#include "validate.h"
#include "displays.h"
#include "qsolve.h"

FILE *file;

int main(int argc, char *argv[]){
    //File creation
    file = fopen("log.txt", "w");
    fprintf(file, "FILE: %s DATE: %s TIME: %s\n", __FILE__, __DATE__, __TIME__);
    //getline creation
    int size = 20; 
    char *line = malloc (sizeof (char*) * size);
    double a, b, c; //Doubles received from user input
    double x1, x2; //Roots
    int errFlag1 = 0; // 0 for all clear, 1 for no input, 2 for exit, 3 for help menu
    int errFlag2 = 0;
    int count = 1;

    initialDisplay();

    while(errFlag1 !=2)
    {   
        fprintf(file, "\nIteration: %d\n", count);
        loopDisplay();

        getit(line, size);
        fprintf(file, "Input: %s", line);
        errFlag1 = (validate(line, size, &a, &b, &c));

        if(errFlag1 !=0){

            DisplayErrors(errFlag1);
        }
        else{
            errFlag2 = qsolve(a,b,c,&x1,&x2);

            if (errFlag2 == 1){
                printf("Roots undefined: complex number\n");
                fprintf(file, "Roots undefined: complex number\n");
            }
            else{
                endDisplay(x1,x2);
            }
        }
        count++;
    }
}