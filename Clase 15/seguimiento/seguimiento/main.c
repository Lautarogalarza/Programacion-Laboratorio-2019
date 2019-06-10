#include <stdio.h>
#include <stdlib.h>

void leerPuntero(int* );

int main()
{
    int x = 10;

    int* p= &x;

    int** r= &p; // un puntero que apunta a un puntero a entero puntero a puntero

    printf("%d", **r);//muestro el contedido de la variable que apunta al puntero que apunta p







    return 0;
}

/*void leerPuntero(int* p)//recibe la direccion de memoria de x y la guarda en el puntero
{


    *p=38;
}*/
