#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int validate(char * line, int nline, double * a, double * b, double * c){
 
	int error = 0;
	char checkForQ;
	char checkForHelp[100];

	
	if (sscanf(line, "%f %f %f", a, b, c) != 3) // did not receive 3 numbers
		error = 1;
	
	// if there is a character in the first place, check it for 'q' for quit
	if (sscanf(line, "%c", checkForQ) == 1) 
	{
		if (checkForQ == 'Q' || checkForQ == 'q')
			error = 2; // not technically an error, but easiest way to main to quit
	}
	
	// if there is a string, check it for 'help'
	if (sscanf(line, "%s", &checkForHelp) == 1)
	{
		if (strcasecmp(checkForHelp, "help") == 0)
			error = 3;  // again, easiest way
	}

	
	

	// error = 0 on all 3 numbers received, = 1 if trash line, = 2 on quit, = 3 on help
	return error;   
}
