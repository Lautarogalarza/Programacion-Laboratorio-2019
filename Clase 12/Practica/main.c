#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAMSECTOR 5
#define TAMMENU 10
#define TAMLISTA 5
#include "Empleados.h"



int main()
{

    eMenu menues[TAMMENU];
    eSector sector[TAMSECTOR];
    eEmpleado lista[TAMLISTA];
    char seguir='s';
    char confirma;
    int id=1;



    initMenu(menues, TAMMENU);
    initSector(sector,TAMSECTOR);
    inicializarEmpleados(lista,TAMLISTA);

    do
    {

        switch(menu())
        {
        case 1:
            altaEmpleado(lista,TAMLISTA,sector,TAMSECTOR,id);
            id++;
            system("pause");
            break;
        case 2:
            mostrarEmpleados(lista,TAMLISTA,sector,TAMSECTOR);
            system("pause");
            break;
        case 3:
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
}

printf("\n\n");
printf("ID    DESCRIPCION  \n");
for(int i=0;i<TAMSECTOR;i++)
{
    printf("%2d   %8s   \n" , sector[i].id , sector[i].descripcion);
}*/
