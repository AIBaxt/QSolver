#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int validate(char * line, int nline, double * a, double * b, double * c){
	int error = 0;
	//A toupper function would be nice here
	if(strncmp(line, "q", 1) == 0 || strncmp(line, "Q", 1) == 0){
		error = 2; //User is requesting to exit
	}
	else if(strncmp(line, "h", 1) == 0 || strncmp(line, "H", 1) == 0){
		error = 3; //User is requesting help menu
	}
	else if(sscanf(line, "%lf %lf %lf", a, b, c) != 3){
		error = 1; // Either no input or did not receive all 3 numbers
	}

	return error;
}
