#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int resultado;
    printf("Este programa pide dos numeros y muestra la suma.\n");
    system("pause");
    printf("Ingrese el primer numero.\n");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero.\n");
    scanf("%d", &numero2);
    system("cls");
    resultado = numero1 + numero2;
    printf("El resultado de la suma de '%d' y '%d' es: '%d'\n", numero1, numero2, resultado);
    printf("Gracias por usar este programa.\n");
    system("pause");
    return 0;
}
