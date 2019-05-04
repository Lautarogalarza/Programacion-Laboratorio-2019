#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

#include "input.h"

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

typedef struct
{
    int codigoMenu;
    char descripcion[51];
    float Importe;

} eMenu;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int codigoAlmuerzo;
    int codigoMenu;
    int legajoEmpleado;
    eFecha fecha;
} eAlmuerzo;

typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo;
    float salario;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

} eEmpleado;


void initMenu(eMenu menues[], int tam);
void initSector(eSector sectores[], int tam);
void inicializarEmpleados(eEmpleado lista[], int tam);
void initEmp(eEmpleado lista[]);

int buscarLibre(eEmpleado lista[], int tam);

int menu();

int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector,int id);

 int generarNextId();

void cargarFecha(eEmpleado lista[],int indice);
void modfEmpleado(eEmpleado lista[], int tam);
void modificarEmpleado(eEmpleado lista[], int indice);
void bajaEmpleado(eEmpleado lista[], int tam);

void mostrarEmpleado(eSector sectores[], int tamSector, eEmpleado lista);
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector);
void mostrarSectores(eSector sectores[],int tam);
void ordenarEmpleados(eEmpleado lista[],int tam );

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[]);


#endif // EMPLEADOS_H_INCLUDED
