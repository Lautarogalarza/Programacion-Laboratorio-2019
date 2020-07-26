#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#define OCUPADO 0
#define VACIO 1
#include "UTN_INPUT.h"


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


/** \brief funcion encargada de hardcodear los menues en la estructura
 *
 * \param menues[] eMenu recibe el array de menues
 * \param tam int recibe el tamaño del array de menues
 * \return void La funcion no retorna nada
 *
 */
void initMenu(eMenu menues[], int tam);

/** \brief funcion encargada de hardcodear los sectores en la estructura
 *
 * \param sectores[] eSector recibe el array de sectores
 * \param tam int recibe el tamaño del array de sectores
 * \return void La funcion no retorna nada
 *
 */
void initSector(eSector sectores[], int tam);

/** \brief funcion encargada de hardcodear los empleados en la estructura
 *
 * \param lista[] eEmpleado recibe el array de empleados
 * \return void La funcion no retorna nada
 *
 */
void init_Emp(eEmpleado lista[]);

/** \brief funcion encargada de hardcodear los almuerzos en la estructura
 *
 * \param almuerzos[] eAlmuerzo recibe el array de almuerzos
 * \param tam int recibe el tamaño del array de almuerzos
 * \return void La funcion no retorna nada
 *
 */
void initAlmuerzo(eAlmuerzo almuerzos[], int tam);

/** \brief Funcion encargada de inicializar todos los elementos del array de empleados en un estado libre para cargar datos
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int retorna -1 si hubo algun error y 0 si no hubo ningun error
 *
 */
int inicializar_Empleados(eEmpleado lista[], int tam);



/** \brief Funcion encargada de buscar algun espacio libre en el array de empleados para cargar un nuevo dato
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna la primera posicion libre que encuentra la funcion
 *
 */
int buscarLibre(eEmpleado lista[], int tam);

/** \brief Funcion encargada de validar si existe un empleado cargado en el array
 *
 * \param list Employee* Recibe un puntero al array de empleados
 * \param len int la cantidad de elementos en el array
 * \return int Retorna -1 si no hay empleados y 0 si encontro
 *
 */
int hay_Empleados_Cargados(eEmpleado lista[], int tam);

/** \brief Funcion encargada de genera un numero de ID y autoincrementarlo
 *
 * \param La funcion no recibe parametros
 * \param La funcion no recibe parametros
 * \return Retorna el ID generado autoincrementado
 *
 */
int generarNextId();

/** \brief Funcion encargada de añadir a los empleados en la estructura
 *
 * \param lista[] eEmpleado Recibe el array de empleados
 * \param tam int recibe la cantidad de elementos en el array  de empleados
 * \param sectores[] eSector Recibe el array de sectores
 * \param tamSector int recibe la cantidad de elementos en el array de sectores
 * \return int  Retorna -1 si hubo un error y 0 si el empleado fue cargado correctamente
 *
 */
int alta_Empleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector);

/** \brief funcion encargada de cargar la fecha en la estructura
 *
 * \param lista[] eEmpleado recibe el array de empleados
 * \param indice int recibe la posicion del empleado a cargar su fecha
 * \return void
 *
 */
void cargarFecha_Empleado(eEmpleado lista[],int indice);

/** \brief Funcion que busca al empleado por su numero de ID
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \param int recibe el ID generado
 * \return int retorna la posicion del array donde se encuentra el ID generado
 *
 */
int buscar_Empleado_PorId(eEmpleado lista[], int tam, int legajo);

/** \brief Funcion encargada de modificar los campos de un empleado
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return int la posicion del array donde se encuentra el ID seleccionado
 *
 */
void modf_Empleado(eEmpleado lista[], int indice, eSector listaSector[] ,int tamSector);

/** \brief Funcion encargada de buscar al empleado y modificarlo
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error y 0 si se pudo modificar correctamente al empleado
 *
 */
int modificar_Empleado(eEmpleado lista[], int tam, eSector listaSector[] ,int tamSector);

/** \brief Funcion encargada de dar de baja a un empleado
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error o 0 si se dio de baja exitosamente
 *
 */
