#include <stdio.h>
#include <stdlib.h>

///////////////PASAJE POR REFERENCIA////////////////
int factorial(int);
/*void muestra(int *x, int y);*/

int main()
{
    /*int x,y;
    printf("ingrese 1: ");
    scanf("%d",&x);
    printf("ingrese 2: ");
    scanf("%d",&y);
    printf("x: %d y: %d", x,y);
    muestra(&x,y);
    printf("x: %d y: %d", x,y);

/////////////////PUNTEROS/////////////////////////
    int nro;
    int *n;

    nro=3;
    n=&nro;

    printf("%d\n",nro);
    printf("%x\n",n);
     printf("%x\n",&n);
    printf("%d\n",*n);*/

    /////////////////////////FACTORIAL//////////////////7

    int valor,result;
    printf("Ingrese el Numero: ");
    scanf("%d",&valor);
    result=factorial(valor);
    printf("El factorial de %d es %d", valor,result);



















    return 0;
}
/*void muestra(int *x, int y){

    *x=y;//asigna el dato guardado en la direccion de memoria que tiene guardado el puntero

    printf("x: %d y; %d", *x,y);
}*/
int factorial(int num){

    long int resultadoFactorial=1;
    int i;

    for(i=(int)num; i>=1; i--)
    {
        resultadoFactorial= resultadoFactorial*i;
    }

    return resultadoFactorial;
}
