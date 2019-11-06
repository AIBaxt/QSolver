#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void compare(double x1, double x2);
void normCompare(double x1, double x2);
int dblcmp(double x1, double x2);


void main(){
    double f1 = 2.56;
    double f2 = 2.56;
    compare(f1, f2);
    f1 = 0.7;
    f2 = 0.7;
    compare(f1, f2);
    f1 = 0.15 + 0.15;
    f2 = 0.1 + 0.2f;
    compare(f1, f2);
    f1 = 0.1 + 0.1 + 0.1;
    f2 = 0.3;
    compare(f1, f2);
}

void compare(double x1, double x2){
    printf("Normal comparison: ");
    normCompare(x1, x2);
    printf("Epsilon comparison: ");
    dblcmp(x1, x2);
}

void normCompare(double x1, double x2){
    if(x1 == x2){
         printf("%f is equal to %f\n", x1, x2);
     }
     else{
         printf("%f is not equal to %f\n", x1, x2);
     }
}

int dblcmp(double x1, double x2){
     if(fabs(x1 - x2) < 0.00001){
         printf("%f is equal to %f\n", x1, x2);
     }
     else{
         printf("%f is not equal to %f\n", x1, x2);
     }
}