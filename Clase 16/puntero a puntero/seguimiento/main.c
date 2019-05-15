#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero=25;

    int* punteroInt;
    int** punteroPuntero;


    punteroInt=&numero;

    punteroPuntero=&punteroInt;

    printf("MUESTRO LO QUE CONTIENE LA VARIABLE QUE APUNTAN\n");
    printf("%d\n",**punteroPuntero);
    printf("%d\n",*punteroInt);
    printf("MUESTRO LA DIRECCION DE MEMORIA DEL PUNTERO Y LA VARIABLE\n");
    printf("%d\n",punteroInt);
    printf("%d\n",&numero);
    printf("MUESTRO LA DIRECCION DE MEMORIA DEL PUNTERO QUE APUNTA \n");
    printf("%d\n",&punteroInt);
    printf("%d\n",punteroPuntero);



    return 0;
}
