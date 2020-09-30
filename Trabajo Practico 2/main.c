#include <stdio.h>
#include <stdlib.h>

#include "controlador.h"
#include "ArrayEmployees.h"

#define DIM 10

int main()
{
    Employee rosterOfEmployees[DIM];
    char chosenOption[9];
    int mappedOption;
    int resultOfInit;

    //INICIALIZAR EMPLEADOS
    resultOfInit=initEmployees(rosterOfEmployees,DIM);
    do
    {
        //MENU
        Menu(chosenOption);
        //MAPEO DE OPCIONES
        mappedOption=MappingChosenOption(chosenOption);
        //printf("%d",resultOfInit);

        switch(mappedOption)
        {
            //ALTA
            case 1:
                CreateAnEmployee(rosterOfEmployees,DIM);
                break;
            //MODIFICAR
            case 2:

                break;
            //BAJA
            case 3:

                break;
            //INFORMAR
            case 4:

                break;

        }
    }
    while(mappedOption==1);

    return 0;
}
