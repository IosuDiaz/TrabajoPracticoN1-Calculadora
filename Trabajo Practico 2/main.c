/******************************************************************************
Iosu Fermin Diaz
Segundo Trabajo Practico
UTN Laboratorio 1

*******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controlador.h"
#include "ArrayEmployees.h"

#define DIM 100

int main()
{
    Employee rosterOfEmployees[DIM];
    int chosenOption;
    int resultOfInit;
    int flagFirstOption=0;
    char exitConfirmation[3]={"NO"};

    //Inicializacion de empleados
    resultOfInit=initEmployees(rosterOfEmployees,DIM);
    //Evalua si se inicializaron las posiciones del array de empleados
    if(resultOfInit==-1)
    {
        system("color 17");
        printf("Error al inicializar la base de datos.");
    }
    else
    {
        printf("Se inicializo correctamente la base de datos.\nPuede empezar a cargar la nomina de empleados.\n\n");

        do
        {
            //Menu
            chosenOption=Menu();
            system("pause");
            system("cls");
            //Evalua
            switch(chosenOption)
            {
                //ALTA
                case 1:
                    CreateAnEmployee(rosterOfEmployees,DIM);
                    system("cls");
                    flagFirstOption=1;
                    break;
                //MODIFICAR
                case 2:
                    if(flagFirstOption)
                    {
                        ModifyAnEmployeeById(rosterOfEmployees,DIM);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("No se puede modificar. Primero hay que cargar al menos un empleado\n");
                        system("pause");
                        system("cls");
                    }

                    break;
                //BAJA
                case 3:
                    if(flagFirstOption)
                    {
                        SelectEmployeeToRemove(rosterOfEmployees,DIM);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("\nNo se puede modificar. Primero hay que cargar al menos un empleado\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                //INFORMAR
                case 4:
                    if(flagFirstOption)
                    {
                        printEmployees(rosterOfEmployees,DIM);
                        informDataOfPaychecks(rosterOfEmployees,DIM);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("\nNo se puede modificar. Primero hay que cargar al menos un empleado");
                        system("pause");
                        system("cls");
                    }
                    break;
                case 5:

                    getString("\nEsta seguro que desea SALIR? \nSI para salir \nNO para cancelar ",exitConfirmation);
                    strupr(exitConfirmation);
                    system("cls");
                    while(strcmp(exitConfirmation,"SI")!=0 && strcmp(exitConfirmation,"NO")!=0)
                    {
                        getString("\nError. Debe ingresar SI o NO: ",exitConfirmation);
                        strupr(exitConfirmation);
                        system("cls");
                    }
                    break;
                }
        }
        while(strcmp(exitConfirmation,"SI")!=0);
    }
    return 0;
}
