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
    struct datosPersonales vecAgenda[3], vecContactos[3], vecAmigos[3];
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

   for(i=0; i<3; i++){

       strcpy(vecContactos[i].nombre,vecAgenda[i].nombre);
       strcpy(vecContactos[i].apellido,vecAgenda[i].apellido);
       strcpy(vecContactos[i].calle,vecAgenda[i].calle);
       vecContactos[i].numero=vecAgenda[i].numero;
       printf("\n Nombre %d Copiado %s ",i, vecContactos[i].nombre);
       printf("\n Apellido %d Copiado %s ",i, vecContactos[i].apellido );
       printf("\n Calle %d Copiado %s ",i, vecContactos[i].calle);
       printf("\n Numero %d Copiado %d ",i, vecContactos[i].numero);


   }

    for(i=0; i<3; i++)
    {
        vecAmigos[i]=vecContactos[i];

        printf("\n Nombre %d Copiado %s ",i, vecAmigos[i].nombre);
        printf("\n Apellido %d Copiado %s ",i, vecAmigos[i].apellido );
        printf("\n Calle %d Copiado %s ",i, vecAmigos[i].calle);
        printf("\n Numero %d Copiado %d ",i, vecAmigos[i].numero);
    }

   //mostrar
    /*for(i=0; i<3; i++)
    {
        printf("\nNombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido );
        printf("\nCalle: %s ", vecAgenda[i].calle);
        printf("\nNumero: %d ", vecAgenda[i].numero);
    }*/

    return 0;
}
