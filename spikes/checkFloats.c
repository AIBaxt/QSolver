#include <float.h>
#include <math.h>
#include <stdio.h>

void main()
{
    float test1 = 0;
    double test2 = 0;
    float test3 = 0;


    // TEST 1: INEQUALITY
    test1 = .25;
    test2 = .25;

    if (test1 == test2)
        printf("Test 1.1: %f = %f\n", test1, test2);
    else
        printf("Test 1.1: %f != %f\n", test1, test2);

    test1 = .1;
    test2 = .1;
    
    if (test1 == test2)
        printf("Test 1.2: %f = %f\n", test1, test2);
    else
        printf("Test 1.2: %f != %f\n", test1, test2);

    

    //TEST 2: ISNAN
    test1 = 0;
    test2 = 0;
    test3 = test1/test2;

    if (isnan(test1))
        printf("Test 2.1: it = nan\n");
    else
    {
        printf("Test 2.1: %f != nan\n", test1);
    }
    if (isnan(test3))
        printf("Test 2.2: it = nan\n");
    else
    {
        printf("Test 2.2: %f != nan\n", test3);
    }



    //TEST 3: ISINF

    test1 = FLT_MAX;
    test3 = FLT_MAX;
    test3 *= 2;
    
    if (isinf(test1))
        printf("Test 3.1: it = inf\n");
    else
    {
        printf("Test 3.1: %f != inf\n", test1);
    }
    if (isinf(test3))
        printf("Test 3.2: it = inf\n");
    else
    {
        printf("Test 3.2: %f != inf\n", test3);
    }


    //TEST 4: ISNORMAL

    test1 = 1.5;
    test3 = 0.00015;

    if (isnormal(test1))
        printf("Test 4.1: %f = normal\n", test1);
    else
    {
        printf("Test 4.1: %f != normal\n", test1);
    }
    if (isnormal(test2))
        printf("Test 4.2: %f = normal\n", test3);
    else
    {
        printf("Test 4.2: %f != normal\n", test3);
    }
}