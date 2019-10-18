#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"
#include "validate.h"
#include "qsolve.h"
#include "initialDisplay.h"
#include "loopDisplay.h"
#include "endDisplay.h"

void displayHelp();

int main(int argc, char *argv[]){
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

        if(errFlag1 == 3)
        {
           displayHelp();
        }
        else if (errFlag1 == 1)
        {
            printf("ERROR: No command or a, b, and c in line received\n");
        }
        else if (errFlag1 == 4)
        {
            printf("ERROR: A, B, or C were not within the range of Float type\n");
        }
        else if (errFlag1 == 5)
        {
            printf("ERROR: A, B, or C was infinite\n");
        }
        else if (errFlag1 == 6)
        {
            printf("ERROR: A, B, or C was nan\n");
        }
        else if (errFlag1 == 7)
        {
            printf("ERROR: A, B, or C was subnormal\n");
        }
        else if (errFlag1 == 8)
        {
            printf("ERROR: A was 0, not quadratic equation\n");
        }
        else if (errFlag1 == 0)
        {
            errFlag2 = qsolve(a,b,c,&x1,&x2);

            if (errFlag2 == 1)
                printf("Roots undefined: complex number\n");
            else
            {
                endDisplay(x1,x2);
            }
            
        }
    }
}


void displayHelp(){
//Here we would display example input and output to the user.
}
