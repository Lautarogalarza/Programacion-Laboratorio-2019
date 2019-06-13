#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    FILE* Pfile = fopen(path,"r");
    int retorno=-1;

    if(Pfile!=NULL&& pArrayListEmployee !=NULL)
    {
        if(parser_EmployeeFromText(Pfile,pArrayListEmployee))
        {

            retorno=1;
            printf("\n Empleados cargados correctamente (modo texto).\n\n");

        }

        else
        {
            retorno =-1;
        }

    }

    else
    {
        retorno =-1;
    }

    fclose(Pfile);
    free(Pfile);


    return retorno;
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
    FILE* Pfile = fopen(path,"rb");
    int retorno=-1;

    if(Pfile != NULL && pArrayListEmployee!=NULL )
    {
        if(parser_EmployeeFromBinary(Pfile,pArrayListEmployee))
        {

            retorno=1;
            printf("\n Empleados cargados correctamente (modo binario).\n\n");

        }

        else
        {
            retorno=-1;
        }
    }

    else
    {
        retorno =-1;
    }

    fclose(Pfile);
    free(Pfile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_GetBiggestId(LinkedList* pArrayListEmployee)
{
    int flag = 0;
    int auxId = 0;
    int len = ll_len(pArrayListEmployee);

    Employee* auxEmployee = employee_new();

    if(pArrayListEmployee!=NULL && auxEmployee!=NULL )
    {

        for(int i=0; i<len; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);

            if(flag==0 || auxEmployee->id > auxId)
            {
                employee_getId(auxEmployee,&auxId);

                flag = 1;
            }
        }

    }

    else
    {
        printf("Hubo un error en la lista");
    }

    free(auxEmployee);

    return auxId;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char bufferString[21];
    char bufferSueldo[21];
    char bufferHoras[21];
    int auxId;
    char bufferId[21];
    int retorno=-1;
    Employee* newEmployee = employee_new();

    if(pArrayListEmployee!=NULL && newEmployee!=NULL)
    {
        auxId=controller_GetBiggestId(pArrayListEmployee)+1;
        sprintf(bufferId, "%d", auxId);


        getValidString("Ingrese Nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",bufferString,1,51);
        stringToUpper(bufferString);

        getValidStringNumeros("Ingrese Sueldo :","ERROR, Ingrese el sueldo nuevamente (solo numeros)","ERROR, se exedio del limite de numeros\n",bufferSueldo,1,6);

        getValidStringNumeros("Ingrese las horas trabajadas :","ERROR, Ingrese las horas nuevamente (solo numeros)","ERROR, se exedio del limite de numeros\n",bufferHoras,1,6);


        newEmployee=employee_newParametros(bufferId,bufferString,bufferHoras,bufferSueldo);

        if(newEmployee!=NULL)
        {

        ll_add(pArrayListEmployee,newEmployee);
        retorno=1;
        printf("\n Carga exitosa.\n\n");

        }

    }

    else
    {
        retorno=-1;
    }

    return retorno;
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
    int modfId;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[21];

    int respuesta;
    int retorno=-1;
    int existeSocio=0;
    int len;
    Employee* auxEmployee=employee_new();

if(pArrayListEmployee!=NULL && auxEmployee!=NULL)
    {

    len=ll_len(pArrayListEmployee);

    printf("\nQue socio queres modificar? (Ingresar Codigo socio) ");
    fflush(stdin);
    scanf("%d",&modfId);

    for(int i=0; i<len; i++)
    {
        auxEmployee=ll_get(pArrayListEmployee,i);

        employee_getId(auxEmployee,&auxId);

        if(modfId==auxId)
        {

            employee_getId(auxEmployee,&auxId);
            employee_getNombre(auxEmployee,auxNombre);
            employee_getHorasTrabajadas(auxEmployee,&auxHoras);
            employee_getSueldo(auxEmployee,&auxSueldo);

            printf("\n\n%d,%s,%d,%d\n\n",auxId,auxNombre,auxHoras,auxSueldo);

            existeSocio=1;

            fflush(stdin);
            getValidInt("Esta seguro que quiere modificar a este socio? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

            switch(respuesta)
            {
            case 1:

                employee_setEmployee(auxEmployee);
                retorno=1;
                break;
            case 2:
                printf("Modificacion cancelada");
                break;

            }
        }
    }


    }
    else
    {
        retorno=-1;
    }
    if(existeSocio==0)
    {
        printf("ERROR, el socio no existe\n");
    }


    return retorno;

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
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[21];

    int modfId;
    int respuesta;
    int retorno=-1;
    int existeEmpleado=0;
    int len;
    Employee* auxEmployee=employee_new();

    if(pArrayListEmployee!=NULL && auxEmployee!=NULL)
    {
        printf("\nQue socio queres dar de baja? (Ingresar ID socio) ");
        fflush(stdin);
        scanf("%d",&modfId);

        len=ll_len(pArrayListEmployee);

        for(int i=0; i<len; i++)
        {
            auxEmployee=ll_get(pArrayListEmployee,i);
            employee_getId(auxEmployee,&auxId);

            if(modfId==auxId)
            {
                employee_getId(auxEmployee,&auxId);
                employee_getNombre(auxEmployee,auxNombre);
                employee_getHorasTrabajadas(auxEmployee,&auxHoras);
                employee_getSueldo(auxEmployee,&auxSueldo);

                printf("\n\n%d,%s,%d,%d\n\n",auxId,auxNombre,auxHoras,auxSueldo);

                existeEmpleado=1;
                fflush(stdin);
                getValidInt("Esta seguro que quiere darle de baja a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);
                retorno=1;

                switch(respuesta)
                {
                case 1:
                    ll_remove(pArrayListEmployee,i);
                    free(auxEmployee);
                    printf("Baja Exitosa\n");
                    break;
                case 2:
                    printf("Baja Cancelada\n");
                    break;
                }

                break;
            }
        }

        if(existeEmpleado==0)
        {
            printf("ERROR, el empleado no existe\n");
        }
    }

    else
    {
        retorno=-1;
    }

    return retorno;
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
    Employee* empleado = employee_new();
    int len = ll_len(pArrayListEmployee);
    int idAuxiliar;
    char nombreAuxiliar[50];
    int horasAuxiliar;
    int sueldoAuxiliar;
    int contador = 0;
    int retorno=-1;

    if(empleado!=NULL && pArrayListEmployee!=NULL)
    {
        puts(" [ID]\t[NOMBRE]\t[HS TRABAJADAS]\t\t[SUELDO]\n\n");

        for(int i=0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);

            employee_getId(empleado, &idAuxiliar);
            employee_getNombre(empleado,nombreAuxiliar);
            employee_getHorasTrabajadas(empleado,&horasAuxiliar);
            employee_getSueldo(empleado,&sueldoAuxiliar);

            printf("%5d  %10s %10d  %20d\n",idAuxiliar, nombreAuxiliar, horasAuxiliar, sueldoAuxiliar);

            contador++;

            if(contador==150)
            {
                contador=0;
                system("pause");
            }
        }

        retorno=1;
    }

    else
    {
        retorno=-1;
    }

    printf("\n\n");

    return retorno;
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

    LinkedList* listaClonada;
    int retorno;

    listaClonada= ll_clone(pArrayListEmployee);

    retorno = ll_sort(listaClonada,controller_compararPorId,1);

    controller_ListEmployee(listaClonada);

    return 1;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


 int controller_compararPorId(void* personaA, void* personaB)
 {
     Employee* auxA =( Employee*)personaA;
     Employee* auxB =(Employee*)personaB;
     int aux;

     if(auxA->id>auxB->id)
     {
         aux=-1;// si es mayor
     }
     else if(auxA->id<auxB->id)
     {
         aux=1; // si es menor
     }
     else
     {
         aux=0; // si es igual
     }

     return aux;
 }


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    int idAuxiliar;
    char nombreAuxiliar[50];
    int horasAuxiliar;
    int sueldoAuxiliar;
    FILE* Pfile = fopen(path,"w");
    Employee* auxEmployee=employee_new();

    if(Pfile != NULL && pArrayListEmployee != NULL && auxEmployee!=NULL )
    {
        len=ll_len(pArrayListEmployee);
        fprintf(Pfile, "id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<len; i++)
        {
            auxEmployee= ll_get(pArrayListEmployee,i);

            employee_getId(auxEmployee, &idAuxiliar);
            employee_getNombre(auxEmployee,nombreAuxiliar);
            employee_getHorasTrabajadas(auxEmployee,&horasAuxiliar);
            employee_getSueldo(auxEmployee,&sueldoAuxiliar);

            fprintf(Pfile,"%d,%s,%d,%d\n",idAuxiliar,nombreAuxiliar,horasAuxiliar,sueldoAuxiliar);

        }

        retorno = 1;
        printf("\n Empleados cargados correctamente (modo binario).\n\n");
    }
    else
    {
        retorno=-1;
    }

    fclose(Pfile);
    free(auxEmployee);
    free(Pfile);

    return retorno;
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
    int retorno=-1;
    FILE* Pfile = fopen(path,"wb");
    Employee* auxEmployee= employee_new();
    int len;

    if(pArrayListEmployee!=NULL && auxEmployee!=NULL && Pfile!=NULL )
    {
        len=ll_len(pArrayListEmployee);

        for(int i=0; i < len; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            fwrite(auxEmployee, sizeof(Employee), 1, Pfile);
        }

        retorno = 1;
        printf("\n Empleados guardados correctamente (modo texto).\n\n");

    }

    else
    {
        retorno=-1;
    }

    fclose(Pfile);
    free(auxEmployee);
    free(Pfile);

    return retorno;
}
