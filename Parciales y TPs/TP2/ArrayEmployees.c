#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"


int initEmployees(Employee* list, int len)
{

    int myReturn=-1;
    for(int i=0; i < len; i++)
    {
        list[i].isEmpty = VACIO;

        myReturn=0;
    }

    return myReturn;
}


int findFreeSpace(Employee* list, int len)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == VACIO)
        {
            index = i;
            break;
        }
    }

    return index;
}


int generateNextId()

{

    static int id=0;

    id ++;

    return id;
}


int addEmployee(Employee* list, int len,int id,char name[],char lastName[],float salary,int sector)
{
    int index;
    int myReturn=-1;

    index = findFreeSpace(list, len);

    if( index == -1)
    {
     printf("\nERROR No hay lugar en el sistema!!!!\n");
    }
    else
    {
        list[index].id=id;

        strcpy(list[index].name,name);

        strcpy(list[index].lastName,lastName);

        list[index].salary=salary;

        list[index].sector=sector;

        list[index].isEmpty = OCUPADO;

        myReturn=0;

        printf("\nALTA EXITOSA\n");

    }

    return myReturn;
}


void  printEmployee(Employee list)
{
    printf("%3d %10s %10s  %10.3f %10d\n",list.id,list.name,list.lastName,list.salary,list.sector);
}


int printEmployees(Employee* list, int len)
{
    int myReturn = -1;

    printf(" ID      Nombre    Apellido    Salario     Sector  \n\n");
    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            printEmployee(list[i]);

            myReturn=0;
        }
    }

    if( myReturn == -1)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    return myReturn;
}


int findEmployeeById(Employee* list, int len, int id)

{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}


int removeEmployee(Employee* list, int len)
{
    int auxId;
    int answer;
    int i;
    int myReturn=-1;
    int employeeExist=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            printf("\nID empleado %d",list[i].id);
        }
    }

    printf("\nQue empleado desea dar de baja? (Ingresar ID empleado): ");
    fflush(stdin);
    scanf("%d",&auxId);

    for(i=0; i<len; i++)
    {
        if(auxId==list[i].id && list[i].isEmpty==OCUPADO)
        {
            employeeExist=1;
            fflush(stdin);
            getValidInt("Esta seguro que quiere darle de baja a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&answer);

            switch(answer)
            {
            case 1:
                list[i].isEmpty=VACIO;
                myReturn=0;
                printf("Baja Exitosa\n");
                break;

                break;
            case 2:
                printf("Baja Cancelada\n");
                 myReturn=-1;
                break;
            }

            break;
        }

    }

    if(employeeExist==0)
    {
        printf("ERROR, el empleado no existe\n");
    }

    return myReturn;
}



int modifyEmployee(Employee* list, int len)
{
    int answer;
    int auxId;
    int i;
    int index;
    int myReturn=-1;
    int employeeExist=0;


    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            printf("\nID empleado %d",list[i].id);
        }
    }

    printf("\nQue empleado quiere modificar? (Ingresar ID empleado) ");
    fflush(stdin);
    scanf("%d",&auxId);

    index=findEmployeeById(list,len,auxId);

    if(auxId==list[index].id && list[index].isEmpty==OCUPADO)
    {
        employeeExist=1;

        fflush(stdin);
        getValidInt("Esta seguro que quiere modificar a este empleado? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&answer);

        switch(answer)
        {
        case 1:
            modfEmpleado(list,index);
            myReturn=0;
            break;
        case 2:
            printf("Modificacion cancelada\n");
            myReturn=-1;
            break;
        }
    }

    if(employeeExist==0)
    {
        printf("ERROR, el empleado no existe\n");
    }

    return myReturn;
}



