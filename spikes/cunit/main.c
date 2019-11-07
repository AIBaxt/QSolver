#include <stdlib.h>
#include <stdio.h>
#include "cunit.h"

#define DATA_SIZE 1000

int main(){
    char data[DATA_SIZE];
    FILE * fPtr;
    fPtr = fopen("file1.txt", "w");
    cunit_date();
    assertd_eq(&fPtr, "s", 5, 6);
    assertd_eq(&fPtr, "s", 3, 6);
    fclose(fPtr);
}