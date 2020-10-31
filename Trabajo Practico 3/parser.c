#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Conversor de texto a estructura
 *
 * \param pFile FILE* archivo que contiene a los empleados cargados
 * \param pArrayListEmployee LinkedList* puntero a donde se van a guardar dichos empleados
 * \return int cantidad de elementos que logra convertir
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i;
    int r;
    char id[50];
    char nombre[50];
    char HorasTrabajadas[50];
    char sueldo[50];
    Employee* anEmployee;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,HorasTrabajadas,sueldo);
        if(esNumerico(id))
        {
            rewind(pFile);
        }
        for(i=0;!feof(pFile);i++)
        {

            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,HorasTrabajadas,sueldo);
            if(r==4)
            {
                anEmployee=employee_newParametros(id,nombre,HorasTrabajadas,sueldo);
                ll_add(pArrayListEmployee,anEmployee);
            }

        }
        fclose(pFile);
    }

    return i;
}

/** \brief Conversor de binario a estructura
 *
 * \param pFile FILE* archivo que contiene a los empleados cargados
 * \param pArrayListEmployee LinkedList* puntero a donde se van a guardar dichos empleados
 * \return int cantidad de elementos que se lograron convertir
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int i;
    int r;
    Employee* anEmployee;

    if(pFile != NULL && anEmployee!=NULL)
    {
        for(i=0;!feof(pFile);i++)
        {
            anEmployee=employee_new();
            r=fread(anEmployee,sizeof(Employee),1,pFile);
            if(r==1)
            {
                ll_add(pArrayListEmployee,anEmployee);
            }


        }
        fclose(pFile);
    }

    return i;
}


/** \brief Conversor de estructura a binario
 *
 * \param pFile FILE* archivo que va a guardar los empleados de la lista
 * \param pArrayListEmployee LinkedList* puntero de donde se obtienen los empleados
 * \return int cantidad de elementos que se lograron convertir
 *
 */
int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            aux=(Employee*) ll_get(pArrayListEmployee,i);
            if(aux!=NULL)
            {

                fwrite(aux,sizeof(Employee),1,pFile);
            }
        }
    }
    return i;
}

/** \brief Conversor de estructura a texto
 *
 * \param pFile FILE* archivo que va a guardar los empleados de la lista
 * \param pArrayListEmployee LinkedList* puntero de donde se obtienen los empleados
 * \return int cantidad de elementos que se lograron convertir
 *
 */
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    char nombre[128];
    int hs;
    int sueldo;
    int len;
    //preguntar si conviene crear variable por variable
    //o declarar una estrucutra en la pila para guardar los datos que se extraen del puntero
    Employee* aux;

    if(pFile!=NULL && pArrayListEmployee!=NULL && aux!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);
            //employee_ListAnEmployee(aux);
            //system("pause");
            if(aux!=NULL)
            {
                employee_getId(aux,&id);
                employee_getNombre(aux,nombre);
                employee_getHorasTrabajadas(aux,&hs);
                employee_getSueldo(aux,&sueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,hs,sueldo);
            }
        }
    }
    return i;
}
