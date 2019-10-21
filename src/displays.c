#include <stdio.h>
#include "qsolve.h"

void initialDisplay()
{
    printf("*****************************\n");
    printf("       JKK Consulting      \n");
    printf("         QUADSOLVER          \n");
    printf("            v0.9             \n");
    printf("*****************************\n");
    printf("Q to Quit, H for help");
    printf("\n");

}

void loopDisplay()
{
    printf("\nInput: ");
}

void endDisplay(double x1, double x2)
{
    printf("\nThe roots are: [%e], [%e]\n", x1, x2);
}

void DisplayHelp(){
    double x1, x2;
    printf("\nInputs are entered as 3 floats separated by spaces.\n");
    printf("Example input: 1 4 2");
    qsolve(1.0 , 4.2 , 2.0, &x1, &x2);
    endDisplay(x1,x2);
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