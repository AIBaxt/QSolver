#include "getit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getit(char * line, int nline){
    char * token = strtok(line, " ");
    double qNums[3];
    int i = 0;
    while(token !=NULL){
        qNums[i] = atof(token);
        token = strtok(NULL, " ");
        i++;
    }
}
