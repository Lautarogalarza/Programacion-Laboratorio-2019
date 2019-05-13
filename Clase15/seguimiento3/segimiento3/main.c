#include <stdio.h>
#include <stdlib.h>

void getCar(char* message, char* caracter );//en los dos caso la direccion de memoria del primer elemento en este caso un caracter

int main()
{
   char nombre[20]="Sebastian";

   char sexo;



getCar("Ingrese sexo :",&sexo);

printf("\nEl sexo es :%c",sexo);





    return 0;
}
void getCar(char* message, char* caracter )
{


    printf("%s",message);
    fflush(stdin);
    scanf("%c", caracter);//scanf recibe un puntero entonces solo le paso la direccion de memoria como con una cadena

}
