#include <stdio.h>
#include <stdlib.h>
#include "../../src/validate.c"
#include "valtests.h"

FILE *file;

int main(){
    file = fopen("log.txt", "w");
    fprintf(file, "FILE: %s DATE: %s TIME: %s\n\n", __FILE__, __DATE__, __TIME__);

    double a = 0;
    double b = 0;
    double c = 0;
    //Empty asserts
    validate("hello", 20, &a, &b, &c);
    assert_empty(__LINE__, a);
    assert_empty(__LINE__, b);
    assert_empty(__LINE__, c);
    validate("gg2344", 20, &a, &b, &c);
    assert_empty(__LINE__, a);
    assert_empty(__LINE__, b);
    assert_empty(__LINE__, c);
    //This will get the first one but not the rest
    validate("1e1011hank300", 20, &a, &b, &c); 
    assert_empty(__LINE__, a);
    assert_empty(__LINE__, b);
    assert_empty(__LINE__, c);

    //NAN and INF asserts
    validate("NAN inf NAN", 20, &a, &b, &c);
    assert_eqnan(__LINE__, a);
    assert_inf(__LINE__, b);
    assert_eqnan(__LINE__, c);
    //Same as above but wrong order
    validate("NAN inf NAN", 20, &a, &b, &c);
    assert_eqnan(__LINE__, b);
    assert_inf(__LINE__, c);
    assert_eqnan(__LINE__, a);

    
    fclose(file);
}