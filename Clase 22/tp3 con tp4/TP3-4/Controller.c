#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN_INPUT.h"



int controller_listExist(LinkedList* pArrayListEmployee)
{
    int existe = -1;
    int len =ll_len(pArrayListEmployee);


        if(len>0)
        {
            existe = 1;

        }


    return existe;
}


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Pfile = fopen(path,"r");
    int retorno=-1;

    if(Pfile!=NULL&& pArrayListEmployee !=NULL)
    {
        if(parser_EmployeeFromText(Pfile,pArrayListEmployee))
        {

            retorno=1;

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


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* Pfile = fopen(path,"rb");
    int retorno=-1;

    if(Pfile != NULL && pArrayListEmployee!=NULL )
    {
        if(parser_EmployeeFromBinary(Pfile,pArrayListEmployee))
        {

            retorno=1;

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


int controller_GetBiggestId(LinkedList* pArrayListEmployee)
{
   int flag = 0;
    int aux = 0;
    int len=ll_len(pArrayListEmployee);

    Employee* auxEmpleado=employee_new();

    if(pArrayListEmployee!=NULL && auxEmpleado!=NULL )
    {

    for(int i=0; i<len; i++)
    {

        auxEmpleado =ll_get(pArrayListEmployee,i);

        if(flag==0 || auxEmpleado->id > aux)
        {
            aux = auxEmpleado->id;
            flag = 1;
        }
    }

    }
    else
    {
        printf("Hubo un error en la lista");
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

    if(pArrayListEmployee!=NULL && auxEmployee!=NULL)
    {
        auxId=controller_GetBiggestId(pArrayListEmployee)+1;
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


int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int modfId;
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[21];

    int respuesta;
    int retorno=-1;
    int existeSocio=1;
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

                existeSocio=0;

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
    if(existeSocio==1)
    {
        printf("ERROR, el socio no existe\n");
    }


    return retorno;


}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int auxHoras;
    int auxSueldo;
    char auxNombre[21];

    int modfId;
    int respuesta;
    int retorno=-1;
    int existeEmpleado=1;
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

                existeEmpleado=0;
                fflush(stdin);
                getValidInt("Esta seguro que quiere darle de baja a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

                switch(respuesta)
                {
                case 1:
                    ll_remove(pArrayListEmployee,i);
                    free(auxEmployee);
                    printf("Baja Exitosa\n");
                    retorno=1;
                    break;
                case 2:
                    printf("Baja Cancelada\n");
                    retorno=0;
                    break;
                }

                break;
            }
        }

        if(existeEmpleado==1)
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


/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
system("cls");
    LinkedList* listaClonada;
    int retorno;
    int opcionOrden;
    int opcion;

    listaClonada= ll_clone(pArrayListEmployee);

    do
    {
        printf("///////////////ORDENAR EMPLEADOS///////////////\n\n");

        printf("\n1.Ordedar por Nombre\n");
        printf("2.Ordedar por Sueldo\n");
        printf("3.Ordedar por horas\n");
        printf("4.Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

    //1 DESCENDENTE MENOS EN STRCMP
    //0 ASCENDENTE MENOS EN STRCMP

        switch(opcion)
        {

    case 1:

         printf("\n1.ORDENAR DESCENDENTEMENTE\n");
        printf("\n2.ORDENAR ASCENDENTEMENTE\n");
        getValidInt("Ingrese una opcion :","error ingrese una opcion valida <1-2>",1,2,&opcionOrden);

        if(opcionOrden==1)
        {


            printf("ORDENANDO....\n");

         retorno = ll_sort(listaClonada,employee_compararPorNombre,1);
         controller_ListEmployee(listaClonada);

        }

        else if(opcionOrden==2)
        {
            printf("ORDENANDO....\n");

             retorno = ll_sort(listaClonada,employee_compararPorNombre,0);
            controller_ListEmployee(listaClonada);
        }

        break;
    case 2:

        printf("\n1.ORDENAR DESCENDENTEMENTE\n");
        printf("\n2.ORDENAR ASCENDENTEMENTE\n");
        getValidInt("Ingrese una opcion :","error ingrese una opcion valida <1-2>",1,2,&opcionOrden);

         if(opcionOrden==1)
        {
               printf("ORDENANDO....\n");

         retorno = ll_sort(listaClonada,employee_compararPorSueldo,1);
         controller_ListEmployee(listaClonada);

        }
        else if(opcionOrden==2)
        {
         printf("ORDENANDO....\n");

             retorno = ll_sort(listaClonada,employee_compararPorSueldo,0);
            controller_ListEmployee(listaClonada);
        }


        break;
    case 3:

         printf("\n1.ORDENAR DESCENDENTEMENTE\n");
        printf("\n2.ORDENAR ASCENDENTEMENTE\n");
        getValidInt("Ingrese una opcion :","error ingrese una opcion valida <1-2>",1,2,&opcionOrden);

        if(opcionOrden==1)
        {
               printf("ORDENANDO....\n");

         retorno = ll_sort(listaClonada,employee_compararPorHoras,1);
         controller_ListEmployee(listaClonada);

        }
        else if(opcionOrden==2)
        {
                printf("ORDENANDO....\n");

             retorno = ll_sort(listaClonada,employee_compararPorHoras,0);
            controller_ListEmployee(listaClonada);
        }


        break;
    case 4:

        printf("\nREGRESANDO AL MENU PRINCIPAL\n");

        break;
    default:
        printf("ERROR..Ingrese una opcion correcta <1-5>\n");

        }

        fflush(stdin);
        system("pause");
        system("cls");


    }while(opcion!=4);


    return retorno;
}*/


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
