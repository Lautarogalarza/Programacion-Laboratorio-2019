#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dia;

    int mes;

    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombra[20];
    char sexo;
    float sueldo;
    eFecha fecha;

} eEmpleado;

int main()
{
    eEmpleado unEmpleado= {1234,"Juan",'m',30000,{13,5,2019}};
    eEmpleado otroEmpleado= {2222,"Ana",'f',32000,{20,8,2019}};

    eEmpleado lista [2]={unEmpleado,otroEmpleado};

    for(int i=0;i<2;i++)
    {

    printf("%s\n",(lista+i)->nombra);//aritmerica de punteros

    }






























   /* eEmpleado* punteroEmpleado;

punteroEmpleado = &unEmpleado;


    printf("Legajo: %d\n", punteroEmpleado->legajo);//accedo al campo de la estructura usando punteros con el operador flecha
    printf("\n");
    printf("Legajo: %d\n", *punteroEmpleado);//esto me va a mostrar el legajo por que el puntero apunta a la primer direccion de memoria de la estructura
    printf("\n");
    printf("Anio: %d\n", punteroEmpleado->fecha.anio);//accedo a un campo anidado del puntero a estructura
    printf("\n");
    printf("nombre: %s\n", (*punteroEmpleado).nombra);//lo mismo que con el operadoe ->*/




    return 0;
}
