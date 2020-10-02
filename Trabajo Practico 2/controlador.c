#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controlador.h"

int getInt(char* message)
{
    int aux;
    printf("%s",message);
    scanf("%d",&aux);
    return aux;
}

void getString(char message[],char input[])
{
    printf("%s",message);
    fflush(stdin);
    scanf ("%[^\n]s", input);
}

float getFloat(char* message)
{
    float aux;
    printf("%s",message);
    scanf("%f",&aux);
    return aux;
}

int isNumericFloat(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int isOnlyLetters(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
           return 0;
       }
       i++;
   }
   return 1;
}

int isNumeric(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

int getStringLetters(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isOnlyLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumbers(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isNumeric(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumericFloat(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isNumericFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int getValidFloat(char requestMessage[],char errorMessage[], float* input,float lowLimit, float hiLimit,int attemps)
{
    char auxStr[256];
    int i, retorno = -1;
    float auxInt;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumericFloat(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atof(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetters(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

//validar
void Menu(char selectedOption[])
{
    //preguntar si el menu es con PALABRAS O NUMEROS
    printf("\nIngrese ALTAS para cargar un empleado");
    printf("\nIngrese MODIFICAR para cambiar los datos de un empleado");
    printf("\nIngrese BAJA para eliminar un empleado de la base de datos");
    printf("\nIngrese INFORMAR para ver el listado de empleados");
    printf("\nSeleccione opcion: ");
    scanf("%s",selectedOption);
    strupr(selectedOption);
}

int MappingChosenOption(char selectedOption[])
{
    int mappingSelectedOption;

    if(strcmp(selectedOption,"ALTAS")==0)
    {
        mappingSelectedOption=1;
    }
    else
    {
        if(strcmp(selectedOption,"MODIFICAR")==0)
        {
            mappingSelectedOption=2;
        }
        else
        {
            if(strcmp(selectedOption,"BAJA")==0)
            {
                mappingSelectedOption=3;
            }
            else
            {
                if(strcmp(selectedOption,"INFORMAR")==0)
                {
                    mappingSelectedOption=4;
                }
            }
        }
    }
    return mappingSelectedOption;
}



int CalculateEmployeeId(void)
{
    static int maxId=-1;
    int id=-1;
    if(id<0)
    {
        maxId++;
        id=maxId;
    }

    return id;
}


