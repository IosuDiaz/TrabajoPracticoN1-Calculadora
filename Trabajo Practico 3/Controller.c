#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "controller.h"

/** \brief Muestra el menu y toma el dato
 *
 * \param selectedOption int* variable a cargar
 * \return int  0 si ok  -1 si error
 *
 */
int controller_Menu(int* selectedOption)
{
    int ifError;

    printf("\n------------------------------------MENU------------------------------------\n");
    printf("\n1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2) Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("\n3) Alta de empleado");
    printf("\n4) Modificar datos de empleado");
    printf("\n5) Baja de empleado");
    printf("\n6) Listar empleados");
    printf("\n7) Ordenar empleados");
    printf("\n8) Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9) Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    printf("\n10) Salir");

    ifError=getValidInt("\nIngrese opcion: ","Error! No ingreso una opcion valida",selectedOption,1,10,3);

    return ifError;
}

/** \brief Muestra en tiempo real la cantidad de empleados que hay cargada
 *
 * \param pArrayListEmployee LinkedList* puntero del array de empleados
 * \return void
 *
 */
void controller_showCounterOfEmployees(LinkedList* pArrayListEmployee)
{
    int len;

    len=ll_len(pArrayListEmployee);

    printf("\n                   -----------------------------------------");
    printf("\n                  |                                         |");
    printf("\n                  |  Cantidad de empleados cargados: %-4d   |",len);
    printf("\n                  |                                         |");
    printf("\n                   -----------------------------------------");
}


