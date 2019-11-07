#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"
#include "validate.h"
#include "displays.h"
#include "qsolve.h"

int LOG = 0;

int main(int argc, char *argv[]){
    //LOGGING
    //setup for retrieving input
    int size = 20; //size isn't definite, not entirely sure what to set it to
    char *line = malloc (sizeof (char*) * size);
    double a, b, c;
    double x1, x2;
    int errFlag1 = 0; // 0 for all clear, 1 for no input, 2 for exit, 3 for help menu
    int errFlag2 = 0;

    initialDisplay();

    while(errFlag1 !=2)
    {
        loopDisplay();

        getit(line, size);
        errFlag1 = (validate(line, size, &a, &b, &c));


        if(errFlag1 !=0){

            DisplayErrors(errFlag1);
        }
        else{
            errFlag2 = qsolve(a,b,c,&x1,&x2);

            if (errFlag2 == 1){
                printf("Roots undefined: complex number\n");
            }
            else{
                endDisplay(x1,x2);
            }
        }
    }
}