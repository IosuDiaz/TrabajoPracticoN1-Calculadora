#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    LinkedList* listaEmployee;
    int selectedOption;
    int len;


    listaEmployee=ll_newLinkedList();

    if(listaEmployee!=NULL)
    {

        do
        {
            controller_showCounterOfEmployees(listaEmployee);
            if(!controller_Menu(&selectedOption))
            {
                switch(selectedOption)
                {
                    //1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
                    case 1:
                        if(controller_loadFromText("data.csv",listaEmployee)==0)//ifErrorLOAD=controller_loadFromText("r",listaEmployee);//0 si error - !=0 si ok
                        {
                            printf("\nSe cargaron correctamente los empleados de la lista txt\n\n");
                        }
                        else
                        {
                            printf("\nNO se cargaron correctamente los empleados de la lista txt\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    //2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
                    case 2:
                        if(controller_loadFromBinary("data.bin",listaEmployee)==0)//ifErrorbin=controller_loadFromBinary("wb",listaEmployee);
                        {
                            printf("\nSe cargaron correctamente los empleados de la lista bin\n\n");
                        }
                        else
                        {
                            printf("\nNO se cargaron correctamente los empleados de la lista bin\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    //3. Alta de empleado
                    case 3:
                        if(controller_addEmployee(listaEmployee)==0)
                        {
                            printf("\nEl empleado se ha agregado correctamente a la lista\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido agregar al empleado\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    //4. Modificar datos de empleado
                    case 4:
                        if(controller_editEmployee(listaEmployee)==0)
                        {
                            printf("\nSe ha modificado correctamente al empleado\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido modificar al empleado\n\n");
                        }
                        system("pause");
                        system("cls");
                            break;
                    //5. Baja de empleado
                    case 5:
                        controller_ListEmployee(listaEmployee);
                        if(controller_removeEmployee(listaEmployee)==0)
                        {
                            printf("\nSe ha eliminado correctamente al empleado\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido eliminar al empleado\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    //6. Listar empleados
                    case 6:
                        if(controller_ListEmployee(listaEmployee)!=0)
                        {
                            printf("\nNo se ha podido listar a los empleados\n\n");
                        }
                        else
                        {
                            printf("\n");
                        }

                        system("pause");
                        system("cls");
                        break;
                    //7. Ordenar empleados
                    case 7:
                        if(controller_sortEmployee(listaEmployee)==0)
                        {
                            printf("\nSe ha ordenado la lista de empleados\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido ordenar la lista de empleados\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    //8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
                    case 8:
                        if(controller_saveAsText("data.csv",listaEmployee)!=-1)
                        {
                            printf("\nSe ha guardado la lista de empleados en modo texto.\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido guardar la lista de empleados en modo texto.\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    //9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
                    case 9:
                        if(controller_saveAsBinary("data.bin",listaEmployee)!=-1)
                        {
                            printf("\nSe ha guardado la lista de empleados en modo binario.\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido guardar la lista de empleados en modo binario.\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;

                }

            }
            else
            {
                printf("\nError! Opcion de menu invalida.");
            }
        }while(selectedOption!=10);
    }

    return 0;
}


    /*--------------------TEST SETTERS Y GETTERS---------------
    aux=employee_new();
    employee_setSueldo(aux,sueldo);
    printf("\nsueldo ingresado en aux %d",aux->sueldo);
    aux->sueldo=250;
    employee_getSueldo(aux,&sueldo);

    printf("\nsueldo ingresado en var%d",sueldo);
    printf("\nsueldo ingresado en aux%d",aux->sueldo);
    --------------------------------------------------------------*/

    /*-------------mostrar listado-------------
    //LISTA DE EMPLEADOS
    len=ll_len(listaEmployee);
    //printf("\n%d",len);
    for(i=0;i<len;i++)
    {
        aux=(Employee*) ll_get(listaEmployee,i);
        mostrarUnEmpleado(aux);
    }
    ------------------------------------------*/

    /*
    if(controller_loadFromText("data.csv",listaEmployee)!=0)//ifErrorLOAD=controller_loadFromText("r",listaEmployee);//0 si error - !=0 si ok
    {
        printf("\nSe cargaron correctamente los empleados de la lista txt");
    }
    else
    {
        printf("\nNO se cargaron correctamente los empleados de la lista txt");
    }


    if(controller_loadFromBinary("data.bin",listaEmployee)!=0)//ifErrorbin=controller_loadFromBinary("wb",listaEmployee);
    {
        printf("\nSe cargaron correctamente los empleados de la lista bin");
    }
    else
    {
        printf("\nNO se cargaron correctamente los empleados de la lista bin");
    }
    */

    /*----------TEST CONTSTRUCTOR PARAMETRIZADO--------------------

    char id[10]={"10"};
    char nombre[128]={"Juan"};
    char horasTrabajadas[10]={"22"};
    char sueldo[10]={"12415"};




    employee_newParametros(id,nombre,horasTrabajadas,sueldo);
    ------------------------------------------------------------*/


    /*--------------------------------------MENU------------------------------------------
    int selectedOption;
    do
    {
        switch(selectedOption)
        {
            //1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
            case 1:
                if(controller_loadFromText("data.csv",listaEmployee)!=0)//ifErrorLOAD=controller_loadFromText("r",listaEmployee);//0 si error - !=0 si ok
                {
                    printf("\nSe cargaron correctamente los empleados de la lista txt");
                }
                else
                {
                    printf("\nNO se cargaron correctamente los empleados de la lista txt");
                }
                break;
            //2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmployee)!=0)//ifErrorbin=controller_loadFromBinary("wb",listaEmployee);
                {
                    printf("\nSe cargaron correctamente los empleados de la lista bin");
                }
                else
                {
                    printf("\nNO se cargaron correctamente los empleados de la lista bin");
                }
                break;
            //3. Alta de empleado
            case 3:
                controller_addEmployee(listaEmployee);
                break;
            //4. Modificar datos de empleado
            case 4:
                controller_editEmployee(listaEmployee);
                break;
            //5. Baja de empleado
            case 5:
                controller_removeEmployee(listaEmployee);
                break;
            //6. Listar empleados
            case 6:
                controller_ListEmployee(listaEmployee);
                break;
            //7. Ordenar empleados
            case 7:
                controller_sortEmployee(listaEmployee);
                break;
            //8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
            case 8:
                controller_saveAsText("data.csv",listaEmployee);
                break;
            //9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
            case 9:
                controller_saveAsBinary("data.bin",listaEmployee);
                break;

        }

    }while(selectedOption!=10)
    ---------------------------------------------------------------------------------------*/












