/** \brief Carga el array con los datos obtenidos del archivo de texto
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero en donde se van a guardar los empleados
 * \return int 0 if ok -1 if error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int ifError=-1;

    pFile=fopen(path,"r");

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        ifError=parser_EmployeeFromText(pFile,pArrayListEmployee);
    }

    fclose(pFile);

    controller_saveAsBinary("data.bin",pArrayListEmployee);
    return ifError;
}


/** \brief Carga el array con los datos obtenidos del archivo de binario
 *
 * \param path char* direccion del archivo
 * \param pArrayListEmployee LinkedList* puntero en donde se van a guardar los empleados
 * \return int  0 if ok -1 if error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int ifError=-1;

    pFile=fopen(path,"rb");
    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        ifError=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }

    fclose(pFile);

    controller_saveAsText("data.csv",pArrayListEmployee);

    return ifError;
}


/** \brief Agrega un empleado al array de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero en donde se va a guarda el empleado
 * \return int 0 if ok -1 if error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;

    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int validHs;
    int validNombre;
    int validSueldo;
    int len;
    int ifError=-1;
    char confirm;

    //el aux se declara en el heap
    aux=employee_new();
    //se valida que los punteros no apunten a null
    if(pArrayListEmployee!=NULL && aux!=NULL)
    {
        //input validado
        validNombre=getValidString("\nIngrese el nombre del empleado: "
                           ,"\nError! El nombre solamente puede contener letras"
                           ,"\nError! El nombre no puede tener mas de 127 letras"
                           ,nombre,127,3);

        validHs=getValidInt("\nIngrese la cantidad de horas trabajadas: "
                        ,"\nError! Solo puede ingresar numeros entre 1 y 500. "
                        ,&horasTrabajadas,1,500,3);

        validSueldo=getValidInt("\nIngrese el sueldo: "
                        ,"Error! Solo puede ingresar numeros entre 1 y 500000. "
                        ,&sueldo,1,500000,3);

        if(!validNombre && !validHs && !validSueldo)
        {
            confirm=toupper(getChar("\nPara agregar el empleado cargado ingrese la letra 'S'\nPara cancelar la carga 'X'"));
            if(confirm=='S')
            {

                //asignacion mediante setters los datos adquiridos del empleado
                //PENSAR ID AUTOMATICO
                //inicia con el maxid+1
                len=ll_len(pArrayListEmployee);
                employee_setId(aux,CalculateId(len));

                employee_setNombre(aux,nombre);

                employee_setHorasTrabajadas(aux,horasTrabajadas);

                employee_setSueldo(aux,sueldo);

                //agregar empleado a la lista
                ll_add(pArrayListEmployee,aux);

                ifError=0;
            }
        }
    }

    return ifError;
}


/** \brief Se modifica a un empleado del array de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero de donde se obtiene el empleado a modificar
 * \return int 0 if ok -1 if error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;

    int i;
    int idIngresado;
    int idObtenido;
    int len;
    int opcionSubMenu;
    char confirm;

    int ifError=-1;

    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    int validSubMenu;
    int validNombre;
    int validHs;
    int validSueldo;

    if(pArrayListEmployee!=NULL)
    {
        printf("---------MODIFICACION DE EMPLEADO---------\n\n");

        controller_ListEmployee(pArrayListEmployee);

        idIngresado=getInt("\nIngrese ID del empleado que quiera modificar: ");

        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(aux,&idObtenido);
            if(idObtenido==idIngresado)
            {
                break;
            }
        }


        if(aux!=NULL)
        {

            validSubMenu=getValidInt("\nQue dato desea modificar del empleado: \n1) Nombre\n2) Horas Trabajadas\n3) Sueldo"
                                    ,"Error! La opcion ingresada no coincide con las disponibles",&opcionSubMenu,1,3,3);
            if(!validSubMenu)
            {

                switch(opcionSubMenu)
                {
                    //nombre
                    case 1:
                        validNombre=getValidString("\nIngrese el nuevo nombre del empleado: "
                                ,"\nError! El nombre solamente puede contener letras"
                                ,"\nError! El nombre no puede tener mas de 127 letras"
                                ,nombre,127,3);
                        break;
                    //horas trabajadas
                    case 2:
                        validHs=getValidInt("\nIngrese la nueva cantidad de horas trabajadas: "
                                ,"\nError! Solo puede ingresar numeros entre 1 y 500. "
                                ,&horasTrabajadas,1,500,3);
                        break;
                    //sueldo
                    case 3:
                        validSueldo=getValidInt("\nIngrese el nuevo sueldo: "
                                ,"Error! Solo puede ingresar numeros entre 1 y 500000. "
                                ,&sueldo,1,500000,3);
                        break;
                }

                confirm=toupper(getChar("\nPara agregar el empleado cargado ingrese la letra 'S'\nPara cancelar la carga 'X'"));
                if(confirm=='S' && (!validNombre || !validHs || !validSueldo))
                {
                    switch(opcionSubMenu)
                    {
                        case 1:
                            employee_setNombre(aux,nombre);
                            break;
                        case 2:
                            employee_setHorasTrabajadas(aux,horasTrabajadas);
                            break;
                        case 3:
                            employee_setSueldo(aux,sueldo);
                            break;
                    }
                    ifError=0;
                    controller_ListEmployee(pArrayListEmployee);
                }
                else
                {
                    printf("\nNo se ha logrado guardar el dato modificado");
                }
            }
            else
            {
                printf("\nError al seleccionar el dato a modificar.");
            }
        }
        else
        {
            printf("\nEl ID no fue encontrado");
        }
    }

    return ifError;
}


/** \brief Remueve un empleado del array de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al cual se le va a borrar un empleado
 * \return int 0 if ok -1 if error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int idObtenido;
    int idIngresado;
    int ifError=-1;
    int confirm;
    int i;
    int len;
    int validRemove;

    if(pArrayListEmployee!=NULL)
    {
        idIngresado=getInt("\nIngrese ID del empleado que quiera eliminar: ");

        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(aux,&idObtenido);
            if(idObtenido==idIngresado)
            {
                break;
            }
        }
        employee_ListAnEmployee(aux);
        confirm=toupper(getChar("\nPara remover el siguiente empleado 'S'\nPara cancelar el borrado 'X'"));

        if(confirm=='S')
        {
            validRemove=ll_remove(pArrayListEmployee,i);
            free(aux);

            if(!validRemove)
            {
                ifError=0;

            }
        }
        else
        {
            printf("\nID no encontrado");
        }
    }

    return ifError;
}


/** \brief Muestra la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero de donde se obtienen los empleados
 * \return int 0 if ok -1 if error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;
    int ifError=-1;


    if(pArrayListEmployee!=NULL && aux!=NULL)
    {

        len=ll_len(pArrayListEmployee);

        printf("%s %15s %17s %13s\n","ID","NOMBRE","HS TRABAJADAS","SUELDO");
        printf("---------------------------------------------------------");

        for(i=0;i<len;i++)
        {

            aux=(Employee*)ll_get(pArrayListEmployee,i);
            if(aux!=NULL)
            {
                employee_ListAnEmployee(aux);
            }
        }
        ifError=0;
    }

    return ifError;
}


/** \brief Ordena la lista de empleados por nombre o por ID de mayor a menor o de menor a mayor
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 if ok -1 if error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcionSubMenu;
    int validSubMenu;
    int criterio;
    int validCriterio;
    int ifError=-1;
    int a;


    if(pArrayListEmployee!=NULL)
    {
        printf("\n---------ORDENAR LISTA EMPLEADOS---------\n\n");

        validSubMenu=getValidInt("\nCon que criterio desea ordenar a los empleados?: \n1) Nombre\n2) ID"
                                    ,"Error! La opcion ingresada no coincide con las disponibles"
                                    ,&opcionSubMenu,1,2,3);
        if(validSubMenu==0 && opcionSubMenu==1 )
        {
            validCriterio=getValidInt("\n0) Z-A\n1) A-Z"
                                    ,"Error! La opcion ingresada no coincide con las disponibles"
                                    ,&criterio,0,1,3);
            if(validCriterio==0)
            {
                ll_sort(pArrayListEmployee,employee_CompareByName,criterio);
                ifError=0;
            }
        }
        else
        {
            if(validSubMenu==0 && opcionSubMenu==2)
            {
                validCriterio=getValidInt("\n0) Mayor-Menor\n1) Menor-Mayor"
                                    ,"Error! La opcion ingresada no coincide con las disponibles"
                                    ,&criterio,0,1,3);
                if(validCriterio==0)
                {
                    ll_sort(pArrayListEmployee,employee_CompareById,criterio);
                    ifError=0;
                }
            }
        }
    }

    return ifError;
}


/** \brief Guarda el contenido del array de empleados en el archivo de texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 if ok -1 if error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int ifError=-1;
    pFile=fopen(path,"w");

    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        ifError=parser_TextFromEmployee(pFile,pArrayListEmployee);
    }
    fclose(pFile);
    return ifError;
}


/** \brief Guarda el contenido del array de empleados en el archivo de texto
 *
 * \param path char* Direccion del archivo
 * \param pArrayListEmployee LinkedList* Puntero de donde se obtienen los empleados
 * \return int 0 if ok -1 if error
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int ifError=-1;
    pFile=fopen(path,"wb");

    if(pArrayListEmployee!=NULL && pFile!=NULL)
    {
        ifError=parser_BinaryFromEmployee(pFile,pArrayListEmployee);
    }
    fclose(pFile);
    return ifError;


}

