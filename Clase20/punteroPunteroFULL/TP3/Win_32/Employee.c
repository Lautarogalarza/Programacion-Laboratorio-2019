#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

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

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    Employee* newEmployeeParam = (Employee*)malloc(sizeof(Employee));
    int todoOk=0;
    if(newEmployeeParam!=NULL)
    {

        if(employee_setId(newEmployeeParam,atoi(idStr))
        {
            if(employee_setNombre(newEmployeeParam,nombreStr))
            {
                if(employee_setHorasTrabajadas(newEmployeeParam,atoi(horasTrabajadasStr))
            {
                if(employee_setSueldo(newEmployeeParam,atoi(sueldoStr))
                    {

                        todoOk=1;

                    }
                }
            }

            if (todoOk==0)
            {
                free(newEmployeeParam);
                newEmployeeParam = NULL;
            }

        }





        newEmployeeParam->id=atoi(idStr);

        newEmployeeParam->sueldo= atoi(sueldoStr);

        newEmployeeParam->id= atoi(horasTrabajadasStr);

        strcpy(newEmployeeParam->nombre,nombreStr);

    }

    return newEmployeeParam;

}



//ESCRIBE EN EL CAMPO
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk =0;

    if(this != NULL && sueldo>0 && sueldo < 100000)
    {
        this->sueldo = sueldo;
        todoOk=1;
    }

    return todoOk;
}

//LEE EL CAMPO
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk =0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;

        todoOk=1;
    }

    return todoOk;



}

int employee_setId(Employee* this,int id)
{
    int todoOk =0;

    if(this != NULL && id>0 )
    {
        this->id = id;
        todoOk=1;
    }

    return todoOk;
}

//LEE EL CAMPO
int employee_getId(Employee* this,int* id)
{
    int todoOk =0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;

        todoOk=1;
    }

    return todoOk;



}
