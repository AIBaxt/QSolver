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
    if (argc == 2 && strcmp(argv[1], "log") == 0)
        LOG = 1;
    //setup for retrieving input
    int size = 20; //size isn't definite, not entirely sure what to set it to
    char *line = malloc (sizeof (char*) * size);
    double a, b, c;
    double x1, x2;
    int errFlag1 = 0; // 0 for all clear, 1 for no input, 2 for exit, 3 for help menu
    int errFlag2 = 0;
 
    if (LOG == 1) 
        printf("\nMAIN: ENTERING INITIALDISPLAY...\n");

    initialDisplay();

    if (LOG == 1)
        printf("\nMAIN: EXITING INITIALDISPLAY...\n");

    while(errFlag1 !=2)
    {
        if (LOG == 1)
        printf("\nMAIN: ENTERING LOOPDISPLAY...\n");

        loopDisplay();

        if (LOG == 1) 
        printf("\nMAIN: EXITING LOOPDISPLAY...\n");

        if (LOG == 1) 
        printf("\nMAIN: ENTERING GETIT...\n");

        getit(line, size);

        if (LOG == 1) 
        printf("\nMAIN: EXITING GETIT...\n");


        if (LOG == 1) 
        printf("\nMAIN: ENTERING VALIDATE...\n");

        errFlag1 = (validate(line, size, &a, &b, &c));

        if (LOG == 1) 
        printf("\nMAIN: EXITING VALIDATE...\n");

        if(errFlag1 !=0){
            if (LOG == 1) 
                printf("\nMAIN: ENTERING DISPLAYERRORS...\n");

            DisplayErrors(errFlag1);

            if (LOG == 1) 
                printf("\nMAIN: EXITING DISPLAYERRORS...\n");
        }
        else{
            if (LOG == 1) 
                printf("\nMAIN: ENTERING QSOLVE...\n");

            errFlag2 = qsolve(a,b,c,&x1,&x2);

            if (LOG == 1) 
                printf("\nMAIN: EXITING QSOLVE...\n");

            if (errFlag2 == 1){
                printf("Roots undefined: complex number\n");
            }
            else{
                if (LOG == 1) 
                    printf("\nMAIN: ENTERING EXITDISPLAY...\n");
                endDisplay(x1,x2);
                if (LOG == 1) 
                    printf("\nMAIN: EXITING EXITDISPLAY...\n");
            }
        }
    }
}