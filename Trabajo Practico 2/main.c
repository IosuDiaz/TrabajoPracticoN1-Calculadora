#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "controlador.h"
#define DIM 1000

int main()
{
    Employee rosterOfEmployees[DIM];
    char chosenOption[9];
    int mappedOption;
    int resultOfInit;

    //MENU
    Menu(chosenOption);
    //MAPEO DE OPCIONES
    mappedOption=MappingChosenOption(chosenOption);
    //INICIALIZAR EMPLEADOS
    resultOfInit=initEmployees(rosterOfEmployees,10);

    printf("%d",resultOfInit);

    switch(mappedOption)
    {
        //ALTA
        case 1:

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
    return 0;
}
