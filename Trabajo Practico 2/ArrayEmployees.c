#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"


int initEmployees(Employee listOfEmployees[], int len)
{
    int i;
    int error;

    error=-1;

    if(listOfEmployees!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            listOfEmployees[i].isEmpty=FALSE;
            error=0;
        }
    }

    return error;
}
