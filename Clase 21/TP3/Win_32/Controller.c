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

    char bufferString[21];
    char bufferSueldo[21];
    char bufferHoras[21];
    int auxId;
    char bufferId[21];
    int retorno;
    Employee* auxEmployee;

    auxEmployee=employee_new();

    if(pArrayListEmployee!=NULL&&auxEmployee!=NULL)
    {
    auxId=mayorIdEstudio(pArrayListEmployee)+1;
    sprintf(bufferId, "%d", auxId);



    getValidString("Ingrese Nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena\n",bufferString,1,51);

    getValidStringNumeros("Ingrese Sueldo :","ERROR, Ingrese el sueldo nuevamente (solo numeros)","ERROR, se exedio del limite de numerosa\n",bufferSueldo,1,2147483647);

    getValidStringNumeros("Ingrese las horas trabajadas :","ERROR, Ingrese las horas nuevamente (solo numeros)","ERROR, se exedio del limite de numerosa\n",bufferHoras,1,2147483647);




    auxEmployee=employee_newParametros(bufferId,bufferString,bufferHoras,bufferSueldo);


    ll_add(pArrayListEmployee,auxEmployee);

     retorno=1;

    }
    else
    {
        printf("hubo un error en la carga");

         retorno=0;
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
    int auxLegajo;
    int auxId;
    int respuesta;
    int retorno=-1;
    int existeSocio=0;
    int len;
    int contador=0;
    Employee* auxEmployee;

    len=ll_len(pArrayListEmployee);

    for(int i=0; i<len; i++)
    {

        auxEmployee=ll_get(pArrayListEmployee,i);

        employee_getId(auxEmployee,&auxId);

        printf("\nLegajo socio %d",auxId);

        contador++;

        if(contador==200)
        {
            contador=0;
            system("pause");
        }

    }

    printf("\nQue socio queres dar de baja? (Ingresar ID socio) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);


    for(int i=0; i<len; i++)
    {
        auxEmployee=ll_get(pArrayListEmployee,i);

        employee_getId(auxEmployee,&auxId);

        if(auxLegajo==auxId)
        {
            existeSocio=1;
            fflush(stdin);
            getValidInt("Esta seguro que quiere darle de baja a este socio? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

            switch(respuesta)
            {
            case 1:
                ll_remove(pArrayListEmployee,i);
                retorno=0;
                printf("Baja Exitosa\n");
                break;
            case 2:
                printf("Baja Cancelada\n");
                break;

            }

            break;
        }
    }

    if(existeSocio==0)
    {
        printf("ERROR, el socio no existe\n");

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

        if(contador==200)
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
}





int  modificar_Socios(LinkedList* pArrayListEmployee)
{
    int auxLegajo;
    int auxId;
    int respuesta;
    int retorno=-1;
    int existeSocio=0;
    int len;
    int contador=0;
    Employee* auxEmployee;

    len=ll_len(pArrayListEmployee);

    for(int i=0; i<len; i++)
    {

        auxEmployee=ll_get(pArrayListEmployee,i);

        employee_getId(auxEmployee,&auxId);

        printf("\nLegajo socio %d",auxId);

        contador++;

        if(contador==200)
        {
            contador=0;
            system("pause");
        }

    }

    printf("\nQue socio queres modificar? (Ingresar Codigo socio) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);

    for(int i=0; i<len; i++)
    {
        auxEmployee=ll_get(pArrayListEmployee,i);

        employee_getId(auxEmployee,&auxId);

    if(auxLegajo==auxId)
    {


        existeSocio=1;

        fflush(stdin);
        getValidInt("Esta seguro que quiere modificar a este socio? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

        switch(respuesta)
        {
        case 1:

            modf_Socios(auxEmployee);
            retorno=0;

            break;
        case 2:

            printf("Modificacion cancelada");
            retorno=-1;
            break;

        }
    }
}
    if(existeSocio==0)
    {
        printf("ERROR, el socio no existe\n");
    }


    return retorno;

}

void modf_Socios(Employee* auxEmployee)
{
    int opcion;
    char auxNewName[31];
    char auxNewSueldo[31];
    char auxNewHoras[31];




    do
    {
        system("cls");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Email\n");
        printf("3.Modificar Fecha de ingreso\n");
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
            getValidStringNumeros("Ingrese nuevo apellido :","ERROR,ingrese el apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewSueldo,1,2147483647);
            stringToUpper(auxNewSueldo);

            employee_setHorasTrabajadas(auxEmployee,atoi(auxNewSueldo));

            printf("\nDato modificado\n");
            break;

        case 3:

            fflush(stdin);
            getValidStringNumeros("ingrese telefono (debe tener un guion y 6 numeros): ","ERROR, Ingrese el sueldo nuevamente (solo numeros)","ERROR, se exedio del limite de numerosa\n",auxNewHoras,1,2147483647);

            employee_setSueldo(auxEmployee,atoi(auxNewHoras));

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

