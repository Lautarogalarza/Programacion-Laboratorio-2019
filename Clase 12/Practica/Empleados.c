#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Empleados.h"


int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Listar Empleados\n");
    printf("3- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void initMenu(eMenu menues[], int tam)
{
    int auxCodigo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char auxDescripcion[10][51]= {"Fideos","Milanesa","Pollo","Pescado","Guiso","Carne","Verduras","Vegano","Pizza","Panchito"};
    float auxImporte[10] = { 235.50, 340, 457, 234, 132, 287, 321, 216, 298.50, 558};


    for(int i=0; i<tam; i++)
    {
        menues[i].codigoMenu=auxCodigo[i];

        strcpy(menues[i].descripcion, auxDescripcion[i]);

        menues[i].Importe=auxImporte[i];



    }
}


void initSector(eSector sectores[], int tam)
{
    int auxCodigo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char auxDescripcion[10][51]= {"RRHH","Sistemas","Ventas","Limpieza","Legales"};

    for(int i=0; i<tam; i++)
    {
        sectores[i].id=auxCodigo[i];

        strcpy(sectores[i].descripcion, auxDescripcion[i]);

    }
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 0;
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1 && lista[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector,int id)
{
    int indice;
    int hayEmpleado;
    int auxSector;


    indice = buscarLibre(lista, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {

        hayEmpleado = buscarEmpleado(lista, tam, id);

        if( hayEmpleado != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", id);
            //mostrarEmpleado(sectores, tamSector, lista[hayEmpleado]);
        }
        else
        {

            lista[indice].legajo = id;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[indice].nombre);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(lista[indice].apellido);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &lista[indice].sexo );

            printf("Ingrese salario: ");
            scanf("%f", &lista[indice].salario );
            cargarFecha(lista,indice);

            system("cls");
            mostrarSectores(sectores,tamSector);
            printf("\nIngrese sector: ");
            scanf("%d", &auxSector );

            /*for(int i=0; i<tamSector;i++)
            {
                if(auxSector!=sectores[i].id)
                {
                    printf("\nEl sector ingresado no existe, por favor ingrese un sector correcto\n");
                    printf("\nIngrese sector: ");
                    scanf("%d", &auxSector );

                }
                else
                {
                    break;

                }
            }*/

            lista[indice].idSector=auxSector;
            lista[indice].isEmpty = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}

void mostrarEmpleado(eSector sectores[], int tamSector, eEmpleado lista)
{
    char nombreSector[20];


    obtenerSector(sectores, tamSector, lista.idSector, nombreSector);


    printf("%2d   %15s   %7s   %5c   %10.2f %s  %d/%d/%d\n", lista.legajo, lista.nombre,lista.apellido, lista.sexo, lista.salario, nombreSector,lista.fechaIngreso.dia,lista.fechaIngreso.mes,lista.fechaIngreso.anio);

}

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int contador = 0;

    printf(" Legajo      Nombre    Apellido    Sexo    Salario   Sector  Fecha de ingreso\n\n");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            mostrarEmpleado(sectores,tamSector,lista[i]);

            //printf("%2d   %15s   %7s   %5c   %10.2f\n",lista[i].legajo ,lista[i].nombre  ,lista[i].apellido  ,lista[i].sexo,lista[i].salario );
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}
void mostrarSectores(eSector sectores[],int tam)
{
    printf("ID  Descripcion\n");
    for (int i=0; i<tam; i++)
    {
        printf("%d %12s\n",sectores[i].id,sectores[i].descripcion);
    }
}

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{

    int encontro = 0;

    for(int i=0; i < tam; i++)
    {

        if(idSector == sectores[i].id)
        {

            strcpy(desc, sectores[i].descripcion);
            encontro = 1;
            break;
        }
    }

    return encontro;
}
void cargarFecha(eEmpleado lista[],int indice)
{
    int auxDia;
    int auxMes;
    int auxAnio;

    printf("\nIngrese su fecha de ingreso\n");

    printf("Ingrese dia: ");
    scanf("%d",&auxDia);
    printf("Ingrese mes");
    scanf("%d",&auxMes);
    printf("Ingrese anio");
    scanf("%d",&auxAnio);

    lista[indice].fechaIngreso.dia=auxDia;
    lista[indice].fechaIngreso.mes=auxMes;
    lista[indice].fechaIngreso.anio=auxAnio;
}
