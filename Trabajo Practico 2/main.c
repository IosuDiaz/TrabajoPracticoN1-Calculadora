#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controlador.h"
#include "ArrayEmployees.h"

#define DIM 500

int main()
{
    Employee rosterOfEmployees[DIM];
    int chosenOption;
    int resultOfInit;
    int flagFirstOption=0;
    char exitConfirmation[3];


    //INICIALIZACION EMPLEADOS
    resultOfInit=initEmployees(rosterOfEmployees,DIM);
    //Evalua si se inicializaron las posiciones del array de empleados
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
            //Menu
            chosenOption=Menu();
            //Evalua
            switch(chosenOption)
            {
                //ALTA
                case 1:
                    CreateAnEmployee(rosterOfEmployees,DIM);
                    flagFirstOption=1;
                    break;
                //MODIFICAR
                case 2:
                    if(flagFirstOption)
                    {
                        ModifyAnEmployeeById(rosterOfEmployees,DIM);
                    }
                    else
                    {
                        printf("\nNo se puede modificar. Primero hay que cargar al menos un empleado");
                    }

                    break;
                //BAJA
                case 3:
                    if(flagFirstOption)
                    {
                        SelectEmployeeToRemove(rosterOfEmployees,DIM);
                    }
                    else
                    {
                        printf("\nNo se puede modificar. Primero hay que cargar al menos un empleado");
                    }
                    break;
                //INFORMAR
                case 4:
                    if(flagFirstOption)
                    {
                        printEmployees(rosterOfEmployees,DIM);
                        informDataOfPaychecks(rosterOfEmployees,DIM);
                    }
                    else
                    {
                        printf("\nNo se puede modificar. Primero hay que cargar al menos un empleado");
                    }
                    break;
                case 5:

                    getString("\nEsta seguro que desea CAMBIAR el dato? ",exitConfirmation);
                    strupr(exitConfirmation);
                    while(strcmp(exitConfirmation,"SI")!=0 && strcmp(exitConfirmation,"NO")!=0)
                    {
                        getString("\nError. Debe ingresar SI o NO: ",exitConfirmation);
                        strupr(exitConfirmation);
                    }
                    break;
                }
        }
        while(chosenOption!=5);
    }
    return 0;
}
