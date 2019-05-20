#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;

    char nombre[21];

    char sexo;

    float salario;

}eEmplado;

int main()
{
    eEmplado emp;

    eEmplado* pEmp = (eEmplado*) malloc(sizeof(eEmplado));

    if(pEmp == NULL)
    {
        exit(1);
    }


    printf("Ingrese legajo: ");
    scanf("%d",&pEmp->legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(pEmp->nombre);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&pEmp->sexo);

    printf("Ingrese salario: ");
    scanf("%f",&pEmp->salario);


    printf("\nLEGAJO NOMBRE SEXO SALARIO\n");

    printf("\n%d %10s %3c %10.2f\n",pEmp->legajo,pEmp->nombre,pEmp->sexo,pEmp->salario);




    return 0;
}
