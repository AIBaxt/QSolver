#include "getit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int LOG; 

int getit(char * line, int nline){
	int error = 0; 
	int size = 0;

	if (fgets(line, nline, stdin) == NULL){
		error = 1; // no input, just an empty line
		if (LOG == 1) 
        printf("\nGETIT 13: NO INPUT IN LINE...\n");
	}
	else 
	{
		if (LOG == 1) 
        printf("\nGETIT 18: RECEIVED LINE OF INPUT...\n");
		size = strnlen(line, nline);
		if (size == nline && line[nline-1] != '\0') {
			error = 2; // didn't read the whole line, got cut off, so no null terminator
			if (LOG == 1) 
        		printf("\nGETIT 23: LINE LONGER THAN NLINE...\n");
		}
	} 
	return error;
}
