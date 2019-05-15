#include <stdio.h>
#include <stdlib.h>

void mostrarCadena(char* pPalabra);
void mostrarCadena2(char* pPalabra);


int main()
{
    char palabrita[7]= {"Buenas"};

    char*pPalabra;

    pPalabra=palabrita;



mostrarCadena(pPalabra);
printf("\n");
mostrarCadena2(pPalabra);


    return 0;
}

void mostrarCadena(char* pPalabra)
{
    while(*pPalabra != '\0')
    {
        printf("%c\t",*pPalabra);
        printf("%p\n",pPalabra);
        pPalabra++;//cambio el valor de la variable
    }
}


void mostrarCadena2(char* pPalabra)
{
    while(*(pPalabra+i) != '\0')
   for (int i=0; i<7; i++)
    {

        printf("%c\t",*(pPalabra+i) );//recorro la variable puntero sin cambiar las direcciones
        printf("%p\n",pPalabra);

    }
}

