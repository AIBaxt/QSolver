#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"

void input();

int main(int argc, char *argv[]){
    int size = 20;
    char *line = malloc (sizeof (char*) * size);
    getit(line, size);
}
