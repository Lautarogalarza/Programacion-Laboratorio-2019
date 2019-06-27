#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Function.h"

int main()
{
    int option;
    float numberOne;
    float numberTwo;
    float additionResult;
    float subtractionResult;
    float multiplicationResult;
    float divisionResult;
    long int factorialResultA;
    long int factorialResultB;
    int flag1=0;
    int flag2=0;
    int flag3=0;

    do
    {
        printf("==========================================\n");
        printf("POR FAVOR INGRESE 2 NUMEROS PARA COMENZAR\n");
        printf("==========================================\n");


        if(flag1==1)
        {
            printf("\n(1) Ingrese el 1er operando (A)= %.2f",numberOne);
        }
        else
        {
            printf("\n(1) Ingrese el 1er operando (A)");
        }


        if(flag2==1)
        {
            printf("\n(2) Ingrese el 2do operando (B)= %.2f",numberTwo);
        }
        else
        {
            printf("\n(2) Ingrese el 2do operando (B)");
        }

        printf("\n(3) Calcular");
        printf("\n(4) Mostrar Resultados");
        printf("\n(5) Salir");

        printf("\n\nElija una opcion:");
        scanf("%d",&option);

        switch(option)
        {
        case 1:

            askNumber(&numberOne);
            flag1=1;

            break;
        case 2:

            askNumber(&numberTwo);
            flag2=1;

            break;
        case 3:
            if(flag1==1 && flag2==1)
            {
                additionResult=Addition(numberOne, numberTwo);
                subtractionResult=Substraction(numberOne, numberTwo);
                multiplicationResult=multiplication(numberOne, numberTwo);
                divisionResult=division(numberOne, numberTwo);
                factorialResultA=factorial(numberOne);
                factorialResultB=factorial(numberTwo);

                printf("\nSE REALIZARON TODAS LAS OPERACIONES POSIBLES\n\n");

                flag3=1;
            }
            else
            {
                printf("\nERROR...Ingrese dos operandos para calcular\n\n");
            }
            break;
        case 4:

            if(flag1==1 && flag2==1 && flag3==1)
            {
                printf("\nAl realizar el factorial solo se tomo en cuenta la parte entera del numero\n\n");

                printf("EL resultado de %.2f + %.2f es: %.2f\n", numberOne, numberTwo, additionResult);
                printf("EL resultado de %.2f - %.2f es: %.2f\n", numberOne, numberTwo, subtractionResult);
                printf("EL resultado de %.2f * %.2f es: %.2f\n", numberOne, numberTwo, multiplicationResult);

                if(numberTwo!=0)
                {

                    printf("EL resultado de %.2f / %.2f es: %.2f\n", numberOne, numberTwo, divisionResult);

                }
                else
                {

                    printf("ERROR...No se puede dividir un numero por 0\n");
                }


                if(numberOne<=0)
                {



                    printf("ERROR...No existe el factorial de numeros negativos\n");
                }
                else
                {

                    printf("EL factorial de %d es: %ld\n", (int)numberOne, factorialResultA);
                }



                if(numberTwo<=0)
                {



                    printf("ERROR...No existe el factorial de numeros negativos\n\n");
                }
                else
                {

                    printf("EL factorial de %d es: %ld\n", (int)numberTwo, factorialResultB);
                }


            }
            else if(flag1==1 && flag2==1 && flag3==0)
            {

                printf("\nERROR...No se pueden ver los resultados si no fueron calculados\n\n");
            }
            else
            {

                printf("\nERROR...Ingrese dos operandos para calcular\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("ERROR...Por favor ingrese una opcion valida <1-5>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=5);

    printf("=================================\n");
    printf("Gracias por usar la calculadora!!\n");
    printf("=================================\n");

    return 0;
}
