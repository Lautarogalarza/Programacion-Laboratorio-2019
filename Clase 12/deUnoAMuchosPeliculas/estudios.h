#ifndef ESTUDIOS_H_INCLUDED
#define ESTUDIOS_H_INCLUDED
#include "input.h"

typedef struct
{
    int id;
    int estado;
    char nombre[50];
    char pais[50];

    int anioDeCreacion;

} eEstudio;

void inicializarEstudios(eEstudio lista[], int tam);

int buscarLibre(eEstudio lista[], int tam);
int buscarEstructura(eEstudio lista[], int tam, int legajo);

int generarNextId();

int cargarEstructura(eEstudio lista[], int tam);
void modfEstructura(eEstudio lista[], int tam);
void modificarEstructura(eEstudio lista[], int tam);

void mostrarEstructuras(eEstudio lista[], int indice);

int menuEstudio();

int menuPelicula();

#endif // ESTUDIOS_H_INCLUDED

//#include "peliculas" se pone aca para que no haya referencia ciclica
