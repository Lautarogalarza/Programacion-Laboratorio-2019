#include <stdio.h>
#include <stdlib.h>

void leerPuntero(int* );

int main()
{
    int x = 10;

    int* p;

    char* j;

    p=&x;//le asigno la direccion de memoria de x al puntero con el operador de direccion



    printf("%d\n",x);

    printf("%x\n",p);//muestro la direccion de memoria a la que apunta el puntero y lo muestra en hexadecimal

    printf("%d\n",*p);// con el operador de indireccion puedo mostrar el contenido de la variable que apunta*/

    printf("antes de llamar a leer puntero: %d\n",x);
    leerPuntero(&x);

    printf("\ndespues de llamar a leer puntero: %d\n",x);





    return 0;
}

void leerPuntero(int* p)//recibe la direccion de memoria de x y la guarda en el puntero
{
    //printf("%d\n",*p);

    *p=38;//le asigno otro valor a la direccion de memoria que guarda x con el operador de indireccion
}
