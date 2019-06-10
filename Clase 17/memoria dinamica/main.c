#include <stdio.h>
#include <stdlib.h>

int checkNull(void* pointer);

int main()
{
    int* pNum;
    int flagNull;

    pNum = (int*) malloc(sizeof(int));//Si no consigue espacio devuelve NULL (no dirección de memoria). Se castea para convertirlo.

    if(pNum == NULL)//Verifico que haya encontrado memoria.
    {
        printf("\nNo se consiguio memoria\n");
        system("pause");
        exit(1);//Me saca de la ejecución del programa. Devuelve 1 al OS ¡No utilizar en funciones!
    }

    *pNum = 10;

    printf("%d\n", *pNum);

    pNum=NULL;

    //checkNull(pNum);



    flagNull= checkNull(pNum);

    if (flagNull){
        printf("\nNo se consiguio memoria\n");
        system("pause");
        exit(1);//Me saca de la ejecución del programa. Devuelve 1 al OS ¡No utilizar en funciones!

    }

        free(pNum);//Libera la memoria pedida con malloc.


    return 0;
}
int checkNull(void* pointer)
{
    int isNull=0;

    if(pointer == NULL)
    {
        //printf("\nNo hay memoria libre suficiente\n");
        //system("pause");
        isNull=1;
    }

    return isNull;
}
