#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void compare(float x1, float x2);
void normCompare(float x1, float x2);
int floatcmp(float x1, float x2);


void main(){
    float f1 = 2.56f;
    float f2 = 2.56f;
    compare(f1, f2);
    f1 = 0.7f;
    f2 = 0.7f;
    compare(f1, f2);
    f1 = 0.15f + 0.15f;
    f2 = 0.1f + 0.2f;
    compare(f1, f2);
    f1 = 0.1f + 0.1f + 0.1f;
    f2 = 0.3f;
    compare(f1, f2);
}

void compare(float x1, float x2){
    printf("Normal comparison: ");
    normCompare(x1, x2);
    printf("Epsilon comparison: ");
    floatcmp(x1, x2);
}

void normCompare(float x1, float x2){
    if(x1 == x2){
         printf("%f is equal to %f\n", x1, x2);
     }
     else{
         printf("%f is not equal to %f\n", x1, x2);
     }
}

int floatcmp(float x1, float x2){
     if(fabs(x1 - x2) < 0.00001){
         printf("%f is equal to %f\n", x1, x2);
     }
     else{
         printf("%f is not equal to %f\n", x1, x2);
     }
}