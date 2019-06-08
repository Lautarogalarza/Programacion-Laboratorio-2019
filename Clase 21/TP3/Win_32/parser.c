#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][20];
    Employee* nuevoEmpleado;
    int cant;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    //printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    while( !feof(pFile) )
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if( cant == 4)
        {
         nuevoEmpleado = employee_newParametros(buffer[0], buffer[1],buffer[2],buffer[3]);

       ll_add(pArrayListEmployee,nuevoEmpleado);
        }
        else
        {
            printf("\n ERROR. No se ha leido correctamente.\n\n");
            exit(1);

        }










    }


    printf("\n Empleados cargados correctamente (modo texto).\n\n");
    fclose(pFile);



    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* nuevoEmpleado;




    while( !feof(pFile) && pArrayListEmployee!=NULL )
    {

        nuevoEmpleado = employee_new();

     fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

    ll_add(pArrayListEmployee,nuevoEmpleado);


    }



     printf("\n Empleados cargados correctamente (modo binario).\n\n");
     fclose(pFile);
     free(pFile);


    return 1;
}
