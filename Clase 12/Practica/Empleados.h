#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

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
int buscarLibre(eEmpleado lista[], int tam);
void inicializarEmpleados(eEmpleado lista[], int tam);
int menu();
void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector,int id);
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector);
void mostrarSectores(eSector sectores[],int tam);
int obtenerSector(eSector sectores[], int tam, int idSector, char desc[]);
void mostrarEmpleado(eSector sectores[], int tamSector, eEmpleado lista);
void cargarFecha(eEmpleado lista[],int indice);
void modfEmpleado(eEmpleado lista[], int tam);
void modificarEmpleado(eEmpleado lista[], int indice);

#endif // EMPLEADOS_H_INCLUDED
