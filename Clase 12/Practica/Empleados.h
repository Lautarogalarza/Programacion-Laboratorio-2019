#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

typedef struct
{
    int codigoMenu;
	char descripcion[51];
    float Importe;

}eMenu;

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int codigoAlmuerzo;
	int codigoMenu;
	int legajoEmpleado;
	eFecha fecha;
}eAlmuerzo;

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

}eEmpleado;


void initMenu(eMenu menues[], int tam);

#endif // EMPLEADOS_H_INCLUDED
