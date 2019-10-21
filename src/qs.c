#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"
#include "validate.h"
#include "qsolve.h"
#include "initialDisplay.h"
#include "loopDisplay.h"
#include "endDisplay.h"

void DisplayHelp();
void DisplayErrors(int errFlag);

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

void DisplayErrors(int errFlag1){
    switch (errFlag1){
        case 1:
            printf("ERROR: No command or a, b, and c in line received\n");
            break;
        case 3:
            DisplayHelp();
            break;
        case 4:
            printf("ERROR: A, B, or C were not within the range of Float type\n");
            break;
        case 5:
            printf("ERROR: A, B, or C was infinite\n");
            break;
        case 6:
            printf("ERROR: A, B, or C was nan\n");
            break;
        case 7:
            printf("ERROR: A, B, or C was subnormal\n");
            break;
        case 8:
            printf("ERROR: A was 0, not quadratic equation\n");
            break;    
    }
}

void DisplayHelp(){
    double x1, x2;
    printf("\nInputs are entered as 3 floats separated by spaces.\n");
    printf("Example input: 1 4 2");
    qsolve(1.0 , 4.2 , 2.0, &x1, &x2);
    endDisplay(x1,x2);
}

