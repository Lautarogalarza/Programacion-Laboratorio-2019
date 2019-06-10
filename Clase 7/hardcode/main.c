#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct
{
    char nombre[20];
    int legajo;
    float sueldo;

}eEmpleado;


int main()
{

    eEmpleado lista[10];

    int legajos[10] = {234, 453, 112, 876, 543, 857, 322, 207, 765, 923};
    char nombres[10][30]={"Juana","Jose","Alberto","Sonia","Ana","Pedro","Sol","Juan","Felipe","Beatriz"};
    float sueldos[10] = { 23500.50, 34000, 45750, 23400, 13200, 28750, 32120, 21600, 29800.50, 55800};
    int i;


    for(i=0; i<10; i++)
    {
        lista[i].legajo=legajos[i];

        strcpy(lista[i].nombre, nombres[i]);

        lista[i].sueldo=sueldos[i];
    }


    printf(" Nombre   Legajo  Sueldo\n\n");

    for(int i=0; i < 10; i++)
    {

        printf("%10s   %d    %.2f\n", lista.nombre[i],lista.legajo[i],lista.sueldo[i]);
    }

    printf("\n\n");






    return 0;
}
