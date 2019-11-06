#include <math.h>
#include <stdio.h>

extern int LOG;

int qsolve(double a, double b, double c, double * x1, double * x2)
{
    int error = 0;
    double possibleTemp = 0;

    double insideSQRT = pow(b, 2) - (4*a*c);
    if (LOG == 1) 
        printf("\nQSOLVE 12: INSIDESQRT = %f...\n", insideSQRT);

    if (insideSQRT < 0) 
        error = 1; // number is negative, sqrt(negative) is complex
    else
    {
        *x1 = ((-1)*b + sqrt(insideSQRT)) / (2*a);
        *x2 = ((-1)*b - sqrt(insideSQRT)) / (2*a);
        if (LOG == 1) 
            printf("\nQSOLVE 21: X1 = %f, X2 = %f...\n", *x1, *x2);

        if (x1 > x2)
        {
            if (LOG == 1) 
                printf("\nQSOLVE 26: X1 AND X2 SWITCHED SPOTS...\n");
            possibleTemp = *x1;
            *x1 = *x2;
            *x2 = possibleTemp;
        }
    }
    
    
//ERROR DESCRIPTION
//1: Complex Number Due to SQRT of negative 

    return error; 
}