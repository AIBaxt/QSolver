#include "getit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getit(char * line, int nline){
	int error = 0; 
	int size = 0;

	if (fgets(line, nline, stdin) == NULL){
		error = 1; // no input, just an empty line
	}
	else 
	{
		size = strnlen(line, nline);
		if (size == nline && line[nline-1] != '\0') {
			error = 2; // didn't read the whole line, got cut off, so no null terminator
		}
	} 
	return error;
}
