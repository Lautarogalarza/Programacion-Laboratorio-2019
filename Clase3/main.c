#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo(int x, int y, int z);

int main()
{
    int numero1;
    int numero2;
    int numero3;
    int numeroMax;

    printf("ingrese numero1:\n");
    scanf("%d",&numero1);

    printf("ingrese numero2:\n");
    scanf("%d",&numero2);

    printf("ingrese numero3:\n");
    scanf("%d",&numero3);

    numeroMax = obtenerMaximo(numero1,numero2,numero3);

    printf("\n\nEl numero maximo es: %d\n\n", numeroMax);

    return 0;
}
int obtenerMaximo(int x, int y, int z)
{
    int maximo;

    if(x > y && x > z)
    {
        maximo = x;
    }
     else if(y >=x && y > z)
    {
        maximo = y;
    }
     else
    {
        maximo = z;
    }
    return maximo;
}
