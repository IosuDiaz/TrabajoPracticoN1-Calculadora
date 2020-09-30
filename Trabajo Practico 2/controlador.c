#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controlador.h"


//validar
void Menu(char selectedOption[])
{
    //preguntar si el menu es con PALABRAS O NUMEROS
    printf("\nIngrese ALTAS para cargar un empleado");
    printf("\nIngrese MODIFICAR para cambiar los datos de un empleado");
    printf("\nIngrese BAJA para eliminar un empleado de la base de datos");
    printf("\nIngrese INFORMAR para ver el listado de empleados");
    printf("\nSeleccione opcion: ");
    scanf("%s",selectedOption);
    strupr(selectedOption);
}

int MappingChosenOption(char selectedOption[])
{
    int mappingSelectedOption;

    if(strcmp(selectedOption,"ALTAS")==0)
    {
        mappingSelectedOption=1;
    }
    else
    {
        if(strcmp(selectedOption,"MODIFICAR")==0)
        {
            mappingSelectedOption=2;
        }
        else
        {
            if(strcmp(selectedOption,"BAJA")==0)
            {
                mappingSelectedOption=3;
            }
            else
            {
                if(strcmp(selectedOption,"INFORMAR")==0)
                {
                    mappingSelectedOption=4;
                }
            }
        }
    }
    return mappingSelectedOption;
}
int CalculateEmployeeId(int id)
{
    static int maxId=-1;

    if(id<0)
    {
        maxId++;
        id=maxId;
    }

    return id;
}


