#include <stdio.h>
#include <stdlib.h>
#define TAM 5
////////////////ARITMERICA DE PUNTEROS///////////////

void mostrarVector1(int vec[], int tam);//nomenclatura vectorial muestra vectorial

void mostrarVector2(int vec[], int tam);//nomenclatura vectorial muestra punteros

void mostrarVector3(int* vec, int tam);//nomenclatura puntero muestra vectorial

void mostrarVector4(int* vec, int tam);//nomenclatura puntero muestra puntero



int main()
{

    int numeros[5] = {3,5,2,4,3};

    int* p;

    /*printf("%x\n",vec);//muestro la direccion de memoria del primero elemento del array

    printf("\n%x\n",*vec);//muestro el primer elemento guardado en la direccion de memoria del primer elemento

    printf("\n%x\n",*(vec+1));//me corro a la siguiente direccion de memoria en el array
    //1 es un sizeof del tipo de dato en este caso le digo que se corra 1 sizeof del tipo de dato en este caso entero
    //pero puede correrme la cantidad de numeros que quiera mientras el array no termine


    for (int i=0; i<5;i++)
    {
        printf("%d\n",*(vec+i) );//recorro el array utilizando aritmetica de punteros
    }*/

    mostrarVector1(numeros,TAM);
    printf("\n");
    mostrarVector2(numeros,TAM);
    printf("\n");
    mostrarVector3(numeros,TAM);
    printf("\n");
    mostrarVector4(numeros,TAM);


    return 0;
}

void mostrarVector1(int vec[], int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d\n",vec[i] );//nomenclatura vectorial muestra con vectorial
    }
}


void mostrarVector2(int vec[], int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d\n",*(vec+i) );//nomenclatura vectorial muestra con  aritmetica de punteros
    }
}



void mostrarVector3(int* vec, int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d\n",vec[i] ); //nomenclatura puntero muestra con vectorial
    }
}


void mostrarVector4(int* vec, int tam)
{
    for (int i=0; i<tam; i++)
    {
        printf("%d\n",*(vec+i) );//nomenclatura puntero muestra con  aritmetica de punteros
    }
}
