#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

//binario es .bin no csv
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option ;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        printf("///////////////BIENVENIDOS////////////////\n");
        printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2.Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
        printf("3.Alta de empleado\n");
        printf("4.Modificar datos de empleado");
        printf("5.Baja de empleado\n");
        printf("6.Listar empleados\n");
        printf("7.Ordenar empleados\n");
        printf("8.Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9.Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("10.Salir\n");
        printf("\nPor favor ingrese una opcion <1-10> :");
        fflush(stdin);
        scanf("%d",&option);

        switch(option)
        {
        case 1:

            controller_loadFromText("data.csv",listaEmpleados);

            break;
        case 2:
             controller_loadFromBinary("data1.bin",listaEmpleados);
            break;
        case 3:

                controller_addEmployee(listaEmpleados);

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            controller_ListEmployee(listaEmpleados);

            break;
        case 7:

            break;
        case 8:

            controller_saveAsText("data.csv",listaEmpleados);

            break;
        case 9:

            controller_saveAsBinary("data1.bin",listaEmpleados);

            break;
        case 10:

            break;
        default:
            printf("ERROR...Ingrese una opcion correcta <1-10>");
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
