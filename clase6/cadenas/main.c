#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena[50];
    fflush(stdin);

    printf("Ingrese una cadena: ");

    //scanf("%s", cadena);

    //gets(cadena);no se usa por que no es recomendable

    fgets(cadena);



    printf("\n%s\n", cadena);

    return 0;
}
