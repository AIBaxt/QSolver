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
    qsolve(0, 1, -1, &x1, &x2);
    nantest(__LINE__, x1);
    inftest(__LINE__, x2);

    qsolve(0, 5, 4, &x1, &x2);
    nantest(__LINE__, x1);
    inftest(__LINE__, x2);


    //more checks, should pass
    qsolve(4.63, 28.11, 4.1, &x1, &x2);
    dblcmp(__LINE__, x2, -5.9217355089063);
    dblcmp(__LINE__, x1, -0.14953878914983);

    qsolve(3e27, 6e33, 5e26, &x1, &x2);
    dblcmp(__LINE__, x2, -1999999.9999999);
    dblcmp(__LINE__, x1, -8.3202501915794e-8);

}
