#include <stdio.h>
#include <stdlib.h>
#include "../../src/qsolve.c"
#include "qstest.h"

#define DATA_SIZE 1000
FILE *file;

int main(){
   // FILE *file;
    file = fopen("log.txt", "w");
    fprintf(file, "FILE: %s DATE: %s: TIME: %s\n\n", __FILE__, __DATE__, __TIME__);
    double x1; 
    double x2;
    
    //Successes
    qsolve(2, 5, -3, &x1, &x2);
    dblcmp(__LINE__, x1, 0.5);
    dblcmp(__LINE__, x2, -3);

    qsolve(1, -1, -3, &x1, &x2);
    dblcmp(__LINE__, x1, 2.302776);
    dblcmp(__LINE__, x2, -1.302776);

    qsolve(12, -9.6, 1.44, &x1, &x2);
    dblcmp(__LINE__, x1, 0.6);
    dblcmp(__LINE__, x2, 0.2);

    //Failures
    qsolve(2, 5, -3, &x1, &x2);
    dblcmp(__LINE__, x1, 0.8);
    dblcmp(__LINE__, x2, -1);

    qsolve(1, -1, -3, &x1, &x2);
    dblcmp(__LINE__, x1, 2.302576);
    dblcmp(__LINE__, x2, -1.302716);

    qsolve(12, -9.6, 1.44, &x1, &x2);
    dblcmp(__LINE__, x1, 0.6555);
    dblcmp(__LINE__, x2, 0.19);

    //NAN
}
