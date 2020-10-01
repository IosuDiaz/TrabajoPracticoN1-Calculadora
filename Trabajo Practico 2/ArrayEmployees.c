#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "controlador.h"

int initEmployees(Employee listOfEmployees[], int len)
{
    int i;
    int error;

    error=-1;

    if(listOfEmployees!=NULL && len>0)
    {
        error=0;
        for(i=0; i<len; i++)
        {
            listOfEmployees[i].isEmpty=FALSE;
        }
    }

    return error;
}

int SearchForAvailableSpace(Employee listOfEmployees[], int len)
{
    int i;
    int index=-1;

    for(i=0; i<len; i++)
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
    fflush(stdin);
    scanf("%s",name);
    while(isOnlyLetters(name)==0)
    {
        printf("Error. El nombre solo puede contener letras o espacios");
        scanf("%s",name);
    }

    printf("\nIngrese el apellido: ");
    fflush(stdin);
    scanf("%s",lastName);
    while(isOnlyLetters(lastName)==0)
    {
        printf("Error. El apellido solo puede contener letras o espacios");
        scanf("%s",lastName);
    }

    printf("\nIngrese el salario: ");
    scanf("%f",&salary);
    //while()
    //{

    //}

    printf("\nIngrese sector: ");
    scanf("%d",&sector);
    //while()
    //{

    //}


    id=CalculateEmployeeId(id);

    addEmployee(listOfEmployees,len,id,name,lastName,salary,sector);

}

int addEmployee(Employee listOfEmployees[], int len, int id, char name[],char lastName[],float salary,int sector)
{
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

    return ifError;
}

void ShowAnEmployee(Employee anEmployee)
{
    printf("%1d %10s %10s %10.2f %10d\n",anEmployee.id,anEmployee.name,anEmployee.lastName,anEmployee.salary,anEmployee.sector);
}

void ShowListOfEmployees(Employee listOfEmployees[], int len)
{
    int i;
    printf("%s %10s %10s %10s %10s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
    for(i=0; i<len; i++)
    {
        if(listOfEmployees[i].isEmpty==TRUE)
        {
            ShowAnEmployee(listOfEmployees[i]);
        }
    }
}

int findEmployeeById(Employee listOfEmployees[], int len, int id)
{
    int i;
    int index;

    index=-1;

    for(i=0; i<len; i++)
    {
        if(listOfEmployees[i].id==id)
        {
            index=i;
            break;
        }
    }
    return index;
}

void ModifyAnEmployeeById(Employee listOfEmployees[], int len)
{
    int idToModify;
    int indexOfEmployee;
    int variableToModify;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    char confirmation[2];

    //Muestra lista de empleados
    ShowListOfEmployees(listOfEmployees,len);

    //Pide el ID que quiere cambiar
    printf("\nIngrese el ID del empleado al que quiere modificar: ");
    fflush(stdin);
    scanf("%d",&idToModify);

    //Busca el indice del empleado a cambiar
    indexOfEmployee=findEmployeeById(listOfEmployees,len,idToModify);

    //Pregunta que dato del empleado quiere cambiar
    printf("\nIngrese 1 para modificar el NOMBRE");
    printf("\nIngrese 2 para modificar el APELLIDO");
    printf("\nIngrese 3 para modificar el SALARIO");
    printf("\nIngrese 4 para modificar el SECTOR");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&variableToModify);

    //Validacion del sub menu
    while(variableToModify!=1 && variableToModify!=2 && variableToModify!=3 && variableToModify!=4)
    {
        printf("\nError. La opcion ingresada no coincide con las disponibles ");
        fflush(stdin);
        scanf("%d",&variableToModify);
    }

    //Evalua respues del sub menu
    switch(variableToModify)
    {
        case 1:
            printf("\nIngrese el nuevo NOMBRE: ");
            fflush(stdin);
            scanf("%s",auxName);
            break;
        case 2:
            printf("\nIngrese el nuevo APELLIDO: ");
            fflush(stdin);
            scanf("%s",auxLastName);
            break;
        case 3:
            printf("\nIngrese el nuevo SALARIO: ");
            scanf("%f",&auxSalary);
            break;
        case 4:
            printf("\nIngrese el nuevo SECTOR: ");
            scanf("%d",&auxSector);
            break;
    }

    //Pregunta si quiere cambiar el dato
    printf("\nEsta seguro que desea cambiar el dato?");
    printf("\nSI para guardar.");
    printf("\nNO para cancerlar.");
    fflush(stdin);
    scanf("%s",confirmation);
    strupr(confirmation);

    //Valida respuesta de la confirmacion
    while(strcmp(confirmation,"SI")!=0 && strcmp(confirmation,"NO")!=0)
    {
        printf("\nError. Tiene que ingresar SI o NO. ");
        fflush(stdin);
        scanf("%s",confirmation);
        strupr(confirmation);
    }

    //Evalua respuesta de la confirmacion
    if(strcmp(confirmation,"SI")==0)
    {
        //Guarda en el indice del empleado el cambio a efectuar
        switch(variableToModify)
        {
            case 1:
                strcpy(listOfEmployees[indexOfEmployee].name,auxName);
                break;
            case 2:
                strcpy(listOfEmployees[indexOfEmployee].lastName,auxLastName);
                break;
            case 3:
                listOfEmployees[indexOfEmployee].salary=auxSalary;
                break;
            case 4:
                listOfEmployees[indexOfEmployee].sector=auxSector;
                break;
            printf("\nSe han guardado los cambios.");
        }
    }
    else
    {
        printf("\nNo se han guardado los cambios.");
    }
}
