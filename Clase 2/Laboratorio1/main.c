#include <stdio.h>
#include <stdlib.h>

/*

*/
int main()      //obligatoria.
{
    /*
    float resultado;
    int n1, n2;
    n1 = 6;
    n2 = 8;

    resultado = n1%n2;          //Mal.
    resultado = (float) n1/n2;  //Bien.

    printf("El resultado es: %f\n", resultado);
    */

    //usamos while o do while cuando no sabemos la cantidad de datos a ingresar.
    /*
    //Mostramos numeros del 1 al 10;
    //con el condicional 'while'.
    int i = 0;
    while(i<10)
    {
        printf("el numero es %d\n", (i + 1));
        i++;
    }
    */

    /*
    //con el do while es:   (do = hacer, while = mientras).
    int i = 0;
    do                      //hacer.
    {
        i++;
        printf("el numero es %d\n", i);
    }while(i<10);           //mientras(condicion).
    */

    /*
    //la usamos cuando sabemos la cantidad de datos a mostrar.
    //Mostramos numeros del 1 al 10
    //con el condicional 'for'

    int i;

    for(i = 0; i <10; i++)
    {
        printf("numeros %d\n", (i+1));
    }
    */

    /*
    //switch
    int hora;
    printf("Por favor ingresa una hora.\n");
    scanf("%d", &hora);
    if(hora >23)
    {
        printf("Ingresaste una hora que no existe");
    }
    else
    {
        switch(hora)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                printf("a dormir");
                break;
            case 7:
            case 8:
            case 9:
                printf("Buenos dias");
                break;
            default:
                printf("cualquier cosa");
        }
    }
    */

    /*
    char hora;
    printf("Ingresa un caracter\n");
    fflush(stdin);
    scanf("%c", &hora);
    switch(hora)
    {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
            printf("A dormir\n");
            break;
        case '7':
        case '8':
            printf("Buenos dias\n");
            break;
        default:
            printf("otra cosa\n");
    }
    */

    //contador y acumulador.

    //maximos y minimos.

    return 0;   //obligatoria. cuando retornas '0' significa que tu funcion finalizo la ejecucion sin ningun error.
}
