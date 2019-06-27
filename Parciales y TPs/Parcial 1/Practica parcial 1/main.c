#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMSECTOR 5
#define TAMMENU 10
#define TAMALMUERZO 10
#define TAMLISTA 100
#include "Empleados.h"



int main()
{

    eMenu menues[TAMMENU];
    eSector sector[TAMSECTOR];
    eEmpleado lista[TAMLISTA];
    eAlmuerzo almuerzos[TAMALMUERZO];
    int opcion;




    initMenu(menues, TAMMENU);
    initSector(sector,TAMSECTOR);
    initAlmuerzo(almuerzos,TAMALMUERZO);
    inicializar_Empleados(lista,TAMLISTA);

    init_Emp(lista);


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


            mostrarSectoresConEmpleados(lista,TAMLISTA,sector,TAMSECTOR);

            break;
        case 2:
            if(hay_Empleados_Cargados(lista,TAMLISTA)==0)
            {
                system("cls");
                mostrar_Empleados(lista,TAMLISTA,sector,TAMSECTOR);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }

            break;
        case 3:
            if(hay_Empleados_Cargados(lista,TAMLISTA)==0)
            {
                system("cls");
                modificar_Empleado(lista,TAMLISTA,sector,TAMSECTOR);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }
            break;
        case 4:
            if(hay_Empleados_Cargados(lista,TAMLISTA)==0)
            {
                system("cls");
                baja_Empleado(lista,TAMLISTA);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");

            }
            break;
        case 5:
            if(hay_Empleados_Cargados(lista,TAMLISTA)==0)
            {

                ordenar_Empleados(lista,TAMLISTA);
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

