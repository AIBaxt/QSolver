#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

extern int LOG;

int CheckPrecision(char *line);
int PrecisionCounter(char line[]);

int validate(char * line, int nline, double * a, double * b, double * c){
	int error = 0;
	//A toupper function would be nice here
	if(strncmp(line, "q", 1) == 0 || strncmp(line, "Q", 1) == 0){
		error = 2; //User is requesting to exit
		if (LOG == 1) 
        printf("\nVALIDATE 18: RECEIVED 'Q'...\n");
	}
	else if(strncmp(line, "h", 1) == 0 || strncmp(line, "H", 1) == 0){
		error = 3; //User is requesting help menu
		if (LOG == 1) 
        printf("\nVALIDATE 23: RECEIVED 'H'...\n");
	}
	else if(sscanf(line, "%lf %lf %lf", a, b, c) != 3){
		error = 1; // Either no input or did not receive all 3 numbers
		if (LOG == 1) 
        printf("\nVALIDATE 28: RECEIVED INCORRECT INPUT...\n");
	}
	
	
	if (error == 0) // I have all three numbers, no issues so far
	{
		if (LOG == 1) 
        printf("\nVALIDATE 35: ERROR = 0, ALL GOOD [%f, %f, %f]...\n", *a, *b, *c);
		if (*a > FLT_MAX || *a < -FLT_MAX || *b > FLT_MAX || *b < -FLT_MAX || *c > FLT_MAX || *c < -FLT_MAX)
			error = 4; // number not within FLT range

		if (isinf(*a) || isinf(*b) || isinf(*c))
			error = 5; // number is infinite

		if (isnan(*a) || isnan(*b) || isnan(*c))
			error = 6; // number is nan

		if (!((isnormal(*a) || *a == 0) && (isnormal(*b) || *b == 0) && (isnormal(*c) || *c == 0)))
			error = 7; // number is subnormal/denormal

		if (*a == 0)
			error = 8; // a is 0, not a legitimite quadratic formula

		if (CheckPrecision(line) == 1)
			printf("\nWARNING: More than 4 digits.  Answers may not be as accurate due to rounding errors.\n\n");
		if (LOG == 1) 
        printf("\nVALIDATE 54: INPUT ERROR RECEIVED, 4-8...\n");
	}

	

/* ERROR CODE DESCRIPTION:
1: Incorrect input
2,3: User Request
4-9: Error in numbers (specifications in code)
*/
	return error;
}

//Separates the 3 digits into indivdual strings after successful validation
//returns 1 if PrecisionCounter counts > 4 digits
int CheckPrecision(char *line){
	int flag = 0;
	char checkA[20], checkB[20], checkC[20];
	sscanf(line, "%s %s %s", checkA, checkB, checkC);
	flag = PrecisionCounter(checkA);
	if (flag == 0) // no point checking if flag is already 1
		flag = PrecisionCounter(checkB);
	if (flag == 0)
		flag = PrecisionCounter(checkC);

	return flag;
}
//Counts each individual character after the "." and returns 1 if count > 4
int PrecisionCounter(char line[]){
	int flag = 0;
	int count = 0;
	int zeroCount = 0;

	for (int a = 0; a < strlen(line); a++)
	{
		if (!(count == 0 && line[a] == '0')){ // ignore initial zeroes, not important to count
			if (line[a] >= 48 && line[a] <= 57){ // if 0-9
				count++;
				if (line[a] == '0') // counts zeroes to ensure only precision numbers matter
					zeroCount++;
				else
					zeroCount = 0; // resets to zero if the zeroes in line affected precision
				
			}
		}

		if (line[a] == 'e' || line[a] == 'E') //the numbers after should not affect this
			a = strlen(line); 
	}

	count = count - zeroCount; // deducts unnecessary zeroes counted from end of line

	if (count > 4)
		flag = 1;

	return flag;
}