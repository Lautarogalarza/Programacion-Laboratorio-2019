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
    printf("3- Modificar Empleados\n");
    printf("4- Baja Empleados\n");
    printf("5- Ordenar Empleados\n");
    printf("6- Salir\n\n");
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


int  inicializarEmpleados(eEmpleado lista[], int tam)
{
    int myReturn=-1;

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = VACIO;

        myReturn=0;
    }

    return myReturn;
}


void initEmp(eEmpleado lista[])
{
    int auxLegajo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char auxNombre[10][51]= {"Lautaro","Jose","Martin","Pepe","Claudia","Florencia","Miguel","Yanina","Mateo","Miriam"};
    char auxApellido[10][51]= {"Galarza","Perez","Caridades","Ruiz","Silva","Sanchez","Garcia","Diaz","Liso","Pinno"};
    char auxSexo[10]= {'M','M','M','M','F','F','M','F','M','F'};
    float auxSalario[10] = { 23.500, 34.000, 45.000, 24.000, 12.000, 28.000, 32.000, 16.000, 28.500, 58.000};
    int auxSector[10] = {1, 2, 3, 4, 5, 3, 4, 1, 5, 2};
    eFecha auxFecha[10]= {  {9,5,1999},{1,7,2001},{2,7,2010},{24,1,1985},{15,5,2006},{12,12,1991},{28,3,2018},{7,11,2012},{5,2,1975},{13,3,1997} };


    for(int i=0; i<10; i++)
    {
        lista[i].legajo=auxLegajo[i];

        strcpy(lista[i].nombre, auxNombre[i]);
        strcpy(lista[i].apellido, auxApellido[i]);

        lista[i].sexo=auxSexo[i];
        lista[i].salario=auxSalario[i];
        lista[i].idSector=auxSector[i];
        lista[i].fechaIngreso=auxFecha[i];

        generarNextId();

        lista[i].isEmpty=OCUPADO;



    }
}


int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarEmpleadoPorId(eEmpleado lista[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO && lista[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int hayEmpleadosCargados(eEmpleado lista[], int tam)
{
    int hayEmpleados = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            hayEmpleados = 0;
            break;
        }
    }

    return hayEmpleados;
}


int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}


int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int respuesta;
    char auxNombre[51] ;
    char auxApellido[51] ;
    char auxSexo;
    int auxSector;
    float auxSalario;
    int myReturn=-1;


    indice = buscarLibre(lista, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {



        fflush(stdin);
        getValidString("\nIngrese nombre: ","\nError por favor solo ingrese caracteres","\nError se exedio del limite de caracteres\n",auxNombre,1,50);
        stringToUpper(auxNombre);

        strcpy(lista[indice].nombre,auxNombre);


        fflush(stdin);
        getValidString("Ingrese apellido: ","\nError por favor solo ingrese caracteres","\nError se exedio del limite de caracteres\n",auxApellido,1,50);
        stringToUpper(auxApellido);

        strcpy(lista[indice].apellido,auxApellido);


        fflush(stdin);
        getSexChar("ingrese sexo","Error ingrese sexo valido <F-M>\n",&auxSexo);

        lista[indice].sexo=auxSexo;

        fflush(stdin);
        getValidFloat("Ingrese salario: ","\Eerror, solo numeros por favor\n",12.000,99.999,&auxSalario);

        lista[indice].salario=auxSalario;

        printf("\nIngrese su fecha de ingreso\n\n");
        cargarFecha(lista,indice);

        system("cls");
        mostrarSectores(sectores,tamSector);

        getValidInt("ingrese sector","\Eerror ingrese un sector valido  <1-5>\n",1,5,&auxSector);

        lista[indice].idSector=auxSector;

        fflush(stdin);
        getValidInt("Esta seguro que quiere darle de alta a este empleado? <1.Si-2.No>","\Eerror ingrese un dato valido  <1-2>\n",1,2,&respuesta);


        if(respuesta==1)
        {

            lista[indice].isEmpty = OCUPADO;

            lista[indice].legajo=generarNextId();

            printf("Alta empleado exitosa!!!\n\n");

            myReturn=0;

        }
        else
        {

            printf("alta cancelada");

        }
    }

    return myReturn;
}


