#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"


void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarEmpleado(eEmpleado emp){

    printf("   %d       %10s     %c    %.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);

}

void mostrarEmpleados(eEmpleado vec[], int tam){
    int contador = 0;

    printf(" Legajo   Nombre  Sexo  Sueldo\n\n");
    for(int i=0; i < tam; i++){
        if(vec[i].ocupado == 1){
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }

    if( contador == 0){
        printf("\nNo hay empleados que mostrar\n");
    }
}

int buscarLibre(eEmpleado vec[], int tam){

    int indice = -1;

     for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0){
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo){

    int indice = -1;

     for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].legajo == legajo){
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam){

int indice;
int legajo;
int esta;


indice = buscarLibre(vec, tam);

if( indice == -1){

    printf("\nNo hay lugar en el sistema\n");
}
else{
     printf("Ingrese legajo: ");
     scanf("%d", &legajo);

     esta = buscarEmpleado(vec, tam, legajo);

     if( esta != -1){
        printf("Existe un empleado de legajo %d en el sistema\n", legajo);
        mostrarEmpleado(vec[esta]);
     }
     else{
        vec[indice].legajo = legajo;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(vec[indice].nombre);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &vec[indice].sexo );

        printf("Ingrese sueldo: ");
        scanf("%f", &vec[indice].sueldo );

        vec[indice].ocupado = 1;

        printf("Alta empleado exitosa!!!\n\n");

     }

}

}
void bajaEmpleado(eEmpleado vec[], int tam)
{
    int respuesta;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vec[i].ocupado==1)
        {
            printf("\nLegajo empleado %d",vec[i].legajo);
        }
    }

    printf("\nQue empleado queres dar de baja? (Ingresar ID Usuario) ");
    scanf("%d",&respuesta);
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        if(respuesta==vec[i].legajo)
        {
            vec[i].ocupado=0;
            break;
        }
    }

}
void modificarEmpleado(eEmpleado vec[], int tam)
{
   int respuesta;
   int legajo;
    int i;
    for(i=0; i<tam; i++)
    {
        if(vec[i].ocupado==1)
        {
            printf("\nLegajo empleado %d",vec[i].legajo);
        }
    }

    printf("\nQue empleado queres modificar? (Ingresar Legajo Usuario) ");
    scanf("%d",&legajo);
    fflush(stdin);

    for(i=0; i<tam; i++)
    {

        if(legajo==vec[i].legajo )
        {
            printf("Esta seguro que quiere modificar a este usuario? <1.Si-2.No>\n");
            scanf("%d",&respuesta);

            switch(respuesta)
            {
            case 1:

                for (i=0; i<tam; i++)
                {
                    if(vec[i].legajo==legajo && vec[i].ocupado==1)
                    {
                        modfEmpleado(vec,i);

                        break;
                    }
                }
                break;
            case 2:
                printf("Modificacion cancelada");
                break;
            default:
                break;


            }
        }
        break;

    }


}
void modfEmpleado(eEmpleado vec[], int i)
{
    int option;
    char auxNewName[31];
    char auxNewSex;
    float auxNewSalary;




    do
    {

        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Salario\n");
         printf("3.Modificar Sexo\n");
        printf("4.Salir\n");
        scanf("%d",&option);


        switch(option)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");

            fflush(stdin);

            gets(auxNewName);

            strcpy(vec[i].nombre, auxNewName);
            break;

        case 2:

           printf("Ingrese nuevo sueldo: ");

            scanf("%f", &auxNewSalary );

            vec[i].sueldo=auxNewSalary;

            break;
             case 3:

           printf("Ingrese nuevo sexo: ");

            scanf("%c", &auxNewSex );

            vec[i].sexo=auxNewSex;

            break;
        case 4:
            break;
        default:
            printf("ERROR!! por favor ingrese una de las opciones validaas <1-5>\n");
            break;


        }


    }
    while(option==4);

}
