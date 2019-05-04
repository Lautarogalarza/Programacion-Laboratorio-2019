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
    char seguir='s';
    char confirma;
    //int id;
    int flagEmp=0;



    initMenu(menues, TAMMENU);
    initSector(sector,TAMSECTOR);
    inicializarEmpleados(lista,TAMLISTA);

    //initEmp(lista);


    do
    {


        switch(menu())
        {
        case 1:

            //id=generarNextId();
            altaEmpleado(lista,TAMLISTA,sector,TAMSECTOR);
            flagEmp=1;
            system("pause");

            break;
        case 2:
            if(flagEmp==1)
            {

                mostrarEmpleados(lista,TAMLISTA,sector,TAMSECTOR);
                system("pause");

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");
                system("pause");
            }
            break;
        case 3:
            if(flagEmp==1)
            {
                modificarEmpleado(lista,TAMLISTA);

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");
                system("pause");
            }
            break;
        case 4:
            if(flagEmp==1)
            {

                bajaEmpleado(lista,TAMLISTA);

                if(hayEmpleadosCargados(lista,TAMLISTA)==0)
                {
                    flagEmp=0;
                }

            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");
                system("pause");
            }
            break;
        case 5:
            if(flagEmp==1)
            {

                ordenarEmpleados(lista,TAMLISTA);
            }
            else
            {
                printf("\nPor favor cargue un empleado antes de mostrar\n\n");
                system("pause");
            }
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
            system("pause");
            break;

        }

    }
    while(seguir == 's');



    return 0;
}

/*printf("\n\n");
printf("ID    DESCRIPCION    IMPORTE\n");
for(int i=0;i<TAMMENU;i++)
{
    printf("%2d   %8s        %.2f \n" , menu[i].codigoMenu , menu[i].descripcion , menu[i].Importe);
}*/

