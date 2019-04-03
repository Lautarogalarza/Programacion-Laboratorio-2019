#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[64];
    int cantidad;

    printf("Nombre: ");
    //fgets(buffer, 62, stdin);
    fgets(buffer,sizeof(buffer)-2,stdin);

    cantidad = strlen(buffer);//la cantidad de elementos de la cadena

    buffer[cantidad-1] = '\0';//la cantidad de elementos de la cadena -1 y a ese elmento en la posicion [cantidad -1] le asigna el \0

    printf("%s", buffer);

    strcmp()//string campare cadena 1 y cadena 2 comparan, devuelve 0 si son iguales, >0 si la cadena 1 es mayor a 2 y un valor menor a 0 si cadena 1 es menor a cadena 2
    stricmp()//lo mismo pero no es sensible a mayusculas y minisculas
    strcpy()//

    return 0;
}
