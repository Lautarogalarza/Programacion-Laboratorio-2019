#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicion de estructura
struct datosPersonales
{
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
    int codigoPostal;

};
int main()
{
    //declaro la variable agenda de tipo datosPersonales
    struct datosPersonales agenda;

    printf("Ingrese el Nombre ");
    gets(agenda.nombre);
    fflush(stdin);

    printf("\nIngrese el apellido ");
    gets(agenda.apellido);
    fflush(stdin);

    printf("\nIngrese calle " );
    gets(agenda.calle);
    fflush(stdin);

    printf("\nIngrese numero de calle ");
    scanf("%d",&agenda.numero);

    printf("\nIngrese su codigo postal ");
    scanf("%d",&agenda.codigoPostal);

    /*strcpy(agenda.nombre, "Yanina");
    strcpy(agenda.apellido, "Scudero");
    strcpy(agenda.calle, "Mitre");
    agenda.numero = 750;
    agenda.codigoPostal = 9999;*/

    printf("El nombre es: %s ", agenda.nombre);
    printf("\nEl apellido es: %s ",agenda.apellido);
    printf("\nSu direccion es: %s %d ", agenda.calle , agenda.numero);
    printf("\nY su codigo postal es %d\n\n ",agenda.codigoPostal);

    /*printf("Nombre Apellido  Calle  Numero  Codigo postal\n");

    printf("%s  %s  %6s %5d  %8d\n", agenda.nombre,agenda.apellido,agenda.calle,agenda.numero,agenda.codigoPostal);*/

    return 0;
}
