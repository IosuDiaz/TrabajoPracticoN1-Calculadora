#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>


/** \brief Consturctor por defecto
 *
 * \return Employee* devuelve la direccion de memoria del puntero a estructura
 *
 */
Employee* employee_new()
{
    Employee* pointer;

    pointer=(Employee*) malloc(sizeof(Employee));

    if(pointer!=NULL)
    {
        employee_setId(pointer,0);
        employee_setNombre(pointer,"\0");
        employee_setHorasTrabajadas(pointer,0);
        employee_setSueldo(pointer,0);
    }

    return pointer;
}


/** \brief Constructor parametrizado: Asigna valores pasados por parametros a un puntero tipo estructura
 *
 * \param idStr char* id que se le asigna al empleado
 * \param nombreStr char* nombre que se le asigna al empleado
 * \param horasTrabajadasStr char* cantidad de horas trabajadas que se le asignan al empleado
 * \param sueldoStr char* sueldo que se le asgina al empleado
 * \return Employee* direccion de memoria del puntero con los valores asignados
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pointer;
    pointer=employee_new();
    int id;
    int horasTrabajadas;
    int sueldo;


    if(pointer!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        id=atoi(idStr);
        horasTrabajadas=atoi(horasTrabajadasStr);
        sueldo=atoi(sueldoStr);

        if(employee_setId(pointer,id)!=0 || employee_setNombre(pointer,nombreStr)!=0 || employee_setHorasTrabajadas(pointer,horasTrabajadas)!=0 || employee_setSueldo(pointer,sueldo)!=0)
        {
            //se libera puntero porque sino se le pasa NULL a free() y no se libera el puntero
            free(pointer);
            pointer=NULL;
        }


        return pointer;
    }
}


int employee_setId(Employee* this,int id)
{
    int ifError=1;

    if(this!=NULL && id>0)
    {
        this->id=id;
        ifError=0;
    }

    return ifError;
}


int employee_getId(Employee* this,int* id)
{
    int ifError=1;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        ifError=0;
    }
    return ifError;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ifError=1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        ifError=0;
    }

    return ifError;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int ifError=1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        ifError=0;
    }

    return ifError;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ifError=1;

    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        ifError=0;
    }

    return ifError;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ifError=1;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        ifError=0;
    }
    return ifError;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ifError=1;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        ifError=0;
    }

    return ifError;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ifError=1;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        ifError=0;
    }
    return ifError;
}

void employee_ListAnEmployee(Employee* this)
{
    int id;
    char nombre[128];
    int hs;
    int sueldo;
    if(this!=NULL)
    {
        employee_getId(this,&id);
        employee_getNombre(this,nombre);
        employee_getHorasTrabajadas(this,&hs);
        employee_getSueldo(this,&sueldo);

        printf("\n %-10d %-15s %-15d %-15d",id,nombre,hs,sueldo);

    }

}
//sacar flechas
int employee_CompareByName(Employee* e1, Employee* e2)
{
    int criterio;
    char nombre1[50];
    char nombre2[50];
    if(e1!=NULL && e2!=NULL)
    {
        employee_getNombre(e1,nombre1);
        employee_getNombre(e2,nombre2);
        criterio=strcmp(nombre1,nombre2);
    }

    return criterio;
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    int criterio;
    int idUno;
    int idDos;

    if(e1!=NULL && e2!=NULL)
    {
        //retornar la resta de los id tal cual kcomo esta en la de comprar por id
        if(!employee_getId(e1,&idUno) && !employee_getId(e2,&idDos))
        {
            criterio=idUno-idDos;
            if(criterio>0)
            {
                criterio=1;
            }
            else
            {
                if(criterio<0)
                {
                    criterio=-1;
                }
            }
        }
    }
    return criterio;
}





