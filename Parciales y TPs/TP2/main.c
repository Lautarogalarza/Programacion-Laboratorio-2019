#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define ELEMENTS 1000

int main()
{

    Employee arrayEmployees[ELEMENTS];
    int option;
    char auxName[51] ;
    char auxLastName[51] ;
    int auxSector;
    float auxSalary;
    int auxId;

    initEmployees(arrayEmployees,ELEMENTS);

    do
    {

        printf("INGRESE UNA OPCION PARA COMENZAR\n");
        printf("\n1.Alta\n");
        printf("2.Modificar\n");
        printf("3.Baja\n");
        printf("4.Informar\n");
        printf("5.Mostrar\n");
        printf("6.Salir\n");
        printf("\nElija una opcion:" );
        fflush(stdin);

        scanf("%d", &option);

        switch(option)
        {

        case 1:

            fflush(stdin);
            getValidString("Ingrese nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",auxName,1,51);
            stringToUpper(auxName);

            fflush(stdin);
            getValidString("Ingrese apellido :","ERROR, ingrese apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",auxLastName,1,51);
            stringToUpper(auxLastName);

            fflush(stdin);
            getValidFloat("Ingrese salario :","ERROR ingrese salario nuevamente (solo numeros)",0,1000000,&auxSalary);

            fflush(stdin);
            getValidInt("Ingrese sector :","ERROR ingrese sector nuevamente <1-10>",1,10,&auxSector);

            auxId=generateNextId();
            addEmployee(arrayEmployees,ELEMENTS,auxId,auxName,auxLastName,auxSalary,auxSector);
            break;
        case 2:
            if(employeeExist(arrayEmployees,ELEMENTS)==0)
            {

                system("cls");
                modifyEmployee(arrayEmployees,ELEMENTS);

            }
            else
            {
                printf("ERROR, Por favor cargue un empleado en el sistema\n\n");
            }
            break;
        case 3:
            if(employeeExist(arrayEmployees,ELEMENTS)==0)
            {

                system("cls");
                removeEmployee(arrayEmployees,ELEMENTS);

            }
            else
            {
                printf("ERROR, Por favor cargue un empleado en el sistema\n\n");
            }
            break;
        case 4:
            if(employeeExist(arrayEmployees,ELEMENTS)==0)
            {

                menuReport(arrayEmployees,ELEMENTS);

            }
            else
            {
                printf("ERROR, Por favor cargue un empleado en el sistema\n\n");
            }
            break;
        case 5:
            if(employeeExist(arrayEmployees,ELEMENTS)==0)
            {
                system("cls");
                printEmployees(arrayEmployees,ELEMENTS);

            }
            else
            {
                printf("ERROR, Por favor cargue un empleado en el sistema\n\n");
            }
            break;
        case 6:
            printf("\nPROGRAMA FINALIZADO\n");
             break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-6>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=6);


    return 0;
}
