#include <stdio.h>
#include <stdlib.h>

int mostrarMenu(int opcionElegida)
{
    printf("\nPara ingresar el primer operando, ingrese 1. ");
    printf("\nPara ingresar el segundo operando, ingrese 2. ");
    printf("\nPara calcular las operaciones, ingrese 3. ");
    printf("\nPara mostrar los resultados, ingrese 4. ");
    printf("\nPara salir, ingrese 5. ");
    printf("\n\nIngrese numero: ");
    scanf("\n %d",&opcionElegida);
    system("cls");
    return opcionElegida;
}

int pedirNumero(int operando, int opcionElegida)
{
    if(opcionElegida==1)
    {
        printf("\nIngrese el primer operando. A=");
        scanf("%d",&operando);
        system("cls");
    }
    else
    {
        if(opcionElegida==2)
        {
            printf("\nIngrese el segundo operando. B=");
            scanf("%d",&operando);
            system("cls");
        }
    }
    return operando;
}

int sumarOperandos(int primerOperando, int segundoOperando)
{
    int suma;
    suma=primerOperando+segundoOperando;
    return suma;
}

int restarOperandos(int primerOperando, int segundoOperando)
{
    int resta;
    resta=primerOperando-segundoOperando;
    return resta;
}

float dividirOperadores(int primerOperando, int segundoOperando)
{
    float division;
    if(!segundoOperando)
    {
        division=0;
    }
    else
    {
    division=(float)primerOperando/segundoOperando;
    }
    return division;
}
int multiplicarOperadores(int primerOperando, int segundoOperando)
{
    int multiplicacion;
    multiplicacion=primerOperando*segundoOperando;
    return multiplicacion;
}

int factorizarOperando(int operando)
{
    int factorizacionOperando=1;

    if(operando<0)
    {
        factorizacionOperando=0;
    }
    else {

        if(operando==0)
        {
            factorizacionOperando=1;
        }

        for(int i = 1;i<=operando;i++)
        {
            factorizacionOperando *= i;
        }
    }

    return factorizacionOperando;
}
/*
void calcularOperaciones()
{
    printf("El resultado de A+B es: %d \n",sumaResuelta);
    printf("El resultado de A-B es: %d \n",restaResuelta);
    printf("El resultado de A/B es: %f \n",divisionResuelta);
    printf("El resultado de A*B es: %d \n",multiplicacionResuelta);
    printf("El factorial de A es: %d y El factorial de B es: %d",factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
}*/

void calcularYMostrarOperaciones(int primerOperando, int segundoOperando, int respuestaMenu)
{
    int sumaResuelta;
    int restaResuelta;
    float divisionResuelta;
    int multiplicacionResuelta;
    int factorizacionPrimerOperandoResuelta;
    int factorizacionSegundoOperandoResuelta;

    if(respuestaMenu==3 || respuestaMenu==4)
    {
        sumaResuelta=sumarOperandos(primerOperando,segundoOperando);
        restaResuelta=restarOperandos(primerOperando,segundoOperando);
        divisionResuelta=dividirOperadores(primerOperando,segundoOperando);
        multiplicacionResuelta=multiplicarOperadores(primerOperando,segundoOperando);
        factorizacionPrimerOperandoResuelta=factorizarOperando(primerOperando);
        factorizacionSegundoOperandoResuelta=factorizarOperando(segundoOperando);
    }

    if(respuestaMenu==4)
    {
        //mostrar resultados
        printf("El resultado de A+B es: %d \n",sumaResuelta);
        printf("El resultado de A-B es: %d \n",restaResuelta);

        //validacion division
        if(!divisionResuelta)
        {
            printf("El resultado de A/B es: Infinito\n");
        }
        else
        {
            printf("El resultado de A/B es: %f \n",divisionResuelta);
        }

        printf("El resultado de A*B es: %d \n",multiplicacionResuelta);

        //validacion factorial
        //Cuando A<0
        if(!factorizacionPrimerOperandoResuelta)
        {
            printf("El factorial de A no es posible de calcular y El factorial de B es: %d \n\n",factorizacionSegundoOperandoResuelta);
        }
        else
        {
            //Cuando B<0
            if(!factorizacionSegundoOperandoResuelta)
            {
                printf("El factorial de A es: %d y El factorial de B no es posible de calcular. \n\n",factorizacionPrimerOperandoResuelta);
            }
            else
            {
                printf("El factorial de A es: %d y El factorial de B es: %d \n\n",factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);

            }
        }
    }
}





































/*
#include <stdio.h>
#include <stdlib.h>

int sumarOperandos(int primerOperando, int segundoOperando)
{
    int suma;
    suma=primerOperando+segundoOperando;
    return suma;
}

int restarOperandos(int primerOperando, int segundoOperando)
{
    int resta;
    resta=primerOperando-segundoOperando;
    return resta;
}

float dividirOperadores(int primerOperando, int segundoOperando)
{
    float division;
    division=(float)primerOperando/segundoOperando;
    return division;
}
int multiplicarOperadores(int primerOperando, int segundoOperando)
{
    int multiplicacion;
    multiplicacion=primerOperando*segundoOperando;
    return multiplicacion;
}

int factorizarPrimerOperando(int primerOperando)
{
    int factorizacionPrimerOperando=1;

    if(primerOperando<0)
    {
        printf("ERROR. El factoreo de un numero negativo no existe.");
    }
    else {

        for(int i = 1;i<=primerOperando;i++)
        {
            factorizacionPrimerOperando *= i;
        }
    }

    return factorizacionPrimerOperando;
}
int factorizarSegundoOperando(int segundoOperando)
{
    int factorizacionSegundoOperando=1;

    if(segundoOperando<0)
    {
        printf("ERROR. El factoreo de un numero negativo no existe.");
    }
    else
    {
        for(int i=1;i<=segundoOperando;i++)
        {
            factorizacionSegundoOperando *= i;
        }
    }
    return factorizacionSegundoOperando;
}

void calcularYMostrarOperaciones(int primerOperando, int segundoOperando, int respuestaMenu)
{
    int sumaResuelta;
    int restaResuelta;
    float divisionResuelta;
    int multiplicacionResuelta;
    int factorizacionPrimerOperandoResuelta;
    int factorizacionSegundoOperandoResuelta;

    sumaResuelta=sumarOperandos(primerOperando,segundoOperando);
    restaResuelta=restarOperandos(primerOperando,segundoOperando);
    divisionResuelta=dividirOperadores(primerOperando,segundoOperando);
    multiplicacionResuelta=multiplicarOperadores(primerOperando,segundoOperando);
    factorizacionPrimerOperandoResuelta=factorizarPrimerOperando(primerOperando);
    factorizacionSegundoOperandoResuelta=factorizarSegundoOperando(segundoOperando);

    if(respuestaMenu==4)
    {
    printf("El resultado de A+B es: %d \n",sumaResuelta);
    printf("El resultado de A-B es: %d \n",restaResuelta);
    printf("El resultado de A/B es: %f \n",divisionResuelta);
    printf("El resultado de A*B es: %d \n",multiplicacionResuelta);
    printf("El factorial de A es: %d y El factorial de B es: %d",factorizacionPrimerOperandoResuelta,factorizacionSegundoOperandoResuelta);
    }
}
*/
