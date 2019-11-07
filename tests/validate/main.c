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
    int error = 0;
    
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

    
    //random checks below, should all pass
    error = validate("1 2 1", 20, &a, &b, &c);
    assert_INTequal(46, 0, error);

    error = validate("inf 2 1", 20, &a, &b, &c);
    assert_INTequal(49, 4, error); // this proved that isinf() is redundant

    error = validate("0 2 1", 20, &a, &b, &c);
    assert_INTequal(52, 8, error);

    error = validate("NAN 2 1", 20, &a, &b, &c);
    assert_INTequal(55, 6, error);

    error = validate("1e-38 2 1", 20, &a, &b, &c);
    assert_INTequal(58, 7, error);

    error = validate("9e38 2 1", 20, &a, &b, &c);
    assert_INTequal(61, 4, error);

    error = validate("9e36 2 1", 20, &a, &b, &c);
    assert_INTequal(64, 0, error);

    error = validate("skribblez", 20, &a, &b, &c);
    assert_INTequal(67, 1, error);

    error = validate("skribblez 1 2 1", 20, &a, &b, &c);
    assert_INTequal(70, 1, error);

    error = validate("h\n", 20, &a, &b, &c);
    assert_INTequal(73, 3, error);

    error = validate("q\n", 20, &a, &b, &c);
    assert_INTequal(76, 2, error);

    fclose(file);
}