int baja_Empleado(eEmpleado lista[], int tam);

/** \brief funcion encargada de cargar el nombre del sector en la estructura
 *
 * \param sectores[] eSector recibe el array de sectores
 * \param tam int Recibe la cantidad de elementos en el array
 * \param idSector int recibe el id del sector
 * \param desc[] char recibe la descripcion del sector
 * \return int Retorna -1 si hubo un error o 0 si todo estuvo bien
 *
 */
int obtener_Sector(eSector sectores[], int tam, int idSector, char desc[]);


/** \brief imprime un menu
 *
 * \return int retorna la opcion elegida del menu
 *
 */
int menu();


/** \brief Funcion encargada de mostrar a un empleado
 *
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSector int recibe el tamaño de sectoress
 * \param lista eEmpleado recibe el array de empleados
 * \return void La funcion no retorna nada
 *
 */
void mostrar_Empleado(eSector sectores[], int tamSector, eEmpleado lista);

/** \brief Funcion encargada de mostrar el listado de todos los empleados
 *
 * \param lista[] eEmpleado recibe el array de empleados
 * \param tam int recibe el tamaño del array de empleados
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSector int recibe el tamaño de sectoress
 * \return int
 *
 */
int mostrar_Empleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector);

/** \brief funcion encargada de mostrar los sectores
 *
 * \param sectores[] eSector recibe el array de sectores
 * \param tam int recibe el tamaño del array de empleado
 * \return void La funcion no retorna nada
 *
 */
void mostrar_Sectores(eSector sectores[],int tam);

/** \brief funcion encargada de ordenar el array de empleados
 *
 * \param lista[] eEmpleado recibe el array de empleados
 * \param tam int recibe el tamaño del array de empleados
 * \return int int Retorna -1 si hubo un error o 0 si se ordeno exitosamente
 *
 */
int ordenar_Empleados(eEmpleado lista[],int tam );



//////////////////////////////////////////////////

/** \brief
 *
 * \param almuerzos[] eAlmuerzo recibe el array de almuerzos
 * \param tamAlmuerzo int recibe el tamaño del array de almuerzos
 * \param empleados[] eEmpleado recibe el array de empleados
 * \param tamEmpleados int recibe el tamaño del array de empleados
 * \param menues[] eMenu  recibe el array de menues
 * \param tamMenues int recibe el tamaño del array de menues
 * \return void la funcion no retorna nada
 *
 */
void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eMenu menues[], int tamMenues);
/** \brief funcion que muestra los almuerzos de cada empleado
 *
 * \param almuerzos[] eAlmuerzo recibe el array de almuerzos
 * \param tamAlmuerzo int recibe el tamaño del array de almuerzos
 * \param empleados[] eEmpleado recibe el array de empleados
 * \param tamEmpleados int  recibe el tamaño del array de empleados
 * \param menues[] eMenu recibe el array de menues
 * \param tamMenues int recibe el tamaño del array de menues
 * \param sectores[] eSector  recibe el array de sectores
 * \param tamSector int recibe el tamaño del array de sectores
 * \return void la funcion no retorna nada
 *
 */
void mostrarAlmuerzosEmpleado(eAlmuerzo almuerzos[], int tamAlmuerzo, eEmpleado empleados[], int tamEmpleados, eMenu menues[], int tamMenues, eSector sectores[], int tamSector);
/** \brief
 *
 * \param empleados[] recibe el array de empleados
 * \param tam int recibe el tamaño del array de empleados
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSec int recibe el tamaño del array de sectores
 * \return void la funcion no retorna nada
 *
 */
void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);
/** \brief
 *
 * \param empleados[] eEmpleado recibe el array de empleados
 * \param tam int recibe el tamaño del array de empleados
 * \param sectores[] eSector recibe el tamaño del array de sectores
 * \param tamSec int recibe el tamaño del array de sectores
 * \return void la funcion no retorna nada
 *
 */
void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec);


#endif // EMPLEADOS_H_INCLUDED
