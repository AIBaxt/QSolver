#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getit.h"

void input();

int main(int argc, char *argv[]){
    input();
}

void input(){
    char * buf = malloc(sizeof (char*) * 20);
    printf("Enter the values for a, b, and c:\n");
    fgets(buf, 20, stdin);
  //  scanf("%s", buf);
    getit(buf, strlen(buf));   
}