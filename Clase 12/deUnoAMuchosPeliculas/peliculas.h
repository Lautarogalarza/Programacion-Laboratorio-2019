#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id;
    int estado;
    char titulo[50];
    char director[50];
    int idEstudio;
    float duracion;
    int anioDeEstreno;

} ePelicula;

//#include "estudios.h"  se pone aca para que no haya referencia ciclica, uno adentro uno afuera
#endif // PELICULAS_H_INCLUDED
