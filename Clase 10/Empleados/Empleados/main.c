#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#define TAM 2
#include "empleado.h"



int main()
{
int flag=0;
char seguir = 's';
    char confirma;
    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM);


    do
    {
        switch(menu())
        {

        case 1:
            //printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            system("pause");
            flag=1;
            break;

        case 2:
            if(flag==1)
            {

            printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM);
            }
            else
            {
                printf("Cague un empleado");

            }
            system("pause");
            break;

        case 3:

            if(flag==1)
            {

             printf("\nModificacion empleado\n\n");
            modificarEmpleado(lista,TAM);
            }
            else
            {
                printf("Cague un empleado");

            }
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}
