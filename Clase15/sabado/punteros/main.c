#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define TAM_STRUCT 3

typedef struct
{
    int numero;

    char nombre[31];

    float salario;

}eUsuario;

void imprimirPunteroEntero(int* pEntero);
void imprimirPunteroArray(int* pArray, int tam);
void imprimirPunteroEstructura(eUsuario* pEstructura);
void imprimirPunteroEstructuras(eUsuario* pEstructura,int tam);

int main()
{
    int numero = 25;
    int* Pnumero;
    Pnumero=&numero;


    int array[TAM]={5,23,12,41,89,201,900,99,80,1};
    int* pArray;
    pArray=array;


    eUsuario unUsuario={15,"carol hr",50.875};
    eUsuario* pUsuario;
    pUsuario=&unUsuario;



    eUsuario lista[TAM_STRUCT] ={{1,"pepe silva",25.000}, {2,"charlie day",12.900}, {3,"green man",76.984} };
    eUsuario* pLista;
    pLista=lista;



    imprimirPunteroEntero(Pnumero);
    imprimirPunteroArray(pArray,TAM);
    imprimirPunteroEstructura(pUsuario);
    imprimirPunteroEstructuras(pLista,TAM_STRUCT);

    return 0;
}

void imprimirPunteroEntero(int* pEntero)
{
    printf("////puntero a INT////\n");
    printf("\n%d",*pEntero);


}

void imprimirPunteroArray(int* pArray,int tam)
{
    printf("\n\n////puntero a Array////\n\n");

    for(int i=0;i<tam;i++)
    {
        printf("%d\n",*( pArray+i ));
    }

}

void imprimirPunteroEstructura(eUsuario* pEstructura)
{
      printf("\n////puntero Estructura////\n");

    printf("\nID:%d\nNombre:%s\nSalario:%.3f\n\n",pEstructura->numero, pEstructura->nombre, pEstructura->salario);
}

void imprimirPunteroEstructuras(eUsuario* pEstructura,int tam)
{
    printf("\n////puntero a Array de Estructuras////\n");

    for(int i=0;i<tam;i++)
    {
        printf("\nID:%d\nNombre:%s\nSalario:%.3f\n\n",(pEstructura+i)->numero,(pEstructura+i)->nombre,(pEstructura+i)->salario);
    }
}


