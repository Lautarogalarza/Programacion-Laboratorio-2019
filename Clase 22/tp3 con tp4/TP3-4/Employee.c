#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "UTN_INPUT.h"


Employee* employee_new()
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));

    if(newEmployee!=NULL)
    {
        newEmployee->horasTrabajadas= 0;
        newEmployee->sueldo= 0;
        newEmployee->id= 0;
        strcpy(newEmployee->nombre,"");
    }

    return newEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployeeParam = employee_new();
    int retorno = 0;

    if(newEmployeeParam != NULL)
    {
        if(employee_setId(newEmployeeParam, atoi(idStr) ) )
        {
            if(employee_setNombre(newEmployeeParam, nombreStr))
            {
                if(employee_setSueldo(newEmployeeParam, atoi(sueldoStr) ) )
                {
                    if(employee_setHorasTrabajadas(newEmployeeParam, atoi(horasTrabajadasStr)   ) )
                    {
                        retorno = 1;
                    }
                }
            }
        }

        if(retorno == 0)
        {
            free(newEmployeeParam);
            newEmployeeParam = NULL;
        }
    }
    return newEmployeeParam;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno =0;

    if(this != NULL )
    {
        this->sueldo = sueldo;

        retorno=1;
    }

    return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno =0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;

        retorno=1;
    }

    return retorno;
}


int employee_setId(Employee* this,int id)
{
    int retorno =0;

    if(this != NULL)
    {
        this->id = id;
        retorno=1;
    }

    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno =0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;

        retorno=1;
    }

    return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {

        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);

        retorno=1;
    }

    return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno =0;

    if(this != NULL )
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno=1;
    }

    return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;

        retorno=1;
    }

    return retorno;
}


void employee_setEmployee(Employee* auxEmployee)
{
    int opcion;
    char auxNewName[31];
    char auxNewSueldo[31];
    char auxNewHoras[31];

    do
    {
        system("cls");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Sueldo\n");
        printf("3.Modificar Horas trabajadas\n");
        printf("4.Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:

            fflush(stdin);
            getValidString("Ingrese nuevo nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewName,1,30);
            stringToUpper(auxNewName);

            employee_setNombre(auxEmployee,auxNewName);

            printf("\nDato modificado\n");
            break;

        case 2:

            fflush(stdin);
            getValidStringNumeros("Ingrese nuevo Sueldo :","ERROR,ingrese el Sueldo nuevamente (solo numeros)","ERROR, se exedio del limite de numeros\n",auxNewSueldo,1,10);

            employee_setSueldo(auxEmployee,atoi(auxNewSueldo));

            printf("\nDato modificado\n");
            break;

        case 3:

            fflush(stdin);
            getValidStringNumeros("ingrese nuevas Horas :","ERROR, Ingrese las horas nuevamente (solo numeros)","ERROR, se exedio del limite de numeros\n",auxNewHoras,1,10);

            employee_setHorasTrabajadas(auxEmployee,atoi(auxNewHoras));

            printf("\nDato modificado\n");
            break;

        case 4:

            printf("REGRESANDO AL MENU PRINCIPAL\n");

            break;
        default:
            printf("ERROR!! por favor ingrese una de las opciones validaas <1-7>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=4);

}


 int employee_compararPorSueldo(void* personaA, void* personaB)
 {
     Employee* auxA =( Employee*)personaA;
     Employee* auxB =(Employee*)personaB;
     int aux;

     if(auxA->sueldo>auxB->sueldo)
     {
         aux=1;// si es mayor
     }
     else if(auxB->sueldo>auxA->sueldo)
     {
         aux=-1; // si es menor
     }
     else
     {
         aux=0; // si es igual
     }

     return aux;
 }


 int employee_compararPorHoras(void* personaA, void* personaB)
 {
     Employee* auxA =( Employee*)personaA;
     Employee* auxB =(Employee*)personaB;
     int aux;

     if(auxA->horasTrabajadas>auxB->horasTrabajadas)
     {
         aux=1;// si es mayor
     }
     else if(auxB->horasTrabajadas>auxA->horasTrabajadas)
     {
         aux=-1; // si es menor
     }
     else
     {
         aux=0; // si es igual
     }

     return aux;
 }

 int employee_compararPorNombre(void* personaA, void* personaB)
 {
     Employee* auxA =( Employee*)personaA;
     Employee* auxB =(Employee*)personaB;
     int aux;

     aux=strcmp(auxA->nombre,auxB->nombre);

     return aux;
 }
