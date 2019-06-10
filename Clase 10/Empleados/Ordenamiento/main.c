
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    char nombre[20];
    float sueldo;
    int legajo;

}eEmpleado;

int main()
{
    eEmpleado lista[10];
    eEmpleado aux;

    int i;
    int j;

    int legajos[10] = {234, 453, 112, 876, 543, 857, 322, 207, 765, 923};
    char nombres[10][30]={"Juana","Jose","Alberto","Sonia","Ana","Pedro","Sol","Juan","Felipe","Beatriz"};
    float sueldos[10] = { 23500.50, 34000, 45750, 23400, 13200, 28750, 32120, 21600, 29800.50, 55800};


    for(i=0;i<10;i++)
   {

        lista[i].legajo=legajos[i];

        strcpy(lista[i].nombre, nombres[i]);

        lista[i].sueldo=sueldos[i];
    }


   printf("Legajo  nombre   sueldo\n");

    for(i=0;i<10;i++)
    {
        printf("\n %d  %s   %.2f", lista[i].legajo,lista[i].nombre,lista[i].sueldo);


    }

    printf("\n\nORDENADOS POR SUELDO\n\n");

     for(i=0; i < 10 -1; i++)
    {
        for( j= i + 1; j < 10; j++)
        {
            if( lista[i].sueldo > lista[j].sueldo)
            {


                 aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;

            }


        }
    }

    printf("Legajo  nombre    sueldo\n");

    for(i=0;i<10;i++)
    {
        printf("\n %d  %s     %5.2f", lista[i].legajo,lista[i].nombre,lista[i].sueldo);


    }

    for(i=0; i < 10 -1; i++)
    {
        for( j= i + 1; j < 10; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {

                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;


            }

        }


    }

    printf("\n\nORDENADOS POR NOMBRE\n\n");

    printf("Legajo  nombre    sueldo\n");

    for(i=0;i<10;i++)
    {
        printf("\n %d  %s     %.2f", lista[i].legajo,lista[i].nombre,lista[i].sueldo);

    }

    return 0;

}
