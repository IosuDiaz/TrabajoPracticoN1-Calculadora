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
            listOfEmployees[i].isEmpty=TRUE;
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
        if(listOfEmployees[i].isEmpty==TRUE)
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
    int validName;
    int validLastName;
    int validSalary;
    int validSector;

    do
    {
        validName=getValidString("\nIngrese el nombre: ","\nError. El nombre solo puede contener letras o espacios", "\nError. El largo del nombre tiene que ser como maximo 50",name,50,1);

    }while(validName==-1);

    do
    {
        validLastName=getValidString("\nIngrese el apellido: ","\nError. El apellido solo puede contener letras o espacios", "\nError. El largo del apellido tiene que ser como maximo 50",lastName,50,1);

    }while(validLastName==-1);

    do
    {
        validSalary=getValidFloat("\nIngrese el salario: ","\nError. El dato ingresado no es valido. Vuelva a intentarlo ",&salary,0,200000,1);

    }while(validSalary==-1);

    do
    {
        validSector=getValidInt("\nIngrese sector: ","\nError. El dato ingresado no es valido. Vuelva a intentarlo ",&sector,0,100,1);

    }while(validSector==-1);

    id=CalculateEmployeeId();

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

        listOfEmployees[availableIndex].id=id;
        strcpy(listOfEmployees[availableIndex].name,name);
        strcpy(listOfEmployees[availableIndex].lastName,lastName);
        listOfEmployees[availableIndex].salary=salary;
        listOfEmployees[availableIndex].sector=sector;
        listOfEmployees[availableIndex].isEmpty=FALSE;
        ifError=0;
    }

    return ifError;
}

void ShowAnEmployee(Employee anEmployee)
{
    printf("\n%3d %17s %16s %18.2f %16d",anEmployee.id,anEmployee.name,anEmployee.lastName,anEmployee.salary,anEmployee.sector);
}

void ShowListOfEmployees(Employee listOfEmployees[], int len)
{
    int i;
    printf("\n%4s %16s %17s %18s %17s","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].isEmpty==FALSE)
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
        if(listOfEmployees[i].id==id && listOfEmployees[i].isEmpty==FALSE)
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
    char confirmation[3];
    int validAuxName;
    int validAuxLastName;
    int validAuxSalary;
    int validAuxSector;
    //Muestra lista de empleados
    ShowListOfEmployees(listOfEmployees,len);

    //Pide el ID que quiere cambiar
    idToModify=getInt("\n\n\nIngrese el ID del empleado al que quiere modificar: ");

    //Busca el indice del empleado a cambiar
    indexOfEmployee=findEmployeeById(listOfEmployees,len,idToModify);

    if(indexOfEmployee!=-1)
    {

        //Pregunta que dato del empleado quiere cambiar
        printf("\nIngrese 1 para modificar el NOMBRE");
        printf("\nIngrese 2 para modificar el APELLIDO");
        printf("\nIngrese 3 para modificar el SALARIO");
        printf("\nIngrese 4 para modificar el SECTOR");
        variableToModify=getInt("\nIngrese opcion: ");

        //Validacion del sub menu
        while(variableToModify!=1 && variableToModify!=2 && variableToModify!=3 && variableToModify!=4)
        {
            getValidInt("\nLa opcion ingresada tiene que estar entre 1 y 4 ","\nError. Vuelva a intentarlo ",&variableToModify,1,4,1);
        }

        //Evalua respues del sub menu
        switch(variableToModify)
        {
            case 1:
                do
                {
                    validAuxName=getValidString("\nIngrese el nuevo nombre: ","\nError. El nombre solo puede contener letras o espacios", "Error. El largo del nombre tiene que ser como maximo 50",auxName,50,1);
                }while(validAuxName==-1);
                break;
            case 2:
                do
                {
                    validAuxLastName=getValidString("\nIngrese el nuevo apellido: ","\nError. El apellido solo puede contener letras o espacios", "Error. El largo del apellido tiene que ser como maximo 50",auxLastName,50,1);
                }while(validAuxLastName==-1);
                break;
            case 3:
                do
                {
                    validAuxSalary=getValidFloat("\nIngrese el nuevo salario: ","\nError. El dato ingresado no es valido. Vuelva a intentarlo ",&auxSalary,0,200000,1);
                }while(validAuxSalary==-1);
                break;
            case 4:
                do
                {
                    validAuxSector=getValidInt("\nIngrese el nuevo sector: ","\nError. El dato ingresado no es valido. Vuelva a intentarlo ",&auxSector,0,100,1);
                }while(validAuxSector==-1);
                break;
        }

        //Pregunta si quiere cambiar el dato
        printf("\nConfirmacion de cambios");
        printf("\nSI para GUARDAR.");
        printf("\nNO para CANCELAR.");
        getString("\n\nEsta seguro que desea CAMBIAR el dato? ",confirmation);
        strupr(confirmation);

        //Valida respuesta de la confirmacion
        while(strcmp(confirmation,"SI")!=0 && strcmp(confirmation,"NO")!=0)
        {
            getString("\nError. Debe ingresar SI o NO: ",confirmation);
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
            }
            printf("\nSe han guardado los cambios.\n");
        }
        else
        {
            printf("\nNo se han guardado los cambios.\n");
        }
    }
    else
    {
        printf("\nNo se ha encontrado ningun empleado con ese ID.\n");
    }
}

