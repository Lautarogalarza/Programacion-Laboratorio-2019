#include <stdio.h>
#include <stdlib.h>
#include "Function.h"
#include <ctype.h>

void askNumber( float* Pnum )
{
    printf("\nIngrese un numero: ");
    fflush(stdin);
    scanf("%f",Pnum);
}


float Addition( float numA, float numB )
{
    float additionResult;

    additionResult= numA + numB;

    return additionResult;
}

float Substraction( float numA, float numB)
{
    float subtractionResult;

    subtractionResult= numA - numB;

    return subtractionResult;
}

float multiplication( float numA, float numB)
{
    float multiplicationResult;

    multiplicationResult= numA * numB;

    return multiplicationResult;
}

float division( float numA, float numB)
{
    float divisionResult;

    divisionResult= numA / numB;

    return divisionResult;
}
int factorial(float num)
{
    long int resultadoFactorial=1;
    int i;

    for (i=(int)num;i>=1;i--)
    {
        resultadoFactorial = resultadoFactorial * i;
    }

    return resultadoFactorial;
}