void modfEmpleado(Employee* list, int index)
{
    int option;
    char auxNewName[51];
    char auxNewLastName[51];
    float auxNewSalary;
    int auxNewSector;

    do
    {
        system("cls");
        printf("  *** MODIFICAR ***\n\n");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Apellido\n");
        printf("3.Modificar Salario\n");
        printf("4.Modificar Sector\n");
        printf("5.Salir\n");
        fflush(stdin);
        scanf("%d",&option);

        switch(option)
        {
        case 1:

            fflush(stdin);
            getValidString("Ingrese nuevo nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewName,1,51);
            stringToUpper(auxNewName);
            strcpy(list[index].name,auxNewName);

            printf("\nDato modificado\n");
            break;

        case 2:

            fflush(stdin);
            getValidString("Ingrese nuevo apellido :","ERROR,ingrese el apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewLastName,1,51);
            stringToUpper(auxNewLastName);
            strcpy(list[index].lastName, auxNewLastName);

            printf("\nDato modificado\n");
            break;

        case 3:

            fflush(stdin);
            getValidFloat("Ingrese nuevo salario :","ERROR ingrese el salario nuevamente (solo numeros)",0,1000000,&auxNewSalary);
            list[index].salary=auxNewSalary;

            printf("\nDato modificado\n");
            break;
        case 4:

            fflush(stdin);
            getValidInt("Ingrese nuevo sector :","ERROR ingrese el sector nuevamente <1-10>",1,10,&auxNewSector);
            list[index].sector=auxNewSector;

            printf("\nDato modificado\n");
            break;
        case 5:
                printf("\nModificacion Exitosa\n");
            break;
        default:
            printf("\nERROR!! por favor ingrese una de las opciones validaas <1-5>\n");
            break;


        }

        fflush(stdin);
        system("pause");
        system("cls");


    }
    while(option!=5);

}


void menuReport(Employee* list,int len)
{
    int option;
    int order;

    do
    {

        system("cls");
        printf("  *** INFORMES ***\n\n");
        printf("1- Ordenar por apellido y sector\n");
        printf("2- Total y promedio de los salarios\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)

        {
        case 1:
            fflush(stdin);
            getValidInt("Ingrese el orden <1-Ascendente_2-Descendente>","ERROR ingrese el orden nuevamente <1-2>",1,2,&order);

            sortEmployees(list,len,order);
            break;
        case 2:
            findSalaryMax(list,len);
            break;
        case 3:
            printf("\nREGRESANDO AL MENU PRINCIPAL\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-7>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=3);
}


void findSalaryMax(Employee*list,int len)
{
    float averageSalary=0;
    int overAverageCounter=0;
    float totalSalary=0;
    int employeeQuantity=0;
    int i;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {

            totalSalary = list[i].salary + totalSalary;

            employeeQuantity++;

            flag=1;
        }
    }

    if(flag==1)
    {
        averageSalary=totalSalary/employeeQuantity;

        for(i=0; i<len; i++)
        {
            if(list[i].salary>averageSalary&&list[i].isEmpty==OCUPADO)
            {
                overAverageCounter++;
            }
        }
    }


    printf("\nEl total de los salarios es: %.3f\n",totalSalary);
    printf("El promedio de los salarios es: %.3f\n",averageSalary);
    printf("La cantidad de empleados que superan el promedio es: %d\n", overAverageCounter);

}


int sortEmployees(Employee* list, int len, int order)
{

    Employee auxEmp;
    int myReturn=-1;

    switch(order)

    {

    case 1://ascendente

        for(int i =0 ; i<len-1 ; i ++)
        {
            for(int j= i+1 ; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }
                else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[i].sector>list[j].sector)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }


            }

            myReturn=0;
        }

        system("cls");
        printf("EMPLEADOS ORDENADOS ASCENDENTEMENTE\n\n");
        printEmployees(list,len);

        break;
    case 2://descendente

        for(int i =0 ; i<len-1 ; i ++)
        {
            for(int j= i+1 ; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }
                else if(strcmp(list[j].lastName,list[i].lastName) ==0 && list[i].sector<list[j].sector)
                {
                    auxEmp = list[i];
                    list[i] = list[j];
                    list[j] = auxEmp;
                }

            }

            myReturn=0;

        }


        system("cls");
        printf("EMPLEADOS ORDENADOS DESCENDENTEMENTE\n\n");
        printEmployees(list,len);

        break;
    }

    return myReturn;
}

int employeeExist(Employee* list, int len)
{
    int existEmployee = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            existEmployee = 0;
            break;
        }
    }

    return existEmployee;
}














