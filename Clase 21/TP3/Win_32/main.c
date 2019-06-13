#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();


    do
    {
        printf("///////////////BIENVENIDOS////////////////\n\n");
        printf("\n1.Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2.Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
        printf("3.Alta de empleado\n");
        printf("4.Modificar datos de empleado\n");
        printf("5.Baja de empleado\n");
        printf("6.Listar empleados\n");
        printf("7.Ordenar empleados\n");
        printf("8.Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("9.Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
        printf("10.Salir\n");
        printf("\nPor favor ingrese una opcion <1-10> :");
        fflush(stdin);
        scanf("%d",&option);

        switch(option)
        {
        case 1:

            if(controller_loadFromText("data.csv",listaEmpleados)==1)
            {

            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }

            break;
        case 2:




            if(controller_loadFromBinary("data.bin",listaEmpleados)==1)
            {

            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }
            break;
        case 3:



           if(controller_addEmployee(listaEmpleados)==1)
            {

            }

            else
            {
                printf("\n\nERROR...No se pudo dar de alta al empleado\n\n");
            }

            break;
        case 4:



            if(controller_editEmployee(listaEmpleados)==1)
            {

            }

            else
            {
                printf("\n\nERROR...No se pudo modificar al empleado\n\n");
            }
            break;
        case 5:


            if(controller_removeEmployee(listaEmpleados)==1)
            {

            }

            else
            {
                printf("\n\nERROR...No se pudo borrar al empleado\n\n");
            }
            break;
        case 6:


            if(controller_ListEmployee(listaEmpleados)==1)
            {

            }

            else
            {
                printf("\n\nERROR...No se pudieron listar a los empleados\n\n");
            }

            break;
        case 7:

            controller_sortEmployee(listaEmpleados);

            break;
        case 8:

            if(controller_saveAsText("data.csv",listaEmpleados)==1)
            {

            }


            else
            {
                printf("\n\nERROR...No se pudo guardar el archivo\n\n");
            }

            break;
        case 9:


          if(controller_saveAsBinary("data.bin",listaEmpleados)==1)
            {

            }

            else
            {
                printf("\n\nERROR...No se pudo guardar el archivo\n\n");
            }

            break;
        case 10:
            printf("\n\nSALIENDO DEL PROGRAMA!!!\n\n");
            break;
        default:
            printf("\n\nERROR...Ingrese una opcion correcta <1-10>\n\n");
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
