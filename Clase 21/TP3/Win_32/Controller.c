#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN_INPUT.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f;

    f = fopen(path,"r");

    if(f!=NULL&& pArrayListEmployee !=NULL)
    {
        parser_EmployeeFromText(f,pArrayListEmployee);
    }
    else
    {
        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
        system("pause");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    fclose(f);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* f;
    f = fopen(path,"rb");

    if(f != NULL)
    {
        parser_EmployeeFromBinary(f,pArrayListEmployee);
    }
    else
    {
        printf("No se pudo abrir el archivo. Me voy a cerrar.\n");
        system("pause");
        fclose(f);
        exit(EXIT_FAILURE);

    }

    fclose(f);



    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int mayorIdEstudio(LinkedList* pArrayListEmployee)
{

    int flag = 0;
    int aux = 0;
    int len=ll_len(pArrayListEmployee);
    Employee* auxEmpleado;

    for(int i=0; i<len; i++)
    {

        auxEmpleado =ll_get(pArrayListEmployee,i);

        if(flag==0 || auxEmpleado->id > aux)
        {
            aux = auxEmpleado->id;
            flag = 1;
        }
    }
    return aux;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    char auxString[21];
    char auxSueldo[21];
    char auxHoras[21];
    char auxId[21];
    Employee* auxEmployee;

    getValidString("Ingrese Nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",auxString,1,51);
    getStringNumeros("Ingrese Sueldo :",auxSueldo);
    getStringNumeros("Ingrese Horas :",auxHoras);
    getStringNumeros("Ingrese Id :",auxId);

    auxEmployee=employee_newParametros(auxId,auxString,auxHoras,auxSueldo);


    ll_add(pArrayListEmployee,auxEmployee);













    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    empleado=employee_new();
    int len=ll_len(pArrayListEmployee);
    int idAuxiliar;
    char nombreAuxiliar[50];
    int horasAuxiliar;
    int sueldoAuxiliar;
    int contador =0;


    puts(" [ID]\t[NOMBRE]\t[HS TRABAJADAS]\t\t[SUELDO]\n\n");
    for(int i=0; i < len; i++)
    {
        empleado = (Employee*)ll_get(pArrayListEmployee, i);

        employee_getId(empleado, &idAuxiliar);
        employee_getNombre(empleado,nombreAuxiliar);
        employee_getHorasTrabajadas(empleado,&horasAuxiliar);
        employee_getSueldo(empleado,&sueldoAuxiliar);
        printf("%5d  %10s %10d  %20d\n",idAuxiliar, nombreAuxiliar, horasAuxiliar, sueldoAuxiliar);
        contador++;

        if(contador==298)
        {
            contador=0;
            system("pause");
        }
    }
    printf("\n\n");




    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ok = 1;

    int len;

    Employee* this;

    FILE* f;

    len =ll_len(pArrayListEmployee);

    f=fopen(path,"w");

    if(f != NULL && pArrayListEmployee != NULL)
    {

        fprintf(f, "id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i < len; i++)
        {
            this= (Employee*) ll_get(pArrayListEmployee,i);
            fprintf(f,"%d,%s,%d,%d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);


        }
    }
    else
    {
        ok = 0;

    }

    fclose(f);
    return ok;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ok = 1;
    FILE* f = fopen(path,"wb");
    int len =ll_len(pArrayListEmployee);
    Employee* this;
    if(f == NULL)
    {
        ok = 0;
        return ok;///Se puede usar pero es mala practica.
    }
    for(int i=0; i < len; i++)
    {
        this= (Employee*) ll_get(pArrayListEmployee,i);
        fwrite(this, sizeof(Employee), 1, f);
    }
    fclose(f);
    return ok;
    return 1;
}

