#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMSECTOR 5
#define TAMMENU 10
#define TAMLISTA 100
#include "Empleados.h"



int main()
{

    eMenu menues[TAMMENU];
    eSector sector[TAMSECTOR];
    eEmpleado lista[TAMLISTA];
    int opcion;




    initMenu(menues, TAMMENU);
    initSector(sector,TAMSECTOR);
    inicializarEmpleados(lista,TAMLISTA);

    //initEmp(lista);


    do
    {


        printf("INGRESE UNA OPCION PARA COMENZAR\n");
        printf("  *** ABM Empleados ***\n\n");
        printf("1- Alta Empleado\n");
        printf("2- Listar Empleados\n");
        printf("3- Modificar Empleados\n");
        printf("4- Baja Empleados\n");
        printf("5- Ordenar Empleados\n");
        printf("6- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:

            altaEmpleado(lista,TAMLISTA,sector,TAMSECTOR);

            break;
        case 2:
            if(hayEmpleadosCargados(lista,TAMLISTA)==0)
            {
                system("cls");
                mostrarEmpleados(lista,TAMLISTA,sector,TAMSECTOR);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }
            break;
        case 3:
            if(hayEmpleadosCargados(lista,TAMLISTA)==0)
            {
                system("cls");
                modificarEmpleado(lista,TAMLISTA,sector,TAMSECTOR);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }
            break;
        case 4:
            if(hayEmpleadosCargados(lista,TAMLISTA)==0)
            {
                system("cls");
                bajaEmpleado(lista,TAMLISTA);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }
            break;
        case 5:
            if(hayEmpleadosCargados(lista,TAMLISTA)==0)
            {

                ordenarEmpleados(lista,TAMLISTA);
            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }
            break;
        case 6:
           printf("\nADIOS\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-6>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=6);



    return 0;
}

/*printf("\n\n");
printf("ID    DESCRIPCION    IMPORTE\n");
for(int i=0;i<TAMMENU;i++)
{
    printf("%2d   %8s        %.2f \n" , menu[i].codigoMenu , menu[i].descripcion , menu[i].Importe);
}*/

