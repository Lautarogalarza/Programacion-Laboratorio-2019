#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudios.h"

void inicializarEstudios(eEstudio lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        lista[i].estado = 0;
    }
}

int buscarLibre(eEstudio lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int menuEstudio()
{
    int opcion;


    system("cls");
    printf("  *** ABM Estudios ***\n\n");
    printf("1- Alta Estudio\n");
    printf("2- Listar Estudios\n");
    printf("3- Modificar Estudios\n");
    printf("4- Baja Estudios\n");
    printf("5- Ordenar Estudios\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int cargarEstructura(eEstudio lista[], int tam)
{
    int indice;
    int respuesta;
    char auxNombre[51] ;
    char auxPais[51] ;
    int auxAnio;
    int myReturn=-1;


    indice = buscarLibre(lista, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {

            getValidString("\nIngrese nombre de estudio : ","\nerror por favor solo ingrese caracteres","\nerror se exedio del limite de caracteres\n",auxNombre,1,50);
            fflush(stdin);

            stringToUpper(auxNombre);
            strcpy(lista[indice].nombre,auxNombre);


            getValidString("Ingrese pais : ","\nerror por favor solo ingrese caracteres","\nerror se exedio del limite de caracteres\n",auxPais,1,50);
            fflush(stdin);

            stringToUpper(auxPais);
            strcpy(lista[indice].pais,auxPais);

            getValidInt("ingrese anio de creacion :","\nerror ingrese un año valido  <1931-2019>\n",1931,2019,&auxAnio);

            lista[indice].anioDeCreacion=auxAnio;


            printf("Esta seguro que quiere darle de alta a este estudio? <1.Si-2.No>");
            scanf("%d",&respuesta);

            if(respuesta==1)
            {

                lista[indice].estado = 1; //isEmpty en 1 esta  vacio y en 0 esta cargado

                lista[indice].id=generarNextId();

                printf("Alta de estudio exitosa!!!\n\n");

                myReturn=0;

            }
            else
            {

                printf("alta cancelada");

            }


    }

    return myReturn;
}


int buscarEstructura(eEstudio lista[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1 && lista[i].id == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarEstructuras(eEstudio lista[], int tam)
{
    int contador = 0;

    printf(" Legajo      Nombre    Pais  Fecha de creacion\n\n");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].estado == 1)
        {

        printf("%2d   %15s   %7s   %d\n",lista[i].id ,lista[i].nombre  ,lista[i].pais,lista[i].anioDeCreacion );
            contador++;
        }
    }

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}


void modificarEstructura(eEstudio lista[], int tam)
{
    int respuesta;
    int legajo;
    int i;
    int indice;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printf("\nLegajo empleado %d",lista[i].id);
        }
    }

    printf("\nQue empleado queres modificar? (Ingresar Legajo Usuario) ");
    scanf("%d",&legajo);
    fflush(stdin);


    indice=buscarEstructura(lista,tam,legajo);
    if(legajo==lista[indice].id )
    {
        printf("Esta seguro que quiere modificar a este usuario? <1.Si-2.No>\n");
        scanf("%d",&respuesta);

        switch(respuesta)
        {
        case 1:

            for (i=0; i<tam; i++)
            {
                if(lista[i].id==legajo && lista[i].estado==1)
                {
                    modfEstructura(lista,i);

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


}

void modfEstructura(eEstudio lista[], int indice)
{
    int opcion;
    char auxNuevoNombre[51] ;
    char auxNuevoPais[51] ;
    int auxNuevoAnio;


    do
    {
        system("cls");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Pais\n");
        printf("3.Modificar Anio de creacion\n");
        printf("4.Salir\n");
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            getValidString("\nIngrese nuevo nombre de estudio : ","\nerror por favor solo ingrese caracteres","\nerror se exedio del limite de caracteres\n",auxNuevoNombre,1,50);
            fflush(stdin);

            stringToUpper(auxNuevoNombre);
            strcpy(lista[indice].nombre, auxNuevoNombre);
            break;

        case 2:

            getValidString("Ingrese nuevo pais : ","\nerror por favor solo ingrese caracteres","\nerror se exedio del limite de caracteres\n",auxNuevoPais,1,50);
            fflush(stdin);

            stringToUpper(auxNuevoPais);
            strcpy(lista[indice].pais, auxNuevoPais);
            break;

        case 3:
            printf("Ingrese nuevo anio: ");

            scanf("%d", &auxNuevoAnio );

            lista[indice].anioDeCreacion=auxNuevoAnio;
            break;
        case 7:

                printf("Datos modificados");

            break;
        default:
            printf("ERROR!! por favor ingrese una de las opciones validaas <1-4>\n");
            break;


        }


    }
    while(opcion!=4);

}
