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
int Menu()
{
    int selectedOption;
    int validOption;
    //preguntar si el menu es con PALABRAS O NUMEROS
    printf("\n1 ALTAS");
    printf("\n2 MODIFICAR");
    printf("\n3 BAJA");
    printf("\n4 INFORMAR");
    printf("\n5 SALIR");

    do
    {
        validOption=getValidInt("\nSeleccione opcion: ","Error. Tiene que un numero del 1 al 5.",&selectedOption,1,5,1);
    }while (validOption=!-1);

    return selectedOption;
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


