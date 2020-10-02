#include <stdio.h>
#include <stdlib.h>

#include "controlador.h"
#include "ArrayEmployees.h"

#define DIM 500

int main()
{
    Employee rosterOfEmployees[DIM];
    char chosenOption[9];
    int mappedOption;
    int resultOfInit;

    //INICIALIZAR EMPLEADOS
    resultOfInit=initEmployees(rosterOfEmployees,DIM);

    if(resultOfInit==-1)
    {
        system("color 17");
        printf("Error al inicializar la base de datos.\nPuede empezar a cargar la nomina de empleados.");
    }
    else
    {
        printf("Se inicializo correctamente la base de datos.\nPuede empezar a cargar la nomina de empleados.");
        do
        {
            //MENU
            Menu(chosenOption);
            //MAPEO DE OPCIONES
            mappedOption=MappingChosenOption(chosenOption);

            switch(mappedOption)
            {
                //ALTA
                case 1:
                    CreateAnEmployee(rosterOfEmployees,DIM);
                    //ShowListOfEmployees(rosterOfEmployees,DIM);
                    break;
                //MODIFICAR
                case 2:
                    ModifyAnEmployeeById(rosterOfEmployees,DIM);
                    //ShowListOfEmployees(rosterOfEmployees,DIM);
                    break;
                //BAJA
                case 3:
                    SelectEmployeeToRemove(rosterOfEmployees,DIM);
                    //ShowListOfEmployees(rosterOfEmployees,DIM);
                    break;
                //INFORMAR
                case 4:
                    printEmployees(rosterOfEmployees,DIM);
                    informDataOfPaychecks(rosterOfEmployees,DIM);
                    break;

                }
        }
        while(mappedOption!=4);
    }
    return 0;
}
