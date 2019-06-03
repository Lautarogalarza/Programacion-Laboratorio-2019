#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
} eEmpleado;

void mostrarEmpleados(eEmpleado** lista, int len);
eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo);
eEmpleado* new_Empleado();
int listaParaImprimir(eEmpleado** lista, int len, char* path);
int guardarEmpleadosCSV(eEmpleado** lista, int len, char* path);
int guardarEmpleadosBinario(eEmpleado** lista, int len, char* path);

int main()
{
    FILE* f;

    char buffer[4][20];
    eEmpleado** lista = (void**) malloc(sizeof(void*));
    eEmpleado** pAuxEmpleado;

    int cont = 0;
    int cant;

    f = fopen("./empleados.bin","rb");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    //printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while( !feof(f) )
    {
        eEmpleado* nuevoEmpleado = new_Empleado(); ///ME CONSIGUE UN EMPLEADO VACIO.
        if(nuevoEmpleado == NULL)
        {
            exit(1);///SI ESTA EN FUNCION SE SALE.
        }
        cant = fread(nuevoEmpleado, sizeof(eEmpleado), 1, f);
        if( cant < 1)
        {
            break;
        }

        *(lista + cont) = nuevoEmpleado;
        cont++;

        pAuxEmpleado = (void**) realloc(lista, sizeof(void*) *(cont+1));
        if(pAuxEmpleado == NULL)
        {
            exit(1);
        }
        lista = pAuxEmpleado;
    }

    mostrarEmpleados( lista, cont);

    fclose(f);


    ///LISTADO EN TXT.

    if(listaParaImprimir(lista, cont, "ListaEmpleados.txt"))
    {
        printf("SE HA IMPRESO LA LISTA.\n");
    }
    else
    {
        printf("PROBLEMAS AL IMRPIMIR.\n");
    }


    ///GUARDAMOS EN CSV.
    if(guardarEmpleadosCSV(lista, cont, "empleados2"))
    {
        printf("SE HAN GUARDADO LOS EMPLEADOS EN CSV.\n");
    }
    else
    {
        printf("PROBLEMAS AL GUARDAR LOS EMPLEADOS.\n");
    }

    ///GUARDAR EN BINARIO.
    if(guardarEmpleadosBinario(lista, cont, "empleados"))
    {
        printf("SE HAN GUARDADO LOS EMPLEADOS EN BINARIO.\n");
    }
    else
    {
        printf("PROBLEMAS AL GUARDAR LOS EMPLEADOS.\n");
    }

    ///LISTAR EN BINARIO.
    if(listaParaImprimir(lista, cont, "empleados.bin"))
    {
        printf("SE HA IMPRESO LA LISTA.\n");
    }
    else
    {
        printf("PROBLEMAS AL IMRPIMIR.\n");
    }

    return 0;
}

int listaParaImprimir(eEmpleado** lista, int len, char* path)
{
    int ok = 1;
    FILE* f = fopen(path,"w");
    if(f == NULL)
    {
        ok = 0;
        return ok;///Se puede usar pero es mala practica.
    }
    fprintf(f, "LISTADO DE EMPLEADOS\n");
    fprintf(f, "LEGAJO NOMBRE APELLIDO SUELDO\n");
    for(int i=0; i < len; i++)
    {
        fprintf(f," %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    printf("\n\n");

    fclose(f);
    return ok;
}

int guardarEmpleadosCSV(eEmpleado** lista, int len, char* path)
{
    int ok = 1;
    char ext[] = ".csv";
    char nombreArchivo[100];
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, ext);

    FILE* f = fopen(nombreArchivo,"w");
    if(f == NULL)
    {
        ok = 0;
        return ok;///Se puede usar pero es mala practica.
    }
    fprintf(f, "id,first_name,last_name,sueldo\n");
    for(int i=0; i < len; i++)
    {
        fprintf(f," %d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    fclose(f);
    return ok;
}

int guardarEmpleadosBinario(eEmpleado** lista, int len, char* path)
{
    int ok = 1;
    char ext[] = ".bin";
    char nombreArchivo[100];
    strcpy(nombreArchivo, path);
    strcat(nombreArchivo, ext);

    FILE* f = fopen(nombreArchivo,"wb");
    if(f == NULL)
    {
        ok = 0;
        return ok;///Se puede usar pero es mala practica.
    }
    for(int i=0; i < len; i++)
    {
        //fprintf(f," %d,%s,%s,%.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
        fwrite(*(lista + i), sizeof(eEmpleado), 1, f);
    }
    fclose(f);
    return ok;
}


void mostrarEmpleados(eEmpleado** lista, int len)
{

    for(int i=0; i < len; i++)
    {
        printf(" %5d   %10s   %20s  %8.2f\n", (*(lista + i))->legajo, (*(lista + i))->nombre, (*(lista + i))->apellido, (*(lista + i))->sueldo);
    }
    printf("\n\n");

}


eEmpleado* new_Empleado()
{

    eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->legajo = 0;
        strcpy(emp->nombre, "");
        strcpy(emp->apellido, "");
        emp->sueldo = 0;

    }
    return emp;
}

eEmpleado* new_EmpleadoParam( int leg, char* nombre, char* apellido, float sueldo)
{

    eEmpleado* emp = (eEmpleado*)malloc( sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->legajo = leg;
        strcpy(emp->nombre, nombre);
        strcpy(emp->apellido, apellido);
        emp->sueldo = sueldo;

    }
    return emp;
}
