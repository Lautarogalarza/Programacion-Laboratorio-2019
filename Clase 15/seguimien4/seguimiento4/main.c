#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* cadena);

int main()
{
    char mensaje[]="Hola mundo";


    mostrarCadena(mensaje);//muestro la cadena recorriendo caracter por caracter
    printf("\n");


    return 0;
}

void mostrarCadena(char* cadena)
{
    while(*cadena!='\0')
    {
        printf("%c",*cadena);
        cadena++;//me voy moviendo un espacio en la direccion de memoria sumandole 1
    }

    //for(int i=0; *(cadena  + i)!='\0';i++)
}
