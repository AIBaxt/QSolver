#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getline.h"

//This function reads in a line and stores it in the passed char * line
void GetLine(char * line, int nLine){
    printf("Enter string: ");
    fgets(line, nLine, stdin);
    line[strcspn(line, "\n")] = 0; //Removes the \n character
}

