#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "qstest.h"

extern FILE *file;

void dblcmp(int line, double x1, double realx1){
    if(!(fabs(x1 - realx1) < 0.00001)){
       // printf("%f is not equal to %f\n",x1, realx1);
       fprintf(file, "LINE %d: %f is not equal to %f\n", line, x1, realx1);
    }
}

void nantest(int line, double x1){
    if(!isnan(x1)){
        fprintf(file, "LINE %d: %f is not NAN", line, x1);
    }
}

void inftest(int line, double x1){
    if(!isinf(x1)){
        fprintf(file, "LINE %d: %f is not INF", line, x1);
    }
}