void SelectEmployeeToRemove(Employee listOfEmployees[], int len)
{
    int idToDelete;
    int indexOfEmployee;
    char confirmation[3];

    ShowListOfEmployees(listOfEmployees,len);

    getValidInt("\n\n\nIngrese el numero del id que quiere borrar: ","\nError. El dato ingresado es invalido. Vuelva a intentarlo. ",&idToDelete,0,1000,1);

    indexOfEmployee=findEmployeeById(listOfEmployees,len,idToDelete);


    if(indexOfEmployee!=-1)
    {
        printf("\nConfirmacion de cambios:");
        printf("\nSI para BORRAR.");
        printf("\nNO para CANCELAR.");
        getString("\nEsta seguro que desea BORRAR el dato? ",confirmation);

        strupr(confirmation);

        while(strcmp(confirmation,"SI")!=0 && strcmp(confirmation,"NO")!=0)
        {
            getString("\nError. Debe ingresar SI o NO ",confirmation);
            strupr(confirmation);
        }

        if(removeEmployee(listOfEmployees,len,idToDelete)==0)
        {
            printf("\nSe ha borrado el empleado correctamente.");
        }
        else
        {
            printf("\nNo se pudo borrar al empleado.");
        }
    }
    else
    {
        printf("\nNo se ha encontrado ningun empleado con ese ID.");
    }
}

int removeEmployee(Employee listOfEmployees[], int len, int id)
{
    int i;
    int ifError;

    ifError=-1;

    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].id==id)
        {
            listOfEmployees[i].isEmpty=TRUE;
            ifError=0;
            break;
        }
    }
    return ifError;
}

int sortEmployees(Employee listOfEmployees[], int len, int order)
{
    int i;
    int j;
    Employee auxEmployee;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {

            if(((order) && (strcmp(listOfEmployees[i].lastName,listOfEmployees[j].lastName)==1)) ||
            ((order) && ((strcmp(listOfEmployees[i].lastName,listOfEmployees[j].lastName)==0) && (listOfEmployees[i].sector > listOfEmployees[j].sector))))
            {
                auxEmployee=listOfEmployees[i];
                listOfEmployees[i]=listOfEmployees[j];
                listOfEmployees[j]=auxEmployee;
            }
            if(((order==0) && (strcmp(listOfEmployees[i].lastName,listOfEmployees[j].lastName)==-1)) ||
               ((order==0) && ((strcmp(listOfEmployees[i].lastName,listOfEmployees[j].lastName)==0) && (listOfEmployees[i].sector < listOfEmployees[j].sector))))
            {
                auxEmployee=listOfEmployees[i];
                listOfEmployees[i]=listOfEmployees[j];
                listOfEmployees[j]=auxEmployee;
            }
        }
    }
    return 0;
}



int printEmployees(Employee listOfEmployees[], int len)
{
    int orderSelected;
    int validOrder;


    do
    {
        validOrder=getValidInt("\nIngrese 1 para ordenar de manera ASCENDENTE o 0 para ordenar de manera DESCENDENTE","Error. La opcion ingresada no es valida",&orderSelected,0,1,1);
    }while(validOrder==-1);

    sortEmployees(listOfEmployees,len,orderSelected);

    ShowListOfEmployees(listOfEmployees,len);

    return 0;
}

int amountOfPaychecks(Employee listOfEmployees[], int len)
{
    int i;
    int counterOfPayChecks=0;

    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].isEmpty==FALSE)
        {
            counterOfPayChecks++;
        }
    }

    return counterOfPayChecks;
}

int sumOfSalaries(Employee listOfEmployees[], int len)
{
    int i;
    int sumOfPayChecks=0;


    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].isEmpty==FALSE)
        {
            sumOfPayChecks+=listOfEmployees[i].salary;
        }
    }
    return sumOfPayChecks;
}


float averageSalary(Employee listOfEmployees[], int len)
{
    float averagePayCheck;

    averagePayCheck=sumOfSalaries(listOfEmployees,len) / amountOfPaychecks(listOfEmployees,len);

    return averagePayCheck;
}

int amountOfPayChecksAboveTheAverage(Employee listOfEmployees[], int len)
{
    int i;
    int counterOfPayChecksAboveTheAverage=0;
    float averagePayCheck;

    averagePayCheck=averageSalary(listOfEmployees,len);

    for(i=0;i<len;i++)
    {
        if(listOfEmployees[i].salary>averagePayCheck && listOfEmployees[i].isEmpty==FALSE)
        {
            counterOfPayChecksAboveTheAverage++;
        }
    }
    return counterOfPayChecksAboveTheAverage;
}

void informDataOfPaychecks(Employee listOfEmployees[], int len)
{
    int counterOfPayChecks;
    float averagePayCheck;
    int sumOfPayChecks;
    int counterOfPayChecksAboveTheAverage;

    sumOfPayChecks=sumOfSalaries(listOfEmployees,len);
    averagePayCheck=averageSalary(listOfEmployees,len);
    counterOfPayChecks=amountOfPaychecks(listOfEmployees,len);
    counterOfPayChecksAboveTheAverage=amountOfPayChecksAboveTheAverage(listOfEmployees,len);

    printf("\nLa suma de los salarios es: %d",sumOfPayChecks);
    printf("\nEl promedio de los salarios es: %f",averagePayCheck);
    printf("\nLa cantidad de salarios es: %d",counterOfPayChecks);
    printf("\nLa cantidad de salarios por encima de el salario promedio es: %d",counterOfPayChecksAboveTheAverage);
}
