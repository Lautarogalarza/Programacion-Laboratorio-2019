#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array[5];
    int i;


    for(i=0; i<5; i++){
        printf("Ingrese 5 numeros: ");
        scanf("%d\n",&array[i]);

    }

     printf("\nlos numeros son: ");

    for(i=0; i<5; i++){
        printf("%d \n",array[i]);


    }







    return 0;
}