void mostrarEmpleado(eSector sectores[], int tamSector, eEmpleado lista)
{
    char nombreSector[20];

    obtenerSector(sectores, tamSector, lista.idSector, nombreSector);

    printf("%2d   %15s   %7s   %5c   %10.2f %s  %d/%d/%d\n", lista.legajo, lista.nombre,lista.apellido, lista.sexo, lista.salario, nombreSector,lista.fechaIngreso.dia,lista.fechaIngreso.mes,lista.fechaIngreso.anio);

}


int mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{

    int retorno=-1;

    printf(" Legajo      Nombre    Apellido    Sexo    Salario   Sector  Fecha de ingreso\n\n");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            mostrarEmpleado(sectores,tamSector,lista[i]);

            retorno=0;
        }
    }

    if( retorno == -1)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    return retorno;
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


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&auxDia);

    lista[indice].fechaIngreso.dia=auxDia;


    getValidInt("Ingrese mes:","Por favor ingrese un mes valido entre 1 y 12: \n",1,12,&auxMes);

    lista[indice].fechaIngreso.mes=auxMes;


    getValidInt("Ingrese anio: ","Por favor ingrese un anio valido entre 1960 y 2030: \n",1960,2030,&auxAnio);

    lista[indice].fechaIngreso.anio=auxAnio;
}


