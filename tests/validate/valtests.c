#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "valtests.h"

extern FILE *file;

void assert_empty(int line, double x){
    if(x!=0){
        fprintf(file, "LINE %d: x is not empty\n", line);
    }
}

void assert_inf(int line, double x){
   if(!(isinf(x))){
        fprintf(file, "LINE %d: x is not INF\n", line);
    }
}

void assert_notinf(int line, double x){
    if(isinf(x)){
        fprintf(file, "LINE %d: x is INF\n", line);
    }
}

void assert_eqnan(int line, double x){
    if(!(isnan(x))){
        fprintf(file, "LINE %d: x is not NAN\n", line);
    }
}

void assert_INTequal(int line, int a, int b)
{
    if (a != b)
        fprintf(file, "LINE %d: %d != %d\n", line, a, b);
}