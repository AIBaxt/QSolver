#include <stdio.h>
#include <stdlib.h>
#include "../../src/qsolve.c"

int main(){
    double x1; 
    double x2;
    qsolve(1, 3, 1, &x1, &x2);
    printf("%f, %f", x1, x2);
}
