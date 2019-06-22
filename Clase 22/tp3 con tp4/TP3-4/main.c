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
                printf("\n Empleados cargados correctamente (modo texto).\n\n");
            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }

            break;
        case 2:

            if(controller_loadFromBinary("data.bin",listaEmpleados)==1)
            {
                printf("\n Empleados cargados correctamente (modo binario).\n\n");
            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }
            break;
        case 3:

            if(controller_addEmployee(listaEmpleados)==1)
            {
                printf("\n Empleado cargado correctamente.\n\n");
            }

            else
            {
                printf("\n\nERROR...No se pudo dar de alta al empleado\n\n");
            }

            break;
        case 4:

            if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_editEmployee(listaEmpleados)==1)
                {
                    printf("\nSe pudo acceder a la modificacion.\n\n");
                }

                else
                {
                    printf("\n\nERROR...No se pudo modificar al empleado\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de modificar\n");
            }

            break;
        case 5:

            if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_removeEmployee(listaEmpleados)==1)
                {
                    printf("\nSe pudo acceder a la baja.\n\n");
                }

                else
                {
                    printf("\n\nERROR...No se pudo borrar al empleado\n\n");
                }



            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de borrar\n");
            }
            break;
        case 6:

            if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_ListEmployee(listaEmpleados)==1)
                {
                    printf("\n Empleados listados correctamente.\n\n");
                }

                else
                {
                    printf("\n\nERROR...No se pudieron listar a los empleados\n\n");
                }


            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de listar\n");
            }

            break;
        case 7:

            if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_sortEmployee(listaEmpleados)==0)
                {
                    printf("\nEmpleados ordenados correctamente.\n\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudieron ordenar los empleados\n\n");
                }



            }

            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de ordenar\n");
            }

            break;
        case 8:

            if(controller_listExist(listaEmpleados)==1)


            {

                if(controller_saveAsText("data.csv",listaEmpleados)==1)
                {

                    printf("\n Empleados guardados correctamente (modo texto).\n\n");

                }


                else
                {
                    printf("\n\nERROR...No se pudo guardar el archivo\n\n");
                }



            }

            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de guardar\n");
            }

            break;
        case 9:

            if(controller_listExist(listaEmpleados)==1)

            {
                if(controller_saveAsBinary("data.bin",listaEmpleados)==1)
                {
                    printf("\n Empleados guardados correctamente (modo binario).\n\n");
                }

                else
                {
                    printf("\n\nERROR...No se pudo guardar el archivo\n\n");
                }


            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de guardar\n");
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
