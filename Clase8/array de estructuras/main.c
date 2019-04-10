#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct datosPersonales{

    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
};
int main()
{
   struct datosPersonales vecAgenda[3];
   int i;

   ////////////////////CARGO DATOS//////////////////
   for(i=0; i<3; i++){

        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].numero);
        fflush(stdin);

   }

   for(i=0; i<3; i++)
   {
       printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].numero);
        fflush(stdin);


   }

    return 0;
}
