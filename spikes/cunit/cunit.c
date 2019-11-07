#include <stdlib.h>
#include <stdio.h>
#include "cunit.h"

void cunit_date(FILE **file){
    //fprintf(*file, "DATE: %s TIME: %s\n", __DATE__, __TIME__);
}

void assertd_eq(FILE **file, char* str, int a, int b){
    if(a!=b){
       // printf("%d does not equal %d\n", a, b);
       fprintf(*file, "%s LINE %d: %d does not equal %d\n", __FILE__, __LINE__, a, b);
    }
}

void assertd_neq(FILE **file, char* str, int a, int b){
    if(a = b){
       // printf("%d equals %d\n", a, b);
       fprintf(*file, "%d equals %d\n", a, b);
    }
}