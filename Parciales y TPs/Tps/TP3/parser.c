#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][20];
    Employee* newEmployee;
    int cant;
    int retorno;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while( !feof(pFile) )
    {
        newEmployee=employee_new();

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if( cant == 4)
        {

         newEmployee = employee_newParametros(buffer[0], buffer[1],buffer[2],buffer[3]);

         ll_add(pArrayListEmployee,newEmployee);
         retorno=1;

        }
        else
        {
            retorno=-1;

        }

    }

    return retorno;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    int cant;
    int retorno;

    while(!feof(pFile))
    {
        newEmployee=employee_new();

        cant=fread(newEmployee,sizeof(Employee),1,pFile);

        if (cant==1)
        {
            ll_add(pArrayListEmployee,newEmployee);
            retorno=1;
        }

        else
        {
            retorno=-1;
        }

    }

    return retorno;
}
