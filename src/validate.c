#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

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


	if (error == 0) // I have all three numbers, no issues so far
	{
		if (*a > FLT_MAX || *a < -FLT_MAX || *b > FLT_MAX || *b < -FLT_MAX || *c > FLT_MAX || *c < -FLT_MAX)
			error = 4; // number not within FLT range

		if (isinf(*a) || isinf(*b) || isinf(*c))
			error = 5; // number is infinite

		if (isnan(*a) || isnan(*b) || isnan(*c))
			error = 6; // number is nan

		if (!(isnormal(*a) && isnormal(*b) && isnormal(*c)))
			error = 7; // number is subnormal/denormal

		if (*a == 0)
			error = 8; // a is 0, not a legitimite quadratic formula

	}

	

/* ERROR CODE DESCRIPTION:
1: Incorrect input
2,3: User Request
4-8: Error in numbers (specifications in code)
*/
	return error;
}