int  modificarEmpleado(eEmpleado lista[], int tam, eSector listaSector[] ,int tamSector)
{
    int respuesta;
    int auxLegajo;
    int i;
    int indice;
    int existeEmpleado=0;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            printf("\nLegajo empleado %d",lista[i].legajo);
        }
    }

    printf("\nQue empleado queres modificar? (Ingresar Legajo Usuario) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);


    indice=buscarEmpleadoPorId(lista,tam,auxLegajo);

    if(auxLegajo==lista[indice].legajo && lista[indice].isEmpty==OCUPADO)
    {
        existeEmpleado=1;

        fflush(stdin);
        getValidInt("Esta seguro que quiere modificar a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

        switch(respuesta)
        {
        case 1:

            modfEmpleado(lista,indice,listaSector,tamSector);
            retorno=0;

            break;
        case 2:

            printf("Modificacion cancelada");
            retorno=-1;
            break;

        }
    }

    if(existeEmpleado==0)
    {
        printf("ERROR, el empleado no existe\n");
    }


    return retorno;

}


void modfEmpleado(eEmpleado lista[], int indice, eSector listaSector[] ,int tamSector)
{
    int opcion;
    char auxNewName[51];
    char auxNewLastName[51];
    char auxNewSex;
    float auxNewSalary;
    int auxNewSector;


    do
    {
        system("cls");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Apellido\n");
        printf("3.Modificar Salario\n");
        printf("4.Modificar Sexo\n");
        printf("5.Modificar Sector\n");
        printf("6.Modificar Fecha de ingreso\n");
        printf("7.Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:

            fflush(stdin);
            getValidString("Ingrese nuevo nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewName,1,51);
            stringToUpper(auxNewName);

            strcpy(lista[indice].nombre,auxNewName);

            printf("\nDato modificado\n");
            break;

        case 2:

            fflush(stdin);
            getValidString("Ingrese nuevo apellido :","ERROR,ingrese el apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewLastName,1,51);
            stringToUpper(auxNewLastName);
            strcpy(lista[indice].apellido, auxNewLastName);

            printf("\nDato modificado\n");
            break;

        case 3:

            fflush(stdin);
            getValidFloat("Ingrese nuevo salario :","ERROR ingrese el salario nuevamente (solo numeros)",0,1000000,&auxNewSalary);
            lista[indice].salario=auxNewSalary;

            printf("\nDato modificado\n");
            break;
        case 4:

            fflush(stdin);
            getSexChar("ingrese nuevo sexo","Error ingrese sexo valido <F-M>\n",&auxNewSex);
            lista[indice].sexo=auxNewSex;

            printf("\nDato modificado\n");
            break;
        case 5:
            system("cls");
            mostrarSectores(listaSector,tamSector);

            fflush(stdin);
            getValidInt("ingrese nuevo sector","\Eerror ingrese un sector valido  <1-5>\n",1,5,&auxNewSector);
            lista[indice].idSector=auxNewSector;

            printf("\nDato modificado\n");
            break;
        case 6:

            printf("Ingrese nueva fecha de ingreso");
            cargarFecha(lista,indice);

            break;
        case 7:

            printf("REGRESANDO AL MENU PRINCIPAL");

            break;
        default:
            printf("ERROR!! por favor ingrese una de las opciones validaas <1-7>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=7);

}


int bajaEmpleado(eEmpleado lista[], int tam)
{
    int auxLegajo;
    int respuesta;
    int i;
    int retorno=-1;
    int existeEmpleado=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            printf("\nLegajo empleado %d",lista[i].legajo);
        }
    }

    printf("\nQue empleado queres dar de baja? (Ingresar ID Usuario) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);


    for(i=0; i<tam; i++)
    {
        if(auxLegajo==lista[i].legajo && lista[i].isEmpty==OCUPADO)
        {
            existeEmpleado=1;
            fflush(stdin);
            getValidInt("Esta seguro que quiere darle de baja a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

            switch(respuesta)
            {
            case 1:
                lista[i].isEmpty=VACIO;
                retorno=0;
                printf("Baja Exitosa\n");
                break;
            case 2:
                printf("Baja Cancelada");
                break;

            }

            break;
        }
    }

     if(existeEmpleado==0)
    {
        printf("ERROR, el empleado no existe\n");
    }

 return retorno;
}


int ordenarEmpleados(eEmpleado lista[],int tam )
{
    eEmpleado auxEmp;
    int retorno=-1;

    for(int i =0 ; i<tam-1 ; i ++)
    {
        for(int j= i+1 ; j<tam; j++)
        {
            if(strcmp(lista[j].apellido,lista[i].apellido)<0)
            {
                auxEmp = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmp;
            }
            else if(strcmp(lista[j].apellido,lista[i].apellido) ==0 && strcmp(lista[j].nombre,lista[i].nombre)<0)
            {
                auxEmp = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmp;
            }
        }

        retorno=0;
    }

    return retorno;
}





/*int altaAlmuerzo(eAlmuerzo lista[], int tam,eEmpleado listaEmpleado[], int tamEmpleado)
{
    int indice;
    int respuesta;
    int auxLegajo;
    int auxIdMenu;
    int myReturn=-1;


    indice = buscarLibre(lista, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {



        fflush(stdin);
        getValidString("\nIngrese nombre: ","\nError por favor solo ingrese caracteres","\nError se exedio del limite de caracteres\n",auxNombre,1,50);
        stringToUpper(auxNombre);

        strcpy(lista[indice].nombre,auxNombre);


        fflush(stdin);
        getValidString("Ingrese apellido: ","\nError por favor solo ingrese caracteres","\nError se exedio del limite de caracteres\n",auxApellido,1,50);
        stringToUpper(auxApellido);

        strcpy(lista[indice].apellido,auxApellido);


        fflush(stdin);
        getSexChar("ingrese sexo","Error ingrese sexo valido <F-M>\n",&auxSexo);

        lista[indice].sexo=auxSexo;

        fflush(stdin);
        getValidFloat("Ingrese salario: ","\Eerror, solo numeros por favor\n",12.000,99.999,&auxSalario);

        lista[indice].salario=auxSalario;

        printf("\nIngrese su fecha de ingreso\n\n");
        cargarFecha(lista,indice);

        system("cls");
        mostrarSectores(sectores,tamSector);

        getValidInt("ingrese sector","\Eerror ingrese un sector valido  <1-5>\n",1,5,&auxSector);

        lista[indice].idSector=auxSector;

        fflush(stdin);
        getValidInt("Esta seguro que quiere darle de alta a este empleado? <1.Si-2.No>","\Eerror ingrese un dato valido  <1-2>\n",1,2,&respuesta);


        if(respuesta==1)
        {

            lista[indice].isEmpty = OCUPADO;

            lista[indice].legajo=generarNextId();

            printf("Alta empleado exitosa!!!\n\n");

            myReturn=0;

        }
        else
        {

            printf("alta cancelada");

        }
    }

    return myReturn;
}*/















