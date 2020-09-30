#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "controlador.h"

int initEmployees(Employee listOfEmployees[], int len)
{
    int i;
    int error;

    error=-1;

    if(listOfEmployees!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            listOfEmployees[i].isEmpty=FALSE;
            error=0;
        }
    }

    return error;
}

int SearchForAvailableSpace(Employee listOfEmployees[], int len)
{
    int i;
    int index=-1;

    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].isEmpty==FALSE)
        {
            index=i;
            break;
        }
    }
    return index;
}

void CreateAnEmployee(Employee listOfEmployees[], int len)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;

    id=-1;

    printf("\nIngrese el nombre: ");
    scanf("%s",name);
    fflush(stdin);
    printf("\nIngrese el apellido: ");
    scanf("%s",lastName);
    fflush(stdin);
    printf("\nIngrese el salario: ");
    scanf("%f",&salary);
    printf("\nIngrese sector: ");
    scanf("%d",&sector);

    id=CalculateEmployeeId(id);
    /*
    printf("\nnombre: %s",name);
    printf("\napellido: %s",lastName);
    printf("\nsalario: %f",salary);
    printf("\nsector: %d",sector);
    printf("\nid: %d",id);*/

    addEmployee(listOfEmployees,len,id,name,lastName,salary,sector);

}

int addEmployee(Employee listOfEmployees[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    //int i;
    int availableIndex;
    int ifError;

    ifError=-1;

    if(listOfEmployees!=NULL && len>0)
    {
        availableIndex=SearchForAvailableSpace(listOfEmployees,len);

        strcpy(listOfEmployees[availableIndex].name,name);
        strcpy(listOfEmployees[availableIndex].lastName,lastName);
        listOfEmployees[availableIndex].salary=salary;
        listOfEmployees[availableIndex].sector=sector;
        listOfEmployees[availableIndex].id=id;
        listOfEmployees[availableIndex].isEmpty=TRUE;
        ifError=0;
    }

    /*      ---PARA MOSTRAR LOS EMPLEADOS GUARDADOS---
    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].isEmpty==TRUE)
        {
            printf("\nnombre %s",listOfEmployees[i].name);
            printf("\napellido %s",listOfEmployees[i].lastName);
            printf("\nsalario %f",listOfEmployees[i].salary);
            printf("\nsector %d",listOfEmployees[i].sector);
            printf("\nid %d",listOfEmployees[i].id);
            printf("\nisEmpty %d",listOfEmployees[i].isEmpty);
            printf("\n-----------------------------------------");
        }
    }*/

    return ifError;
}

