#include <stdio.h>
#include <stdlib.h>

int main()
{   /*3.Escribir un programa que realice las siguientes acciones
    Limpie la pantalla
    Asigne a 2 variables numero1 y numero2 valores distintos de cero
    Efectúe el producto de dichas variables
    Muestre el resultado pos pantalla
    Obtenga el cuadrado de numero1 y lo muestre par pantalla*/

    float numero1;
    float numero2;
    int opcion;
    char vuelta='s';

    while(vuelta == 's')
    {
        printf("1.Limpiar la pantalla.\n");
        printf("2.Asignar valores a dos variables.\n");
        printf("3.Efectuar el producto de dichas variables.\n");
        printf("4.Mostrar resultados.\n");
        printf("5.Obtener el cuadrado de numero1.\n");
        printf("por favor ingrese una opcion.\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("a");
                break;
            case 2:
                printf("a");
                break;
            case 3:
                printf("a");
                break;
            case 4:
                printf("a");
                break;
            case 5:
                printf("a");
                break;
            default:
                printf("a");
        }
        //Pregunta si queremos salir del menu
        printf("Desea continuar ingrese 's'.\n");
        fflush(stdin);
        scanf("%c",&vuelta);
    }
    return 0;
}
